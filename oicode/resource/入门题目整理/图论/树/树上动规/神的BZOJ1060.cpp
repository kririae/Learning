#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<ctime>
#include<queue>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
ll ans;
int n,root,cnt;
int f[500005],last[500005];
struct edge{int to,next,v;}e[1000005];
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
void insert(int u,int v,int w)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;e[cnt].v=w;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;e[cnt].v=w;
}
void dfs(int x,int fa)
{
	for(int i=last[x];i;i=e[i].next)
		if(e[i].to!=fa)
		{
			dfs(e[i].to,x);
			f[x]=max(f[x],f[e[i].to]+e[i].v);
		}
	for(int i=last[x];i;i=e[i].next)
		if(e[i].to!=fa)ans+=f[x]-f[e[i].to]-e[i].v;
}
int main()
{
	n=read();root=read();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read(),w=read();
		insert(u,v,w);
	}
	dfs(root,0);
	printf("%lld",ans);
	return 0;
}
