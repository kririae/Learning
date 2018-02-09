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
const int N=17,M=1<<17,Mod=1e9+7;

int n,m,g[N][N],f[M],Num[M],p2[N*N],a[M],b[M];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("obelisk.in","r",stdin);
	freopen("obelisk.out","w",stdout);
#endif
	cin>>n>>m;
	for(int i=1,u,v;i<=m;i++)
		cin>>u>>v,g[u-1][v-1]=1;
	f[0]=1;Num[0]=-1;
	for(int i=1;i<(1<<n);i++)
		Num[i]=Num[i>>1]*(i&1?-1:1);
	p2[0]=1;
	for(int i=1;i<=n*n;i++)
		p2[i]=p2[i-1]*2%Mod;
	for(int i=0;i<(1<<n)-1;i++)
	{
		for(int j=0;j<n;j++)
			b[1<<j]=0;
		for(int j=0;j<n;j++)
			if(i&(1<<j))
				for(int k=0;k<n;k++)
					b[1<<k]+=g[j][k];
		int t=(1<<n)-1-i;
		a[0]=0;
		for(int s=(t-1)&t;;s=(s-1)&t)
		{
			int Now=t^s,las=Now&-Now;
			a[Now]=a[Now^las]+b[las];
			f[Now^i]=(f[Now^i]+Num[Now]*p2[a[Now]]*(LL)f[i])%Mod;
		//	cout<<t<<" "<<s<<" "<<i<<" "<<a[Now]<<" "<<(Now^i)<<" "<<Now<<" "<<las<<" "<<b[las]<<endl;
			if(!s)
				break;
		}
	//	cout<<i<<" "<<f[i]<<endl;
	}
	cout<<(f[(1<<n)-1]+Mod)%Mod;
	return 0;
}

