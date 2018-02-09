#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
#define next next_
inline void readi(int &x);
template<class T> inline bool ten(T &x,const T &y){return y<x?x=y,1:0;}
template<class T> inline bool rel(T &x,const T &y){return x<y?x=y,1:0;}
const int maxn=2000005,inf=(1<<30)-1;

int n,m,N;
int head[maxn],adj[maxn],next[maxn],tot;

int C[maxn],Clen,vis[maxn],ine[maxn],pre[maxn];
bool onc[maxn],Cfound;

vector<int> ans;

void addedge(int u,int v)
{tot++;adj[tot]=v;next[tot]=head[u];head[u]=tot;}

void init()
{
	scanf("%d%d",&n,&m);
	N=n*2;
	for(int i=1;i<=n;i++)
		addedge(i,i+n);
	for(int u,v,i=1;i<=m;i++)
		readi(u),readi(v),addedge(u+n,v);
}

void tdfs(const int &x)
{
	vis[x]=1;
	for(int i=head[x];i&&!Cfound;i=next[i])
		if(vis[adj[i]]==0)
		{
			pre[adj[i]]=x;
			ine[adj[i]]=i;
			tdfs(adj[i]);
		}
		else if(vis[adj[i]]==1)
		{
			Cfound=1;
			for(int p=x;p!=adj[i];p=pre[p])
				C[++Clen]=p,onc[ine[p]]=1;
			C[++Clen]=adj[i];
			onc[ine[adj[i]]=i]=1;
			reverse(C+1,C+Clen+1);
			return;
		}
	vis[x]=2;
}

int deg[maxn];
int q[maxn],qh,qt;

bool topo()
{
	for(int x=1;x<=N;x++)
		for(int i=head[x];i;i=next[i])
			if(!onc[i])
				deg[adj[i]]++;
	qh=qt=0;
	for(int x=1;x<=N;x++)
		if(deg[x]==0)q[++qt]=x;
	for(int u,v,i;qh<qt;)
	{
		u=q[++qh];
		for(i=head[u];i;i=next[i])
			if(!onc[i]&&--deg[v=adj[i]]==0)
				q[++qt]=v;
	}
	return qt==N;
}

int L[maxn],R[maxn],ban[maxn];

void work()
{
	for(int x=1;x<=N&&!Cfound;x++)
		if(!vis[x])
			tdfs(x);
	if(!Cfound)
	{
		for(int i=1;i<=n;i++)
			ans.push_back(i);
		return; 
	}
	if(!topo())
		return;
	
	for(int i=1;i<=Clen;i++)
		L[C[i]]=R[C[i]]=i;
	for(int u,i,j=N;j;j--)
	{
		u=q[j];
		if(!L[u])L[u]=inf;
		for(i=head[u];i;i=next[i])
			if(!onc[i])ten(L[u],L[adj[i]]);
	}
	for(int u,i,j=1;j<=N;j++)
	{
		u=q[j];
		if(!R[u])R[u]=-1;
		for(i=head[u];i;i=next[i])
			if(!onc[i])rel(R[adj[i]],R[u]);
	}
	
	int l=0,r=Clen+1;
	for(int i=1;i<=Clen;i++)
		if(L[C[i]]<i){r=i;break;}
	for(int i=Clen;i;i--)
		if(R[C[i]]>i){l=i;break;}
	for(int i=1;i<=l;i++)ban[ine[C[i]]]=1;
	for(int i=r+1;i<=Clen;i++)ban[ine[C[i]]]=1;
	
	memset(R,0,N+1<<2);
	for(int i=1;i<=Clen;i++)
		R[C[i]]=i;
	for(int u,i,j=N;j;j--)
	{
		u=q[j];
		for(i=head[u];i;i=next[i])
			if(!onc[i])rel(R[u],R[adj[i]]);
	}
	
	r=0;
	for(int i=1;i<=Clen;i++)
		if(R[C[i]]>r)
		{
			for(int j=max(i,r)+1;j<=R[C[i]];j++)
				ban[ine[C[j]]]=1;
			r=R[C[i]];
		}
	for(int i=1;i<=n;i++)
		if(onc[i]&&!ban[i])ans.push_back(i);
}

int main()
{
	freopen("reality.in","r",stdin);
	freopen("reality.out","w",stdout);
	init();
	work();
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
		printf("%d%c",ans[i]," \n"[i+1==ans.size()]);
	return 0;
}

inline void readi(int &x)
{char c;while(c=getchar(),c<'0'||c>'9');
x=c^'0';while(c=getchar(),c>='0'&&c<='9')x=x*10+(c^'0');}

