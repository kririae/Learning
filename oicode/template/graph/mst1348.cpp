#include <bits/stdc++.h>
using namespace std;
struct edge {
	int sp, v, ep;
	bool operator<(const edge(&a)) const {
		return this->v < a.v;
	}
};
edge p[105];
struct point {
	int x, y;
	bool operator<(const point(&a)) const {
		if (this->x < a.x)
			return true;

		if (this->x == a.x)
			return this->y < a.y;

		return false;
	}
};
std::set<point> result;
int father[105];
inline int find(int v) {
	if (father[v] != v)
		father[v] = find(father[v]);

	return father[v];
}
inline void unionn(int a, int b) {
	int r1 = find(a), r2 = find(b);
	father[r1] = r2;
}
int main() {
	int n, e;
	cin >> n >> e;

	for (int i = 1; i <= n; ++i) {
		father[i] = i;
	}

	for (register int i, j, wij, k = 0; k < e; ++k) {
		cin >> i >> j >> wij;
		edge curr;
		curr.sp = i, curr.ep = j, curr.v = wij;
		p[k] = curr;
	}

	sort(p, p + e);

	for (int i = 0; i < e; ++i) {
		if (find(p[i].sp) != find(p[i].ep)) {
			unionn(p[i].sp, p[i].ep);
			point curr;
			curr.x = p[i].sp, curr.y = p[i].ep;
			result.insert(curr);
		}
	}

	for (set<point>::iterator it = result.begin(); it != result.end(); ++it) {
		int a = min(it->x, it->y);
		int b = max(it->x, it->y);
		cout << a << " " << b << endl;
	}
}
