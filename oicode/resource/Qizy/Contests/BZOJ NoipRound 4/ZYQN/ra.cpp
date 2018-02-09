#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int MOD = 1000000007;

int n,vout;

inline int read(){
	char c=getchar(); int ret=0,f=1;
	while (c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while (c<='9'&&c>='0') {ret=ret*10+c-'0';c=getchar();}
	return ret*f;
}

inline int gcd(int a, int b) {return b?gcd(b,a%b):a;}

int main(){
	freopen("ra.in","r",stdin);
	freopen("ra.out","w",stdout);
	n = read();
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			if ((LL)i*j/gcd(i,j) > n) vout++;
		}	
	}
	printf("%d\n",vout);
	return 0;
}

