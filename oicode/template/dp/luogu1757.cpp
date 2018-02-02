#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int f[maxn];
int ai, bi, ci, t = 0;
vector<pair<int, int> > bag[105];
int main() {
	auto maxx = [](int a, int b) {return a > b ? a : b; };
	cin.tie(0);
	ios::sync_with_stdio(false);
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < n; ++i) {
		cin >> ai >> bi >> ci;
		t = maxx(t, ci);
		bag[ci].push_back(make_pair(ai, bi));
	}
	for (int j = 1; j <= t; ++j) {
		for (int i = m; i >= 0; --i) {
			for (int k = 0; k < bag[j].size(); ++k) {
				f[i] = maxx(f[i - bag[j][k].first] + bag[j][k].second, f[i]);
			}
		}
	}
	cout << f[m] << endl;
}
