#include<algorithm>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include  <stdio.h>
#include   <math.h>
#include   <time.h>
#include   <vector>
#include   <bitset>
#include    <queue>
#include      <set>
#include      <map>
using namespace std;

const int N=100005,M=5000005,Mod=123456789;

int lc[M],rc[M],s[M],rt[N],f[N],g[N],Max[N],Ans1,Ans2,tot,n,type;

void Add(int& x,int l,int r,int p,int k)
{
	if(!x)
		x=++tot,lc[x]=rc[x]=s[x]=0;
	int Mid=l+r>>1;
	s[x]=(s[x]+k)%Mod;
	if(l==r)
		return;
	if(p<=Mid)
		Add(lc[x],l,Mid,p,k);
	else
		Add(rc[x],Mid+1,r,p,k);
}

int Ask(int x,int l,int r,int p)
{
	if(r<=p)
		return s[x];
	int Mid=l+r>>1;
	if(p<=Mid)
		return Ask(lc[x],l,Mid,p);
	return (s[lc[x]]+Ask(rc[x],Mid+1,r,p))%Mod;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("hamon.in","r",stdin);
	freopen("hamon.out","w",stdout);
#endif
	cin>>n>>type;
	for(int i=1;i<=n;i++)
	{
		int a;scanf("%d",&a);
		for(int j=a-1;j;j-=j&-j)
			f[i]=max(f[i],Max[j]);
		if(f[i]==0)
			g[i]=1;
		else
			g[i]=Ask(rt[f[i]],0,N,a-1);
		f[i]++;
		if(f[i]>Ans1)
			Ans1=f[i],Ans2=0;
		if(f[i]==Ans1)
			Ans2=(Ans2+g[i])%Mod;
		Add(rt[f[i]],0,N,a,g[i]);
		for(int j=a;j<N;j+=j&-j)
			Max[j]=max(Max[j],f[i]);
	}
	cout<<Ans1<<endl;
	if(type)
		cout<<Ans2<<endl;
	return 0;
}
