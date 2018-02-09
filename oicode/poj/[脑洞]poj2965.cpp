#include <iostream>
#include <cstdio>
#include <bitset>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::bitset;
using std::pair;
using std::make_pair;

char c;
bitset<6> status[6];
bitset<6> origin[6];
std::vector<pair<int, int> > res;
namespace {
inline void push(int x, int y) {
    status[x][y] = ! status[x][y];
	for (int i = 1; i <= 4; ++i) {
		status[x][i] = !status[x][i];
		status[i][y] = !status[i][y];
	}
}
inline void init() {
	cin.tie(0);
	std::ios::sync_with_stdio(false);
	for (register int i = 1; i <= 4; ++i) 
		for (register int j = 1; j <= 4; ++j) {
			cin >> c;
			origin[i][j] = (c == '+');
			if(origin[i][j]) push(i, j);
		}
}
inline void solve() {
	init();
	for (int i = 1; i <= 4; ++i) 
		for (int j = 1; j <= 4; ++j) 
			if(status[i][j]) res.push_back(make_pair(i, j));  
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); ++i) 
		cout << res[i].first << " " << res[i].second << endl; 
}
}
int main() {
	solve();
	return 0;
}