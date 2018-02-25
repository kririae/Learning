#include<cstdio>
#include<iostream>
#define VAL 1005
#define N 1000005
#define ALL 10000505
using namespace std;
/*
果断主席树组+线段树（lazy管理区间）
有点难写，而且这个有bug
貌似应该主席树+树状数组
修改查询 mlog^2nlogv
建立 nlogn


hh,才发现正解是：
分块套Treap
建立n
修改m*n^0.5

*/
//char tree
const int L=0,R=1;
int root[N],a[N];
int son[ALL][2],sum[ALL];//,fr[ALL],to[ALL];
int n,m,cnt,seg_cnt,sroot;//++cnt
//-------华丽分割线------- 
void add(int &k,int fr,int to,int x){//可持久化修改 
	int f=++cnt;
	son[f][L]=son[k][L];son[f][R]=son[k][R];sum[f]=sum[k]+1;
    k=f;
	if(fr==to) return;
	int mid=(fr+to)>>1;
	if(x<=mid) add(son[f][L],fr,mid,x);
	else add(son[f][R],mid+1,to,x);
}
inline void build(){
	for(int i=1;i<=n;i++){
		root[i]=root[i-1];
		add(root[i],1,VAL,a[i]);
	}
}
int bigger(int kfr,int kto,int c,int fr,int to){//返回区间【kfr,kto】大于等于c的个数 fr,to 确定区间及结束  注意小于0的情况
    if(fr==to){
        return sum[kto]-sum[kfr];
    }else{
        int mid=(fr+to)>>1;
        if(c<=mid){
            return sum[son[kto][R]]-sum[son[kfr][R]]+bigger(son[kfr][L],son[kto][L],c,fr,mid);
        }else return bigger(son[kfr][R],son[kto][R],c,mid+1,to);
    }
}
//--------暴力分割线----- 
//segment tree
int segson[2*N][2],segfr[2*N],segto[2*N],segadd[2*N];
void _build(int &k,int fr,int to){
    k=++seg_cnt;segfr[k]=fr;segto[k]=to;
    if(fr==to) return;
    _build(segson[k][L],fr,(fr+to)>>1);
    _build(segson[k][R],((fr+to)>>1)+1,to);
}
void adds(int k,int fr,int to,int c){
    if(fr==segfr[k]&&to==segto[k]){
        segadd[k]+=c;
    }else{
        int mid=(segfr[k]+segto[k])>>1;
        if(fr<=mid) adds(segson[k][L],fr,min(to,mid),c);
        if(to>mid) adds(segson[k][R],max(fr,mid+1),to,c);
    }
}
int query(int k,int fr,int to,int c){//>=c
    if(fr==segfr[k]&&to==segto[k]){
        if(c-segadd[k]<=1) return to-fr+1;
        if(c-segadd[k]>VAL) return 0;
        return bigger(root[fr],root[to],c-segadd[k],1,VAL);
    }else{
        int mid=(segfr[k]+segto[k])>>1;
        if(segadd[k]!=0){
            segadd[son[k][L]]+=segadd[k];segadd[son[k][R]]+=segadd[k];
            segadd[k]=0;
        }
        int ret=0;
        if(fr<=mid) ret+=query(son[k][L],fr,min(mid,to),c);
        if(to>mid) ret+=query(son[k][R],max(mid+1,fr),to,c);
        return ret;
    }
}
//-----------完美的结尾线---- 
int main(){
	scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    build();_build(sroot,1,n);
    for(int i=1;i<=m;i++){
        char c=getchar();while(c!='A'&&c!='M') c=getchar();
        int f,t,cc;scanf("%d%d%d",&f,&t,&cc);
        if(c=='A'){
            printf("%d\n",query(sroot,f,t,cc));
        }else{
            adds(sroot,f,t,cc);
        }
    }
	return 0;
} 
