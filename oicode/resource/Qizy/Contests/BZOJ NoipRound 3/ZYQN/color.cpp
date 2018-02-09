#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 100+9;
const int MOD = 998244353;

int n,m,p,q,POW[N],REV[N],g[N][N];
struct Matrix{
	int a[N][N];
	inline Matrix() {}
	inline Matrix(const Matrix &B) {
		memcpy(this,&B,sizeof(*this));
	} 
	inline Matrix(int x) {
		memset(a,0,sizeof(a));
		for (int i=1;i<=n;i++) {
			a[i][i] = x;
		}
	}
	inline Matrix operator * (const Matrix &B) {
		Matrix ret(0);
		for (int j=1;j<=n;j++) {
			for (int i=1;i<=n;i++) {
				for (int k=1;k<=n;k++) {
					ret.a[i][j] += (LL)a[k][j] * B.a[i][k] % MOD;
					ret.a[i][j] %= MOD;
				}
			}
		}
		return ret;
	}
	inline Matrix operator ^ (int t) {
		Matrix ret(1),tmp(*this);
		while (t) {
			if (t & 1) ret = ret * tmp;
			tmp = tmp * tmp; t >>= 1;
		}
		return ret;
	}
}trans,ans; 

inline int read(){
	char c=getchar(); int ret=0,f=1;
	while (c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while (c<='9'&&c>='0') {ret=ret*10+c-'0';c=getchar();}
	return ret*f;
}

inline int pow(int w, int t) {
	int ret = 1;
	while (t) {
		if (t&1) ret = (LL)ret * w % MOD;
		w = (LL)w * w % MOD; t >>= 1;
	}
	return ret;
}

inline int alph(int a, int b, int x) {
	if (x > a || x > b || p-a-b+x < 0) return 0;
	int ret = (LL)POW[a] * POW[p-a] % MOD;
	ret = (LL)ret * REV[x] % MOD;
	ret = (LL)ret * REV[a-x] % MOD;
	ret = (LL)ret * REV[b-x] % MOD;
	ret = (LL)ret * REV[p-a-b+x] % MOD;
	return ret;
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout); 
	n = read(); m = read();
	p = read(); q = read();
	POW[0] = REV[0] = 1;
	for (int i=1;i<=max(n,p);i++) {
		POW[i] = (LL)POW[i-1] * i % MOD;
	}
	REV[max(n,p)] = pow(POW[max(n,p)],MOD-2);
	for (int i=max(n,p)-1;i;i--) {
		REV[i] = (LL)REV[i+1] * (i+1) % MOD;
	}
	g[1][1] = p;
	for (int i=2;i<=n;i++) {
		for (int j=1;j<=p;j++) {
			g[i][j] = (LL)g[i-1][j-1] * (p - j + 1) % MOD + (LL)g[i-1][j] * j % MOD;
			g[i][j] %= MOD;
		}
	}
	for (int a=1;a<=n;a++) {
		for (int b=1;b<=n;b++) {
			if (a > p || b > p) continue;
			for (int x=0;x<=a+b-q;x++) {
				trans.a[b][a] += alph(a,b,x);
				trans.a[b][a] %= MOD;
			}
			trans.a[b][a] = ((LL)g[n][b]*REV[p]%MOD) * trans.a[b][a] % MOD;
			trans.a[b][a] = ((LL)POW[b]*POW[p-b]%MOD) * trans.a[b][a] % MOD;
		}
	}
	for (int i=1;i<=min(n,p);i++) {
		ans.a[i][1] = g[n][i];
	}
	trans = trans ^ (m-1);
	ans = ans * trans;
	int vout = 0;
	for (int i=1;i<=n;i++) {
		vout += ans.a[i][1];
		vout %= MOD;
	}
	printf("%d\n",vout);
	return 0;
}
