// #define DEBUG
#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
struct point {
	int x;
	int y;
	int deepth;
};
int t, r, c;
void bfs();
const int MAXN = 205;
bool mmp[MAXN][MAXN];
const int go[4][2] = {{-1, 0},
	{ 1, 0},
	{ 0, -1},
	{ 0, 1}
};
set<int> result;
void printOut() {
	for(int i = 0; i < r + 2; ++i) {
		for(int j = 0; j < c + 2; ++j) {
			cout << mmp[i][j];
		}

		cout << endl;
	}

	cout << endl;
}
point p[1000];
int main() {
	freopen("bfs1256.in", "r", stdin);
	cin >> t;

	for(int k = 0; k < t; ++k) {
		cin >> r >> c;
		point start, end;
		memset(mmp, false, sizeof(mmp));

		for(int i = 1; i <= r; ++i) {
			char *ca = new char[c + 5];
			scanf("%s", ca + 1);

			for(int j = 1; j <= c; ++j) {
				mmp[i][j] = (ca[j] != '#');

				if(ca[j] == 'S') start.x = i, start.y = j;

				if(ca[j] == 'E') end.x = i, end.y = j;
			}
		}

#ifdef DEBUG
		printOut();
		cout << "start: " << start.x << " " << start.y << endl;
		cout << "end: " << end.x << " " << end.y << endl;
#endif
		start.deepth = 1;
		int current = 0, processing = 1;
		p[current] = start;
		mmp[start.x][start.y] = true;
		int maxn = 1000000000;

		while(current <= processing) {
			for(int i = 0; i < 4; ++i) {
				int go_x = p[current].x + go[i][0], go_y = p[current].y + go[i][1];

				if(go_x < 1 || go_y < 1 || go_x > r || go_y > c) continue;

				if(!mmp[ go_x ][ go_y ]) continue;

				mmp[p[current].x][p[current].y] = false;
				//mmp[p[current].x + go_x][p[current].y + go_y] = false;
				p[processing].x = go_x;
				p[processing].y = go_y;
				p[processing].deepth = p[current].deepth + 1;

				if(go_x == end.x && go_y == end.y) {
					if(maxn > p[processing].deepth) maxn = p[processing].deepth - 1;
				}

				++processing;
			}

			++current;
		}

		cout << maxn << endl;
		/*
		for(int i = 0; i < processing; ++i) {
			cout << p[i].x << " " << p[i].y << " " << p[i].deepth << endl;
		}*/
		cout << endl << endl << endl;
	}

	fclose(stdin);
	return 0;
}
