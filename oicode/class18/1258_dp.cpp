#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 1005;
int lines[maxn][maxn];
int memo[maxn][maxn];
int layers;
int main() {
	scanf("%d", &layers);
	for(int i = 1; i <= layers; ++i) 
		for(int j = 1; j <= i; ++j) 
			cin >> lines[i][j];
	memo[1][1] = lines[1][1];
	for(int i = 2; i <= layers; ++i) {
		for(int j = 1; j <= i; ++j) {
			memo[i][j] = max(memo[i - 1][j - 1], memo[i - 1][j]) + lines[i][j];
		}
	}
	int ans = 0;
	for(int i = 1; i <= layers; ++i) 
		ans = max(ans, memo[layers][i]);
	cout << ans << endl;
	return 0;
}
