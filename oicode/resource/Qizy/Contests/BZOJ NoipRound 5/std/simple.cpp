#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <queue>
using namespace std;

typedef long long LL;
typedef pair<int,int> mp;
#define pb push_back
const int inf = 1<<30;
const int maxn = 10005;

LL n,m,y,ans;int T;
LL GCD(LL n,LL m) {return m?GCD(m,n%m):n;}
LL updiv(LL n,LL m) {return n%m?n/m+1:n/m;}
LL dndiv(LL n,LL m) {return n%m?n/m:n/m-1;}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("simple.in","r",stdin);
		freopen("simple.out","w",stdout);
	#endif
	for (scanf("%d",&T);T--;) {
		scanf("%lld %lld %lld",&n,&m,&y);
		LL ans=y,t=GCD(n,m);
		n/=t;m/=t;y/=t;ans-=y;
		if (n>m) swap(n,m);
		for (int j=0;j<n;j++) {
			LL mink=max(1ll,updiv(j*m-y,n));
			LL maxk=dndiv(j*m,n);
			if (mink<=maxk) ans+=maxk-mink+1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
