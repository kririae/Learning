/*大神的代码 注意LCA*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<set>
#define inf 1000000000
#define ll long long
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int bin[20];
int n,cnt;
int fa[300005][20];
int a[300005],f[300005],last[300005],deep[300005];
struct edge{int to,next;}e[600005];
void insert(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}
void dfs(int x)
{
	for(int i=1;i<=18;i++)
		if(deep[x]>=bin[i])
			fa[x][i]=fa[fa[x][i-1]][i-1];
		else break;
	for(int i=last[x];i;i=e[i].next)
		if(e[i].to!=fa[x][0])
		{
			deep[e[i].to]=deep[x]+1;
			fa[e[i].to][0]=x;
			dfs(e[i].to);
		}
}
int lca(int x,int y)
{
	if(deep[x]<deep[y])swap(x,y);
	int t=deep[x]-deep[y];
	for(int i=0;i<=18;i++)
		if(bin[i]&t)x=fa[x][i];
	for(int i=18;i>=0;i--)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	if(x==y)return x;
	return fa[x][0];
}
void dp(int x)
{
	for(int i=last[x];i;i=e[i].next)
		if(e[i].to!=fa[x][0])
		{
			dp(e[i].to);
			f[x]+=f[e[i].to];
		}
}
void solve()
{
	dfs(a[1]);
    for(int i=1;i<n;i++)
	{
		int t=lca(a[i],a[i+1]);
		f[a[i]]++;f[a[i+1]]++;
		f[t]--;f[fa[t][0]]--;
	}
    dp(a[1]);
	for(int i=2;i<=n;i++)f[a[i]]--;
	for(int i=1;i<=n;i++)printf("%d\n",f[i]);
}
int main()
{
	bin[0]=1;for(int i=1;i<20;i++)bin[i]=bin[i-1]<<1;
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		insert(u,v);
	}
	solve();
	return 0;
}
