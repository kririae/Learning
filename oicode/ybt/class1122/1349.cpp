// 注意0的情况
#include <bits/stdc++.h>
using namespace std;
struct edge {
	int x = 0, y = 0, value = 0;
	bool operator < (const edge (&a)) const
	{
		return this->value < a.value;
	}
};
edge *p;
int *father;
inline int find(int v)
{
	if(father[v] != v) father[v] = find(father[v]);

	return father[v];
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
	int k;
	cin >> k;
	father = new int[k * k + 5];
	p = new edge[k * k + 5];
	memset(father, 0, sizeof(father) * (k * k + 5));

	for(register int i = 0; i <= k * k + 5; ++i) {
		father[i] = i;
	}

	int ll = 0;

	for(register int i = 1; i <= k; ++i) {
		for(register int j = 1; j <= k; ++j) {
			cin >> p[ll].value;

			if(p[ll].value != 0) {
				p[ll].x = i, p[ll].y = j;
				++ll;
			}
		}
	}

	sort(p, p + ll);
	int summ = 0;

	for(register int i = 0; i < ll; ++i) {
		if(p[i].value != 0 && find(p[i].x) != find(p[i].y)) {
			summ += p[i].value;
			unionn(p[i].x, p[i].y);
		}
	}

	cout << summ << endl;
	return 0;
}
