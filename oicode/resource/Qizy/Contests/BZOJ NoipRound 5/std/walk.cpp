#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <vector>
#include <time.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> mp;
#define pb push_back
const int inf = 1<<30;
const int maxn = 1000005;
const int N = 1000000;

int ehead[maxn],ecnt;
int head[maxn],cnt;
int stk[maxn*2],top;
struct edge{
	int u,v,next;
}rec[maxn],edg[maxn*2];
void add(int u,int v) {
	edg[++ecnt]=(edge){u,v,ehead[u]};
	ehead[u]=ecnt;
	edg[++ecnt]=(edge){v,u,ehead[v]};
	ehead[v]=ecnt;
	stk[++top]=u;stk[++top]=v;
}
void _add(int u,int v,int w) {
	rec[++cnt]=(edge){u,v,head[w]};
	head[w]=cnt;
}
int n,ans[maxn],maxLen;
int vis[maxn],idx;
int dfs(int u) {
	int maxc=0;vis[u]=idx;
	for (int v,j=ehead[u];j;j=edg[j].next)
	if (vis[v=edg[j].v]!=idx) {
		int tmpc=dfs(v);
		maxLen=max(maxLen,maxc+tmpc+1);
		maxc=max(maxc,tmpc+1);
	}
	return maxc;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("walk.in","r",stdin);
		freopen("walk.out","w",stdout);
	#endif
	scanf("%d",&n);
	for (int u,v,w,i=1;i<n;i++)
		scanf("%d %d %d",&u,&v,&w),_add(u,v,w);
	for (int i=1;i<=N;i++) {
		for (int j=i;j<=N;j+=i)
		for (int k=head[j];k;k=rec[k].next)
			add(rec[k].u,rec[k].v);
		maxLen=0;++idx;
		for (int v,j=1;j<=top;j++)
			if (vis[v=stk[j]]!=idx) dfs(v);
		for (int j=1;j<=top;j++)
			ehead[stk[j]]=0;
		ecnt=0;top=0;ans[maxLen]=i;
	}
	for (int i=n;i>=1;i--)
		ans[i]=max(ans[i],ans[i+1]);
	for (int i=1;i<=n;i++)
		printf("%d\n",ans[i]);
	return 0;
}
