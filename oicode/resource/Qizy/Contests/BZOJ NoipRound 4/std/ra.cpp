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

typedef long long LL;
const int N=10000000,Mod=1e9+7;

LL n;
int p[N/10+5],m,Num[N+5],f[N+5],F[N],Ans;
bool P[N+5];

void sieve(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(!P[i])
			p[++m]=i,Num[i]=1;
		for(int j=1;j<=m&&i*p[j]<=n;j++)
		{
			int k=i*p[j];P[k]=1;
			if(i%p[j]==0)
			{
				Num[k]=Num[i];break;
			}
			Num[k]=Num[i]+1;
		}
	}
	for(int i=1;i<=n;i++)
		f[i]=(f[i-1]+(1<<Num[i]))%Mod;
}

int solve(LL x)
{
	if(x<=N)
		return f[x];
	if(F[n/x]!=-1)
		return F[n/x];
	F[n/x]=0;
	for(LL i=1;i<=x;)
	{
		LL j=x/(x/i);
		F[n/x]=(F[n/x]+x/i*(j-i+1ll))%Mod;i=j+1;
	}
	for(LL i=2;i*i<=x;i++)
		F[n/x]=(F[n/x]-solve(x/(i*i))+Mod)%Mod;
	return F[n/x];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("ra.in","r",stdin);
	freopen("ra.out","w",stdout);
#endif
	sieve(N);memset(F,-1,sizeof F);
	cin>>n;
	for(LL i=1;i<=n;)
	{
		LL j=n/(n/i);
		Ans=(Ans+solve(n/i)*(j-i+1ll))%Mod;i=j+1;
	}
	cout<<(((n%Mod)*(n%Mod)-Ans)%Mod+Mod)%Mod;
	return 0;
}

