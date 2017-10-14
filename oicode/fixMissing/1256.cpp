#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct Point {
	int x;
	int y;
	int deepth;
};
const int MAXN = 900;
bool mmp[MAXN][MAXN];
const int go[4][2] = {{-1,0},{1, 0},{0,-1},{0, 1}};
Point p[8000000];
int t;
int main() {
	cin >> t;
	for(int k = 0; k < t; ++k) {
		int r, c;
		cin >> r >> c;
		Point start, end;
		memset(mmp, false, sizeof(mmp));
		for(int i = 0; i < 8000000; ++i) {
			p[i].x = 0, p[i].y = 0, p[i].deepth = 0;
		}
		for(int i = 1; i <= r; ++i) {
			char *ca = new char[c + 5];
			scanf("%s", ca + 1);
			for(int j = 1; j <= c; ++j) {
				mmp[i][j] = (ca[j] != '#');
				if(ca[j] == 'S') start.x = i, start.y = j;
				if(ca[j] == 'E') end.x = i, end.y = j;
			}
		}
		start.deepth = 1;
		int curr = 0, proc = 1;
		p[curr] = start;
		mmp[start.x][start.y] = true;
		bool ifp = true;
		while(curr <= proc) {
			mmp[p[curr].x][p[curr].y] = false;
			for(int i = 0; i < 4; ++i) {
				int go_x = p[curr].x + go[i][0], go_y = p[curr].y + go[i][1];
				if(mmp[go_x][go_y]) {
					mmp[go_x][go_y] = false;
					p[proc].x = go_x;
					p[proc].y = go_y;
					p[proc].deepth = p[curr].deepth + 1;
					if(go_x == end.x && go_y == end.y) {
						ifp = false;
						cout << p[proc].deepth - 1 << endl;
						curr = proc + 100;
						break;
					}	
					++proc;
				}
			}
			++curr;
		}
		if(ifp) cout << "oop!" << endl;
	}
	return 0;
}