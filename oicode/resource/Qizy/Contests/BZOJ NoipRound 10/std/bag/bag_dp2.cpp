#include<bits/stdc++.h>
using namespace std;
const int maxn=53,maxv=10011;
int n,m,v[maxn],V,V0,C;
void init(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i) scanf("%d",v+i); sort(v+1,v+n+1);
	sort(v+1,v+n+1); scanf("%d%d",&V0,&C); V=v[1];
}
long long f[33][33*maxv],g[maxv];
bitset<maxv*33>F[33];
void preset(){
//	f[i][j][k]代表现在是第i个，选了j个大物品，然后现在mod V是k的最小。
	if (V<V0){
		for (int j=0;j<=C;++j) for (int k=0;k<V;++k) f[j][k]=1e18;
		f[0][0]=0;
		for (int i=1;i<=n;++i){
			if (v[i]>=V0){
				int t=v[i]%V;
				for (int j=1;j<=C;++j) for (int k=0;k<V;++k)
					f[j][k]=min(f[j][k],f[j-1][(k+V-t)%V]+v[i]);
			}else{
				int len=V/__gcd(v[i],V);
				for (int j=0;j<=C;++j){
					int N=V/len;
					for (int d=0;d<N;++d){
						for (int T=1;T<=2;++T)
							for (int k=0,last=d,now;k<=len;++k,last=now){
								now=(last+v[i])%V;
	//							cout<<i<<' '<<v[i]<<' '<<last<<' '<<now<<endl;
								f[j][now]=min(f[j][now],f[j][last]+v[i]);
							}
					}
				}
			}
		}
		for (int i=0;i<V;++i) g[i]=1e18;
		for (int j=0;j<=C;++j) for (int k=0;k<V;++k) g[k]=min(g[k],f[j][k]);
	}else{
		for (int j=0;j<=C;++j) F[j].reset();
		F[0][0]=1;
		for (int i=1;i<=n;++i) for (int j=1;j<=C;++j){
			F[j]|=F[j-1]; F[j]|=F[j-1]<<v[i];
		}
	}
}
void work(){
	preset();
	if (V<V0){
		while (m--){
			long long x; scanf("%lld",&x);
			puts(g[x%V]<=x?"Yes":"No");
		}
	}else{
		while (m--){
			long long x; scanf("%lld",&x);
			if (x>C*10000){puts("No"); continue;}
			puts(F[C].test(x)?"Yes":"No");
		}
	}
}
int main(){
	freopen("bag.in","r",stdin);
	freopen("bag.out","w",stdout);
	init();
	work();
	return 0;
}

