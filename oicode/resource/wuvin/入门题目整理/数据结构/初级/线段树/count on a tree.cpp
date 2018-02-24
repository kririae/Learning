#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define inf 0x7fffffff
#define ll long long
#define N 100005
#define M 2000005
using namespace std;
inline ll read()
{
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,tot,sz,cnt,ind,last;
int num[N],pos[N];
int v[N],tmp[N],hash[N],root[N];
int ls[M],rs[M],sum[M];
int deep[N],fa[N][17];
struct data{int to,next;}e[200005];int head[N];
void ins(int u,int v)
{e[++cnt].to=v;e[cnt].next=head[u];head[u]=cnt;}
void insert(int u,int v)
{ins(u,v);ins(v,u);}
int find(int x)
{
	int l=1,r=tot;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(hash[mid]<x)l=mid+1;
		else if(hash[mid]==x)return mid;
		else r=mid-1;
	}
}
void dfs(int x)
{
	ind++;num[ind]=x;pos[x]=ind;
	for(int i=1;i<=16;i++)
	    if((1<<i)<=deep[x])fa[x][i]=fa[fa[x][i-1]][i-1];
	    else break;
	for(int i=head[x];i;i=e[i].next)
		if(fa[x][0]!=e[i].to)
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
    for(int i=0;i<=16;i++)
        if((1<<i)&t)x=fa[x][i];
    for(int i=16;i>=0;i--)
        if(fa[x][i]!=fa[y][i])
            x=fa[x][i],y=fa[y][i];
    if(x==y)return x;
    return fa[x][0];
}
void update(int l,int r,int x,int &y,int num)
{
    y=++sz;
	sum[y]=sum[x]+1;
	if(l==r)return;
	ls[y]=ls[x];rs[y]=rs[x];
	int mid=(l+r)>>1;
	if(num<=mid)
	    update(l,mid,ls[x],ls[y],num);
	else update(mid+1,r,rs[x],rs[y],num);
}
int que(int x,int y,int rk)
{
	int a=x,b=y,c=lca(x,y),d=fa[c][0];
	a=root[pos[a]],b=root[pos[b]],c=root[pos[c]],d=root[pos[d]];
	int l=1,r=tot;
	while(l<r)
	{
		int mid=(l+r)>>1;
		int tmp=sum[ls[a]]+sum[ls[b]]-sum[ls[c]]-sum[ls[d]];
		if(tmp>=rk)r=mid,a=ls[a],b=ls[b],c=ls[c],d=ls[d];
		else rk-=tmp,l=mid+1,a=rs[a],b=rs[b],c=rs[c],d=rs[d];
	}
	return hash[l];
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	    v[i]=read(),tmp[i]=v[i];
	sort(tmp+1,tmp+n+1);
	hash[++tot]=tmp[1];
	for(int i=2;i<=n;i++)
	    if(tmp[i]!=tmp[i-1])hash[++tot]=tmp[i];
	for(int i=1;i<=n;i++)v[i]=find(v[i]);
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		insert(u,v);
	}
	dfs(1);
	for(int i=1;i<=n;i++)
	{
		int t=num[i];
		update(1,tot,root[pos[fa[t][0]]],root[i],v[t]);
	}
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read(),rk=read();
		//x^=last;
		last=que(x,y,rk);
		printf("%d",last);
		if(i!=m)printf("\n");
	}
	return 0;
}
