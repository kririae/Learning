#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n;
bool mmp[205][205];
int value[205];
int res[205];
int best[205];
int main() {
	memset(mmp, false, sizeof(mmp));
	cin >> n;
	for(int i = 1; i <= n; ++i) 
		cin >> value[i];
	while(true) {
		int xi, yi;
		cin >> xi >> yi;
		if(xi == 0 && yi == 0) break;
		mmp[xi][yi] = true;
	}
	// mmp是邻接矩阵
	// res[i]表示在某一个地窖以后能挖到的最多的地雷
	memset(res, -1, sizeof(res));
	res[n] = value[n];
	for(int i = n - 1; i >= 1; --i) {
		// value[i]表示当前节点
		int maxn = 0;
		for(int j = i + 1; j <= n; ++j) {
			// value[j]表示向前迭代查看的节
			if(mmp[i][j] && res[j] > maxn) {
				maxn = res[j];
				best[i] = j;
			}
		}
		res[i] = maxn + value[i];
	}
	int maxnum = 0;
	int k = 1;
	for (int i = 1; i <= n; ++i)
		if(maxnum < res[i]) {maxnum = res[i]; k = i;}
	cout << k;
	k = best[k];
	while(k != 0) {
		cout << "-" << k;
		k = best[k];
	}
	cout << endl << maxnum;
	return 0;
}
