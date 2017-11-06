// run time error
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct Point {
	int x;
	int y;
	int deepth;
};
bool map[600][600];
const int go[4][2] = {{-1,0},{1, 0},{0,-1},{0, 1}};
Point p[100000];
int t;
int main() {
	cin >> t;
	for(int k = 0; k < t; ++k) {
		int r, c;
		cin >> r >> c;
		Point start, end;
		memset(map, false, sizeof(map));
		for(int i = 0; i < 40000; ++i) {
			p[i].x = 0, p[i].y = 0, p[i].deepth = 0;
		}
		for(int i = 1; i <= r; ++i) {
			char ca[40000];
			scanf("%s", ca + 1);
			for(int j = 1; j <= c; ++j) {
				map[i][j] = (ca[j] != '#');
				if(ca[j] == 'S') start.x = i, start.y = j;
				if(ca[j] == 'E') end.x = i, end.y = j;
			}
		}
		start.deepth = 1;
		int curr = 0, proc = 1;
		p[curr] = start;
		map[start.x][start.y] = true;
		int maxn = 10000000;
		while(curr <= proc) {
			for(int i = 0; i < 4; ++i) {
				int go_x = p[curr].x + go[i][0], go_y = p[curr].y + go[i][1];
				if(go_x < 1 || go_y < 1 || go_x > r || go_y > c) continue;
				if(!map[ go_x ][ go_y ]) continue;
				map[p[curr].x][p[curr].y] = false;
				p[proc].x = go_x;
				p[proc].y = go_y;
				p[proc].deepth = p[curr].deepth + 1;
				if(go_x == end.x && go_y == end.y) {
					if(maxn > p[proc].deepth) maxn = p[proc].deepth - 1;
				}	
				++proc;
			}
			++curr;
		}
		if(maxn == 10000000) cout << "oop!" << endl;
		else cout << maxn << endl;
	}
	return 0;
}