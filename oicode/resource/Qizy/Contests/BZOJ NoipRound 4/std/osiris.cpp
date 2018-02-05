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

void solve()
{
	int a,b,c,x,y,z;cin>>a>>b>>c>>x>>y>>z;
	int need=max(x-a,0)+max(y-b,0)+max(z-c,0),have=max(a-x,0)/2+max(b-y,0)/2+max(c-z,0)/2;
	if(need<=have)
		puts("YES");
	else
		puts("NO");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("osiris.in","r",stdin);
	freopen("osiris.out","w",stdout);
#endif
	int t;cin>>t;
	while(t--)
		solve(); 
	return 0;
}

