#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
const int mod = 1000000007;
long long f[maxn];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.in", "w", stdout);
	int t;
	f[0] = 1;
	int n = 1009;
	for (int i = 1; i < n; i += 2) 
		for (int j = i; j <= n; ++j) {
			f[j] = (f[j] + f[j - i]) % mod;
	}
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;
		cout << f[n] << endl;
	}
}
