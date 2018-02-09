#include <bits/stdc++.h>
using namespace std;
int n, m, father[100005];
struct edge {
	int x{0}, y{0}, v{0};
	bool operator<(const edge(&a)) const
	{
		return this->v < a.v;
	}
} p[100005];
inline int find(int val)
{
	if (father[val] != val)
		father[val] = find(father[val]);

	return father[val];
}
inline void unionn(int val1, int val2)
{
	father[find(val1)] = find(val2);
}
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;

	for (int i = 0; i <= n; ++i) {
		father[i] = i;
	}

	for (int i = 0; i < m; ++i) {
		cin >> p[i].x >> p[i].y >> p[i].v;
	}

	sort(p, p + m);
	int summ = 0;

	for (int i = 0; i < m; ++i) {
		if (find(p[i].x) != find(p[i].y)) {
			unionn(p[i].x, p[i].y);
			summ = p[i].v;
		}
	}

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (find(i) != find(j)) {
				cout << -1 << endl;
				return 0;
			}
		}
	}

	cout << summ << endl;
	return 0;
}
