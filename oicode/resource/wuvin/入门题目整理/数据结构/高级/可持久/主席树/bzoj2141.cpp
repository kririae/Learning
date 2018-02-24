/*
本题实质，带修改区间kth
hzwer分块飞过。（貌似不知为何，此题分块很优越，有可能询问太集中）
分块一次修改sqrt(n)logn,我的方法一次lognlogINF（+大常数） 
算了一下，由于m太小，分块无压力过。
还是练一下bit+主席树。（有人说bit+替罪羊树(雾)）
我比较懒，不想离散化，那就暴力10^9的值域吧(貌似常数要x2)
等等题目表示ai,bi<=n 
等等，貌似只用主席书就可以维护逆序对个数了。
logn水过 
不对，上面方法是错的。
还是要bit+主席树
上面方法只能应对一次查询 
不对hi<1e9 


eeeWA了半天，N开大十倍就A了 
我们来仔细算一下空间。
数组大小2*10^4
每个节点有一个xds
e..发现线段树的高度不是严格logn的
比如一个1~15的线段树，最深五层。
应该按2n算log 
那么本题N要为
4588000 
那么树状数组的层数？
严格（logn +1） 
*/ 
#include<cstdio>
#include<iostream>
#define low(x) (x&(-x))
#define N   4588005
#define INF 1000000005
using namespace std;
const int L=0,R=1;
int n,m,cnt,root[20005],total;
int a[20005];
//--------hjt-------
int son[N][2],size[N];
inline int build(int &k,int fr_,int to_,int &x,int f2){//顺带返回比x大的个数
    int f=++cnt;son[f][L]=son[k][L];son[f][R]=son[k][R];
    size[f]=size[k]+f2;k=f;
    if(fr_==to_) return 0;
    int mid=(fr_+to_)>>1;
    if(mid>=x)  {return size[son[k][R]]+build(son[k][L],fr_,mid,x,f2);}
    else  return build(son[k][R],mid+1,to_,x,f2);
}
void pre(){
    total=0;
    for(int i=1;i<=n;i++){
        root[i]=root[i-1];
        total+=build(root[i],1,INF,a[i],1);
    }
}

int cxd(int jia1,int jia2,int jian,int fr_,int to_,int &f){
    if(fr_>f){
        return size[jia1]+size[jia2]-size[jian];
    }else if(to_<=f){
        return 0;
    }else{
        int mid=(fr_+to_)>>1;
        return cxd(son[jia1][L],son[jia2][L],son[jian][L],fr_,mid,f)+
        cxd(son[jia1][R],son[jia2][R],son[jian][R],mid+1,to_,f);
    }
}
int cxx(int jia1,int jia2,int jian,int fr_,int to_,int &f){
    if(fr_>=f){
        return 0;
    }else if(to_<f){
        return size[jia1]+size[jia2]-size[jian];
    }else{
        int mid=(fr_+to_)>>1;
        return cxx(son[jia1][L],son[jia2][L],son[jian][L],fr_,mid,f)+
        cxx(son[jia1][R],son[jia2][R],son[jian][R],mid+1,to_,f);
    }
}
//--------bit-----------
int bit[20005];
inline void change(int x,int y){//把a[x]变成y
    for(int i=x;i<=n;i+=low(i)){
        build(bit[i],1,INF,a[x],-1);
        build(bit[i],1,INF,y,1);
    }
    a[x]=y;
}
inline int querybigger(int x,int k){//查询区间1-x比k大的个数
    int ret=0;
    for(int i=x;i>=1;i-=low(i)){
        ret+=cxd(root[i],bit[i],root[i-low(i)],1,INF,k);
    }
    return ret;
}
inline int querysmaller(int x,int k){//查询区间1-x比k小的个数
    int ret=0;
    for(int i=x;i>=1;i-=low(i)){
        ret+=cxx(root[i],bit[i],root[i-low(i)],1,INF,k);
    }
    return ret;
} 
//------------------
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    pre();
    printf("%d\n",total);
    scanf("%d",&m);
    for(int i=1,l,r;i<=m;i++){
        scanf("%d%d",&l,&r); 
        int ans=querysmaller(r,a[l])-querysmaller(l,a[l])+querybigger(r,a[r])-querybigger(l,a[r]);
        total-=ans;int t=a[l];
        change(l,a[r]);
		change(r,t);
        ans=querysmaller(r,a[l])-querysmaller(l,a[l])+querybigger(r,a[r])-querybigger(l,a[r]);
        total+=ans; 
        printf("%d\n",total);
    }
    return  0;
}
