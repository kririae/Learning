#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int tree[2005] = {0};
int main()
{
	int n, m;
	cin >> n >> m;

	for(int x, y, i = 0; i < m; ++i) {
		cin >> x >> y;
		tree[y] = x;
	}

	int root = 0;

	for(int i = 1; i <= n; ++i) {
		if(tree[i] == 0) root = i;
	}

	cout << root << endl;
	int allmax = 0;
	int maxnode = 0;

	for(int i = 1; i <= n; ++i) {
		int maxn = 0;

		for(int j = 1; j <= n; ++j) {
			if(tree[j] == i) ++maxn;
		}

		if(allmax < maxn) {
			maxnode = i;
			allmax = maxn;
		}
	}

	cout << maxnode << endl;

	for(int i = 1; i <= n; ++i) {
		if(tree[i] == maxnode) cout << i << " ";
	}

	return 0;
}
