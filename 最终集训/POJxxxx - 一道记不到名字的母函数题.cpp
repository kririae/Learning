#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;

inline ll fpow(ll a, ll p, ll mod) {
	ll ans = 1;
	for (; p; p >>= 1) {
		if(p & 1) (ans *= a) %= mod;
		(a *= a) %= mod;
	} return ans;
} int t, n;
int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		printf("%lld\n", (fpow(4, n - 1, 10007) + fpow(2, n - 1, 10007)) % 10007);
	}
}