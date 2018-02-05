#include<bits/stdc++.h>
using namespace std;
const int maxn=53,maxv=10011;
int n,m,v[maxn],V,V0,C;
void init(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i) scanf("%d",v+i); sort(v+1,v+n+1);
	sort(v+1,v+n+1); scanf("%d%d",&V0,&C);
}
bool f[33][maxv];
void work(){
	// f[i][j][k]代表现在在第i个已经用了j个超限物品，能否拼成k
	memset(f,0,sizeof(f)); f[0][0]=1;
	for (int i=1;i<=n;++i){
		if (v[i]<V0){
			for (int j=0;j<=C;++j) for (int k=v[i];k<=10000;++k) f[j][k]|=f[j][k-v[i]];
		}else{
			for (int j=1;j<=C;++j) for (int k=v[i];k<=10000;++k) f[j][k]|=f[j-1][k-v[i]];
		}
	}
	for (int j=1;j<=C;++j) for (int k=0;k<=10000;++k) f[j][k]|=f[j-1][k];
	while (m--){
		int x; scanf("%d",&x);
		puts(f[C][x]?"Yes":"No");
	}
}
int main(){
	freopen("bag.in","r",stdin);
	freopen("bag.out","w",stdout);
	init();
	work();
	return 0;
}
