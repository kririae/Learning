#include <iostream>
#include <cstdio>
using namespace std;
int *list, max_num = 0;
int maxn(int x, int y) {
	return x > y ? x : y;
}
int maxnum(int x, int y) {
	if(y - x == 1) return list[x];
	int m = x + (y - x) / 2;
	int maxs = maxn(maxnum(x, m), maxnum(m,  y));
	int value = 0, left, right;
	left = list[m - 1];
	for(int i = m - 1; i >= x; --i) left = maxn(left, value += list[i]);
	value = 0;right = list[m];
	for(int i = m; i < y; ++i) right = maxn(right, value += list[i]);
	return maxn(maxs, left + right);
}
int main() {
	freopen("watfly.in", "r", stdin);
	//freopen("watfly.out", "w", stdout);
	int n;
	cin >> n;
	list = new int[n + 5];
	for(int i = 0; i < n; ++i) cin >> list[i];
	int res = maxnum(0, n);
	cout<<res;
	fclose(stdin);//fclose(stdout);
}
