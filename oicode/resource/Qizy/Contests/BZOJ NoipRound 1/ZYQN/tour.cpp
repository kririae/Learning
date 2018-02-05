#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 1500+9;

LL vout; 
int n,in[N];
bitset<N> edg[N]; 

inline int read(){
	char c=getchar(); int ret=0,f=1;
	while (c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while (c<='9'&&c>='0') {ret=ret*10+c-'0';c=getchar();}
	return ret*f;
}

int main(){
	freopen("tour.in","r",stdin);
	freopen("tour.out","w",stdout);
	n = read(); char pat[N];
	for (int j=1;j<=n;j++) {
		scanf("%s",pat+1);
		for (int i=1;i<=n;i++) 
			edg[j][i] = pat[i] - '0',
			in[i] += pat[i] - '0';
	}
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) if (edg[i][j]) {
		vout += (LL)(in[i] - 1) * (in[j] - 1);
		vout -= (edg[i] & edg[j]).count();
	}
	printf("%lld\n",vout);
	return 0;
}

