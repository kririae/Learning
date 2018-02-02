/*
* by kriaeth
* time:
* using template v0.0
* read function by xehoth
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>
#include <deque>
#include <queue>

using std::cout;
using std::endl;
using std::cin;

namespace solve
{

template<typename T>
inline T min(T a, T b) {
    return a < b ? a : b;
}

const int inf = ~(1 << 31);
int t, res = inf;
std::bitset<7> map[7];
std::bitset<7> tempo_map[7];

inline void push(int x, int y, int &cnt) 
{
    ++cnt;
	tempo_map[x - 1][y] = tempo_map[x - 1][y] ^ 1;
	tempo_map[x][y - 1] = tempo_map[x][y - 1] ^ 1;
	tempo_map[x + 1][y] = tempo_map[x + 1][y] ^ 1;
	tempo_map[x][y + 1] = tempo_map[x][y + 1] ^ 1;
	tempo_map[x][y] = tempo_map[x][y] ^ 1;
}

inline void init()
{
	char curline[5];
	for (int i = 1; i <= 5; ++i) {
		std::scanf("%s", curline + 1);
		for (int j = 1; j <= 5; ++j) 
			map[i][j] = (curline[j] - '0');
	}
	res = inf;
}

inline void solve()
{
	int t;
	scanf("%d", &t);
	for (int rp = 0; rp < t; ++rp) {
		init();
		// 枚举第一行修改的所有情况
		// tempo_map = map;
		for (int k = 0; k < (1 << 5); ++k) {
		    for (int i = 0; i < 7; ++i) {
		        for (int j = 0; j < 7; ++j) {
		            tempo_map[i][j] = map[i][j];
		        }
		    }
			int cnt = 0;
	        for (int i = 1; i <= 5; ++i) 
	        	if(k & (1 << i)) push(1, i, cnt);
	        // 改变的每一行，使上面一行灭
	       	for (int i = 2; i <= 5; ++i) 
	       		for (int j = 1; j <= 5; ++j) 
	       		if(tempo_map[i - 1][j]) push(i, j, cnt);
	       	bool succeed = true;
	       	for (int i = 1; i <= 5; ++i)
	       	for (int j = 1; j <= 5; ++j)
	       		if(tempo_map[i][j] == 1) succeed = false;
	       	if(succeed) {
	       		res = min(res, cnt);
	       	}
	    }
	    std::cout << res << std::endl;
	}
}
}

int main()
{
	solve::solve();
	return 0;
}
