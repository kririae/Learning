#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define INF 200001
#define N (200005*20*2)
using namespace std;
/*
今天已经跪了4道题了，不行，再怎么也要水过一道。 
主席树水题 
我收回上面那句，这是一道同值连接，可用分块+ST表（nlogn-sqrt(n)--空间nlogn）/主席树(nlogn-logn--空间nlogn(大常数))
r[i]记录为与a[i]值相同的数在右边第一次出现的位置
l[i]同理
每次查询两侧的区间就是了
e...MLE,真该分块。 

好吧，看了正解，应该离线+莫队+线段树维护转移

别人的题解：
双倍福利题……看到这道题YY了很久也没YY出正解……（看我YY出来了吧，YY，。。YYYY） 
首先从1到i的mex好求吧，那就求出来，再预处理一下每个数的下一个数的位置是多少
你发现你已经能回答l==1的询问了 = = 、,那么怎样才能由i推到i+1呢？
从i到i+1的变化就是取消了a[i]的影响，也就是说[i,next[i]-1]的mex=min(mex,a[i])考虑到mex是单调的，倒着更新就好了
于是你又可以回答以l==i+1结尾的询问了……于是离线做就好了……真是巧妙啊……
*/
const int L=0,R=1;
int n,m,t,cnt;//t为全局没有出现的最小自然数 include 0 
int a[INF];
int sor[INF];
//主席树 
int son[N][2],minn[N],root[INF],rvroot[INF];
void add(int &k,int fr,int to,int &fi,int &c){
	int f=++cnt;
	son[f][L]=son[k][L];son[f][R]=son[k][R];minn[f]=min(minn[k],c);
	k=f;
	if(fr==to) return;
	int mid=(fr+to)>>1;
	if(fi<=mid) add(son[k][L],fr,mid,fi,c);
	else add(son[k][R],mid+1,to,fi,c);
}
/*
int query(int pf,int pt,int fr,int to){
	if(fr==to) return fr;
	int side=-1;int mid=(fr+to)>>1;
	if(sum[son[pt][L]]-sum[son[pf][L]]<mid-fr+1)//不对，这不能定量，应该定性，定性就不支持区间减了
	//糟了，我又跪了。。。TTTTTTTATTTTTTT 
    /*我好像会做分块了 (！'v'！)*//*
}*/

int queryfr(int k,int c,int fr,int to){//>=c
    if(fr>=c){//全区间
        return minn[k];
    }
    int mid=(fr+to)>>1;
    if(c>mid) return queryfr(son[k][R],c,mid+1,to);
    else return min(queryfr(son[k][R],c,mid+1,to),queryfr(son[k][L],c,fr,mid));
}
int querybk(int k,int c,int fr,int to){//<=c
    if(to<=c){
        return minn[k];
    }
    int mid=(fr+to)>>1;
    if(c<=mid) return querybk(son[k][L],c,fr,mid);
    else return min(querybk(son[k][L],c,fr,mid),querybk(son[k][R],c,mid+1,to));
}
int biao[INF];
int r[INF];
int l[INF];
bool cmp(const int &a1,const int &a2){
	return a[a1]<a[a2];
}
int main(){
    minn[0]=INF;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sor[i]=i;
	}
	sort(sor+1,sor+n+1,cmp);
	bool fl=false;
	a[0]=-1;
	for(int i=1;i<=n;i++){//离散化+扫描 
		if(!fl){
			if(a[sor[i]]>a[sor[i-1]]+1)
				t=a[sor[i-1]]+1,fl=true;
		}else a[sor[i]]=t+2;//不打括号挂得早 
	}
	if(t==0) t=a[sor[n]]+1; 
    for(int i=1;i<=n;i++){
        l[i]=biao[a[i]];biao[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        r[l[i]]=i;
    }
    for(int i=1;i<=n;i++){
        if(r[i]==0) r[i]=n+1;
    }
	for(int i=1;i<=n;i++){
		root[i]=root[i-1];
		add(root[i],0,n+1,r[i],a[i]);
	}
    for(int i=n;i>=1;i--){
        rvroot[i]=rvroot[i+1];
        add(rvroot[i],0,n+1,l[i],a[i]);
    }
	for(int i=1;i<=m;i++){
		int f,t2;
		scanf("%d%d",&f,&t2);
        int ans=min(t,queryfr(root[f-1],t2+1,0,n+1));
        ans=min(ans,querybk(rvroot[t2+1],f-1,0,n+1));
		printf("%d\n",ans);
	}
	return 0;
}
