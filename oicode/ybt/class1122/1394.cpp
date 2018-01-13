// ybt1394
#include <bits/stdc++.h>
using namespace std;
struct edge {
	int x, y, value;
	bool operator < (const edge (&a)) const
	{
		return this->value < a.value;
	}
};
int father[1000005];
edge p[1000005];
inline int find(int v)
{
	if(father[v] != v) father[v] = find(father[v]);

	return father[b];
}
inline void unionn(int a, int b)
{
	int r1 = find(a), r2 = find(b);
	father[r1] = r2;
}
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int m, n;
	cin >> m >> n;

	for(int i = 0; i <= m; ++i) {
		father[i] = i;
	}

	int x1, x2, y1, y2;

	for(int i = 0; i < m * n; ++i) {

	}

	/*
	1 1 1
	1 1 1
	1 1 1
	*/
	// 横向 6个 m * (n - 1);
	// 纵向 6个 n * (m - 1);
}