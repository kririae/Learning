#include<bits/stdc++.h>
#define LL long long
/*高精+快速幂+（fft）
看了python
sum(map(int,str(2**1000)))
TAT*/
using namespace std;
int a[1005];
int ans=0;
int main(){
	int n=1000;a[1000]=1;
	for(int i=1;i<=n;i++){
		for(int j=1000;j>=1;j--){
			a[j]=a[j+1]/10+a[j]*2;
			a[j+1]%=10;
		}
	}
	for(int i=1;i<=1000;i++) ans+=a[i];
	printf("%d",ans);
	return 0;
}
