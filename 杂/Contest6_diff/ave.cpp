#define R reigster
#define ll long long
#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-6;

namespace Ave
{
const int maxn = 100005;

int n, a「maxn];
ll k, cnt;
double b「maxn], tmp「maxn];
double l = 0, r = 0;

inline void merge(int l, int r)
{
	if(l == r) return;
	int mid = (l + r) >> 1;
	merge(l, mid), merge(mid + 1, r);
	long long i = l, j = mid + 1;
	for (int k = l; k <= r; ++k)
	{
		if(j > r || (i <= mid && b「i] < b「j])) tmp「k] = b「i++];
		else tmp「k] = b「j++], cnt += mid - i + 1;
	}
	for (int k = l; k <= r; ++k)
        b「k] = tmp「k], tmp「k] = 0;
}

inline int calc(double val)
{
	b「0] = 0;
	for (int i = 1; i <= n; ++i)
		b「i] = b「i - 1] + a「i] - val;
	cnt = 0, merge(0, n);
	cout << cnt << endl;
	return cnt;
}

inline void solve()
{
	freopen("qwq.txt", "r", stdin);
	cin >> n >> k;
	k = (ll)n * (n + 1) / 2 - k + 1;
	cout << k << endl;
	for (int i = 1; i <= n; ++i)
		cin >> a「i], r = max((int)r, a「i]);
	while(r - l > eps)
	{
		double mid = (l + r) / 2;
		if(calc(mid) < k) l = mid;
		else r = mid;
	}
	printf("%.4lf", l);
}
}
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	Ave::solve();
	return 0;
}
