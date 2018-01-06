/*
* luogu1197 星球大战
* 2017 11 25
 */
#include <bits/stdc++.h>
using namespace std;
int n, m, k, father[200005];
vector<int> result;
int lst[200005];
set<int> caled;
struct edge {
	int x, y;
} p[200005];
inline int find(int val) {
	if(father[val] != val) father[val] = find(father[val]);

	return father[val];
}
inline void unionn(int val1, int val2) {
	father[find(val1)] = find(val2);
}
inline int count() {
	// 查找联通数量
	for (int i = 0; i <= n; ++i)
		int tempo = find(i);

	// 化为两层的树形结构
	int count = 0;
	int flag = father[0];

	for (int i = 1; i <= n; ++i) {
		if(father[i] != flag) {
			flag = father[i];
			++count;
		}
	}

	return count;
}
inline void initf() {
	for (int i = 0; i <= n; ++i)
		father[i] = i;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	initf();

	for (register int i = 0; i < m; ++i)
		cin >> p[i].x >> p[i].y;

	cin >> k;

	for (int val, i = 0; i < k; ++i) {
		cin >> lst[i];
		caled.insert(lst[i]);
	}

	/*
	for(int i = 0; i <= m; ++i) {
	   	unionn(p[i].x, p[i].y);
	}*/
	for(int i = 0; i < k; ++i) {
		int curr = lst[i];

		for(int i = 0; i <= m; ++i) {
			if(caled.count(p[i].y) == 0) {
				unionn(p[i].x, p[i].y);
			}
		}

		cout << count() << endl;

		for(int i = 0; i <= n; ++i) {
			cout << father[i] << " ";
		}

		cout << endl;
	}

	for(int i = result.size() - 1; i >= 0; --i) {
		cout << result[i] << endl;
	}

	return 0;
}