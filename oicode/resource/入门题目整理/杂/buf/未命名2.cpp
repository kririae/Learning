#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
#define mod 1000000007ll
#define inv 233333335ll
vector<int> p;
int n;
ll calc(ll x, ll m)
{
	ll xx = (x * x % mod) * x % mod;
	xx = ((6 * x * x + 15 * x + 10) % mod * xx + mod - x) % mod;
	xx =  xx * inv % mod;
	m = m * m % mod;
	m = m * m % mod;
	return xx * m % mod;
}
ll work(int x, int s)
{
	ll ret = 0, c = 1, m;
	int cnt = 0;
	for (int i = 0; i < s; i++)
		if (x & (1 << i)) {
			cnt++;
			c *= p[i];
		}
	m = n / c;
	//c^4*(....)
	ret = calc(m, c);
	//cout << m << " " << c << " " << ret << endl;
	if (cnt % 2 == 0) return ret;
	return -ret;
}

int main()
{

	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int m = n;
		p.clear();
		for (int i = 2; i * i <= m; i++) {
			if (m % i == 0) {
				p.push_back(i);
				while (m % i == 0) m /= i;
			}
		}
		if (m > 1) p.push_back(m);
		ll ans = calc(n, 1);
		for (int i = 1; i < (1 << p.size()); i++) {
			ans += work(i, p.size());
			while (ans < 0) ans += mod;
			while (ans >= mod) ans -= mod;
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
