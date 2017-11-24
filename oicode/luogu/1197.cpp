#include <bits/stdc++.h>
using namespace std;
int n, m, k, father[200005];
vector<int> result;
struct edge {
	int x, y;
} p[200005];
inline int find(int val) {
	if(father[val] != val) father[val] = find(val);
	return father[val];
}
inline void unionn(int val1, int val2) {
	father[find(val1)] = find(val2);
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i <= n; ++i) 
		father[i] = i;
	for (register int i = 0; i < m; ++i) 
		cin >> p[i].x >> p[i].y;
	cin >> k;
	for (int val, i = 0; i < k; ++i) {
		cin >> val;
		for(int i = 0; i < m; ++i) {
			if(p[i].x == val || p[i].y == val) {
				unionn(p[i].x, p[i].y);
			}
		}
		// 查找联通数量
		for (int i = 0; i <= n; ++i) 
			int tempo = find(i);
		// 化为两层的树形结构
		int count = 1;
		int flag = father[0];
		for (int i = 1; i <= n; ++i) {
			if(father[i] != flag) {
				flag = father[i];
				++count;
			}
		}
		result.push_back(count);
	}
	for(int i = result.size() - 1; i >= 0; --i) {
		cout << result[i] << endl;
	}
	return 0;
}