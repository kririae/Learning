#include<bits/stdc++.h>
using namespace std;
const int maxn=2011;
int n,a[maxn];
void init(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",a+i);
}
long long f[maxn][maxn];// f[i][j]代表选i，有j段的最大值
void work(){
	for (int i=1;i<=n;++i) for (int j=1;j<=n;++j) f[i][j]=-1e12; f[0][1]=0;
	for (int i=1;i<=n;++i){
		for (int k=0;k<i;++k) if (a[k]<a[i]) f[i][1]=max(f[i][1],f[k][1]+a[i]);
		for (int j=2;j<=i;++j){
			if (j&1){
				for (int k=0;k<i;++k) if (a[k]<a[i]) f[i][j]=max(f[i][j],max(f[k][j-1],f[k][j])+a[i]);
			}else{
				for (int k=0;k<i;++k) if (a[k]>a[i]) f[i][j]=max(f[i][j],max(f[k][j-1],f[k][j])+a[i]);
			}
		}
	}
	double ans=0; for (int i=1;i<=n;++i) for (int j=1;j<=i;++j) ans=max(ans,f[i][j]*1.0/j);
	printf("%.3f\n",ans);
}
int main(){
	freopen("interval.in","r",stdin);
	freopen("interval.out","w",stdout);
	init();
	work();
	return 0;
}
