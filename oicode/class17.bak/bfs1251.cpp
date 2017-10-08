#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct point {
	int x; 
	int y;
	int deepth;
};
const int go[4][2] = {{-1,0},{1, 0},{0,-1},{0, 1}};
point p[100000];
int main() {
	int m, n;
	while(true) {
		int minnres = 100000000;
		cin >> m >> n;
		if(m == 0 && n == 0) break;
		bool map[m + 5][n + 5];
		memset(map, false, sizeof(map));
		for(int i = 0; i < 10000; ++i) {
			p[i].x = 0, p[i].y = 0, p[i].deepth = 0;
		}
		point start, end;
		start.deepth = 0;
		for(int i = 1; i <= m; ++i) {
			char *c = new char[n + 5];
			scanf("%s", c + 1);
			for(int j = 1; j <= n; ++j) {
				map[i][j] = (c[j] != '#');
				if(c[j] == '@') 
					start.x = i, start.y = j;
				if(c[j] == '*')
					end.x = i, end.y = j;
			}
		}
		p[0] = start;
		int curr = 0, proc = 1;
		while(curr <= proc) {
			for(int k = 0; k < 4; ++k) {
				int gox = p[curr].x + go[k][0];
				int goy = p[curr].y + go[k][1];
				// cout << gox << " " << goy << endl;
				if(gox < 1 || goy < 1 || gox > m || goy > n) continue;
				if(!map[gox][goy]) continue;
				map[p[curr].x][p[curr].y] = false;
				p[proc].x = gox, p[proc].y = goy, p[proc].deepth = p[curr].deepth + 1;
				if(p[proc].x == end.x && p[proc].y == end.y && minnres > p[proc].deepth) 
					minnres = p[proc].deepth;
				++proc;
			}
			++curr;
		}
		if(minnres == 100000000) cout << -1 << endl;
		else cout << minnres << endl;
	}
	return 0;
}
