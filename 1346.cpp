#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int maxn = 20005;
int father[maxn];
int n, m, q;
inline int find(int ind) {
	if(father[ind] != ind) father[ind] = find(father[ind]);
	return father[ind];
}
inline void unionn(int indx, int indy) {
	father[indy] = indx;
}
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) 
		father[i] = i;
	for(int x, y, i = 0; i < m; ++i) {
		scanf("%d%d", &x, &y);
		int r1 = find(x);
		int r2 = find(y);
		if(r1 != r2) unionn(r1, r2);
	}
	cin >> q;
	for(int x, y, i = 0; i < q; ++i) {
		scanf("%d%d", &x, &y);
		if(find(x) == find(y)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
