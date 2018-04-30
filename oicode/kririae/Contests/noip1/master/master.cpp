#include <bits/stdc++.h>

using namespace std;

const int maxn = 305;
int n, k, ans;
char s[maxn], t[maxn];
int main()
{
	freopen("master1.in", "r", stdin);
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> k;
	cin >> s >> t;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			for (int x = i, y = j, m = 0; x < n && y < n; ++x, ++y)
			{
				if(s[x] != t[y])
				{ 
					++m; 
					if(m > k) break; 
				}
				ans = max(ans, x - i + 1);
			}

	cout << ans << endl;
}
