#include <bits/stdc++.h>
using namespace std;
struct edge {
	int x, y, value;
	bool operator < (const edge (&a)) const {
		return this->value < a.value;
	}
} p[4000005];
int father[4000005];
inline int find(int v) {
	if(father[v] != v) father[v] = find(father[v]);
	return father[v];
}
inline void unionn(int a, int b) {
	int r1 = find(a), r2 = find(b);
	father[r1] = r2;
}
int main() {
	memset(father, 0, sizeof(father));
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, k, tot = 0;
	cin >> n >> k;
    for(register int i = 0; i <= n; ++i) {
        father[i] = i;
    }
    int summ = 0;
	for (register int status, rp = 0; rp < k; ++rp) {
		cin >> status >> p[rp].x >> p[rp].y >> p[rp].value;
		if(status == 1) {
			unionn(p[rp].x, p[rp].y);
			summ += p[rp].value;
		}
	}
	sort(p, p + k);
	int times = 0;
	for(register int i = 0; i < k; ++i) {
		if(find(p[i].x) != find(p[i].y)) {
		    summ += p[i].value;
			unionn(p[i].x, p[i].y);
		}
	}
	cout << summ << endl;
	return 0;
