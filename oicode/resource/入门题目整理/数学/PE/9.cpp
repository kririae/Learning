#include<bits/stdc++.h>
#define LL long long
/*部分枚举O(n^2)
可以推式子O(n) 
还可以手算*/
using namespace std;
long long a[2000];
LL ans=0;
int main(){
	int n=1000;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			LL p=sqrt(i*i+j*j);
			if(p*p==i*i+j*j&&i+j+p==n){
				ans=i*j*p;
				printf("%I64d\n",ans);
				return 0;
			}
		}
	}
	printf("%I64d\n",ans);
	return 0;
}
