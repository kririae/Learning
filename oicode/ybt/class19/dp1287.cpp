#include <iostream>
#include <cstring>
using namespace std;
int mmp[105][105];
int ass[105][105];
int minin(const int &a, const int &b) {
	return a < b ? a : b;
}
int main() {
	int n;
	cin >> n;
	for(int i = 0; i < 105; ++i) {
		for(int j = 0; j < 105; ++j) {
			mmp[i][j] = 0;
			ass[i][j] = 1000000;
		}
	}
	for(int i = 1; i <= n; ++i) 
		for(int j = 1; j <= n; ++j) 
			cin >> mmp[i][j];
	ass[1][1] = mmp[1][1];
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			int minnum = minin(ass[i - 1][j], ass[i][j - 1]);
			if(minnum == 1000000) minnum = 0;
			ass[i][j] = mmp[i][j] + minnum;
		}
	}
	cout << ass[n][n];
	return 0;
}
