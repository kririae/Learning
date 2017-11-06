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
point p[50000];
bool map[70][70];
char *c;
int main() {
	int m, n;
	int minnres = 100000000;
	cin >> m >> n;
	memset(map, false, sizeof(map));
	point start, end;
	start.deepth = 0;
	for(int i = 1; i <= m; ++i) {
		c = new char[n + 40];
		scanf("%s", c + 1);
		for(int j = 1; j <= n; ++j) {
			map[i][j] = (c[j] != '#');
		}
	}
	start.x = 1, start.y = 1, start.deepth = 1;
	end.x = m, end.y = n;
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
	cout << minnres << endl;
	return 0;
}
