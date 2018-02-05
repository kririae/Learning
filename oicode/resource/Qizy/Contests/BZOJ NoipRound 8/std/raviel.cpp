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
const int N=10005,Mod=123456789;

int n,Ans[N],f[N],s[N];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("raviel.in","r",stdin);
	freopen("raviel.out","w",stdout);
#endif
	cin>>n;
	f[0]=1;
	for(int i=2;i<=n;i++)
		f[i]=(f[i-1]+f[i-2])%Mod,s[i]=(s[i-1]+f[i])%Mod;
	for(int i=1;i<n;i++)
		Ans[i]=(s[n-i-1]+1ll)*f[i]%Mod;
	for(int i=1;i<n;i++)
		for(int j=1;j<n;j++)
			Ans[i+j]=(Ans[i+j]+(LL)s[n-max(i,j)]*f[i-1]%Mod*f[j])%Mod;
	for(int i=1;i<=2*n;i++)
		cout<<Ans[i]<<" ";
	return 0;
}

