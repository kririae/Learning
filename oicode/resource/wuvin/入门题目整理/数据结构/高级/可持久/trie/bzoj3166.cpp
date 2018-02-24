/*
又是一道暴力枚举+优化的题
不过有一定思维难度（反正我没做起）
这道题告诉我们：哪个量不好算就枚举那个量
当然枚举的这个量的个数要十分有限
枚举答案这种2^31级别的方法还是算了吧 
*/ 
#include<cstdio>
#include<iostream>
#define N 50005
using namespace std;
//----------------------------trie----------
const int L=0,R=1,INF=0x7fff0000;
struct node{
	int s[2],size;
}x[N*33];
int cnt;
void build(int &k,int p,int x2){//现在是第p位 p=31 
	int t=++cnt;x[t].s[L]=x[k].s[L];x[t].s[R]=x[k].s[R];x[t].size=x[k].size+1;k=t;
	if(p==0) return;
	int si=(x2&(1<<(p-1)))>>(p-1);
	build(x[t].s[si],p-1,x2);
}
int ansss;
int get1max(int st,int en,int p,int x2){//找一个与x亦或最大的  (st,en]
	if(p==0) return 0;if(p==31) ansss=0;
	int si=((x2&(1<<(p-1)))>>(p-1))^1;
	if(x[x[en].s[si]].size-x[x[st].s[si]].size>0){
		ansss+=1<<(p-1);
		get1max(x[st].s[si],x[en].s[si],p-1,x2);
	}else{
		get1max(x[st].s[si^1],x[en].s[si^1],p-1,x2);
	}
	if(p==31) return ansss;
	return 0;
}
//-------------------------------------------
int n,m,root[N];
int a[N];
//由于是次大值，只有ST表+二分了
//ST
int st[20][N];
int log[N];
void pre(){
	for(int i=2;i<=n+2;i++) log[i]=log[i>>1]+1;
	for(int i=1;i<=n;i++)
		st[0][i]=a[i];
	for(int i=1;(1<<i)<=n;i++)
		for(int j=1;j+(1<<i)-1<=n;j++){
			st[i][j]=max(st[i-1][j],st[i-1][j+(1<<(i-1))]);
		}
}
int getmax(int l,int r){
	if(l>r) return -INF;
	int d=log[r-l+1];
	return max(st[d][l],st[d][r-(1<<d)+1]); 
}
int upper(int x,int st,int en){
	if(st>en) return en;
	int l=st,r=en+1;//[l,r)
	while(l+1<r){
		int mid=(l+r)>>1;
		int p=getmax(st,mid);
		if(p>x) r=mid;
		else l=mid;
	}
	return l;
}
int rupper(int x,int st,int en){
	if(st>en) return st;
	int l=st-1,r=en;//(l,r]
	while(l+1<r){
		int mid=(l+r)>>1;
		int p=getmax(mid,en);
		if(p>x) l=mid;
		else r=mid;
	}
	return r;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	pre();
	for(int i=1;i<=n;i++){
		root[i]=root[i-1];
		build(root[i],31,a[i]);
	}
	int anss=0;int bug=0;
	for(int i=1;i<=n;i++){
		int l1,r1,l2,r2;
		if(getmax(1,i-1)<a[i]){
			l1=l2=1;bug++;
		}else{
			l1=rupper(a[i],1,i);
			l2=rupper(a[i],1,l1-2);
		}
		if(getmax(i+1,n)<a[i]){
			r1=r2=n;bug++;
		}else{
			r1=upper(a[i],i,n);
			r2=upper(a[i],r1+2,n);
		}
		if(bug==2) {bug=0;continue;}
		anss=max(anss,get1max(root[l2-1],root[r2],31,a[i]));
		bug=0;
	}
	printf("%d\n",anss);
	return 0;
}
