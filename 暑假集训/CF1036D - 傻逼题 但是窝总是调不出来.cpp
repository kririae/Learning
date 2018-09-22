#include <bits/stdc++.h>
#define ll long long0
using namespace std;

const int N = 3e5 + 5;
int n, m;
deque<int> a, b;
int main() {
	scanf("%d", &n);
	for (int i = 1, x; i <= n; ++i) scanf("%d", &x), a.push_back(x);
	scanf("%d", &m);
	for (int i = 1, x; i <= m; ++i) scanf("%d", &x), b.push_back(x);
	ll x = a.front(), y = b.front();
	a.pop_front();
	b.pop_front();
	int ans = 0;
	while (true) {
		if ((a.size() & b.size()) == 0) { 
			if (a.size() | b.size())
				return puts("-1"), 0;
			else break;
		}
		if (x < y) x += a.front(), a.pop_front();
		else if (x > y) y += b.front(), b.pop_front();
		if (x == y) {
			++ans;
			x = a.front();
			y = b.front();
			a.pop_front();
			b.pop_front();
		}
	}
	cout << ans << endl;
}