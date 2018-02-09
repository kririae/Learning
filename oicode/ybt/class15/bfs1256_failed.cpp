#define DEBUG
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
void printOut()
{
	for(int i = 0; i < r + 2; ++i) {
		for(int j = 0; j < c + 2; ++j) {
			cout << mmp[i][j];
		}

		cout << endl;
	}

	cout << endl;
}
point p[1000];
int main()
{
	freopen("bfs1256.in", "r", stdin);
	cin >> t;

	for(int k = 0; k < t; ++k) {
		cin >> r >> c;
		point start, end;
		memset(mmp[0], false, sizeof(mmp[0]));
		memset(mmp[r + 1], false, sizeof(mmp[r + 1]));

		for(int i = 0; i < r + 2; ++i)
			mmp[i][0] = false, mmp[i][r + 2] = false;

		for(int i = 1; i <= r; ++i) {
			char *ca = new char[c];
			scanf("%s", ca);

			for(int j = 1; j <= c; ++j) {
				mmp[i][j] = (ca[j - 1] != '#');

				if(ca[j] == 'S') start.x = i, start.y = j;

				if(ca[j] == 'E') end.x = i, end.y = j;
			}
		}

#ifdef DEBUG
		printOut();
		cout << "start: " << start.x << " " << start.y << endl;
		cout << "end: " << end.x << " " << end.y << endl;
#endif
		int current = 0, processing = 1;
		p[current] = start;

		while(current <= processing) {
			for(int i = 0; i < 3; ++i) {
				int go_x = go[i][0], go_y = go[i][1];

				if(mmp[p[current].x + go_x][p[current].y + go_y] && p[current].x >= 1 && p[current].y >= 1) {
					mmp[p[current].x][p[current].y] = false;
					mmp[p[current].x + go_x][p[current].y + go_y] = false;
					p[processing].x = p[current].x + go_x;
					p[processing].y = p[current].y + go_y;
					p[processing].deepth = p[current].deepth + 1;
					++processing;
					// if(p[processing].x == end.x && p[processing].y == end.y) // result.insert(p[processing].deepth);
					cout << p[processing].deepth << endl;
				}
			}

			/*
			if(mmp[p[current].x + 1][p[currenr].y]) {
				mmp[p[current].x + 1][p[currenr].y]	= false;
				mmp[p[current].x][p[current].y] = false;
				p[processing].deepth = p[current].deepth + 1;
				++processing;
			}
			if(mmp[p[current].x + 1][p[currenr].y]) {

			}
			if(mmp[p[current].x + 1][p[currenr].y]) {

			}
			if(mmp[p[current].x + 1][p[currenr].y]) {

			}*/
			cout << "------------------" << endl;
			++current;
		}

		for(set<int>::iterator it = result.begin(); it != result.end(); ++it) {
			cout << *it << endl;
		}
	}

	fclose(stdin);
	return 0;
}
void bfs()
{

}
