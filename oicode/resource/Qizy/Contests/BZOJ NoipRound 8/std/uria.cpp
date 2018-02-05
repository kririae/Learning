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
const int N=10000005;

LL n,Ans;
int m,f[N],p[N],phi[N];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("uria.in","r",stdin);
	freopen("uria.out","w",stdout);
#endif
	cin>>n;
	int lim=int(sqrt(n)); 
	for(int i=2;i<=lim;i++)
	{
		if(!f[i])
			p[++m]=i,phi[i]=i-1;
		for(int j=1;j<=m&&i*p[j]<=lim;j++)
		{
			f[i*p[j]]=1;
			if(i%p[j]==0)
			{
				phi[i*p[j]]=phi[i]*p[j];break;
			}
			phi[i*p[j]]=phi[i]*(p[j]-1);
		}
		Ans+=n/i/i*phi[i];
	}
	cout<<Ans;
	return 0;
}
