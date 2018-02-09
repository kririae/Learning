//
// Created by AliceMargatroid on 2017/12/30.
//
#include <bits/stdc++.h>
using namespace std;
const int dx[] = {
	-1, 0, 1, 0
};
const int dy[] = {
	0, 1, 0, -1
};
bool mmp[105][105];
int n, m, res, cnt;
char s[105];
int goList[25][4];

int main()
{
	int tempo[4] = {0, 1, 2, 3};

	do {
		for (int i = 0; i < 4; ++i) {
			goList[cnt][i] = tempo[i];
		}

		++cnt;
	} while(next_permutation(tempo, tempo + 4));

	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	char c;
	int startx, starty;
	int endx, endy;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> c;

			if(c == 'S') {
				startx = i, starty = j;
				mmp[i][j] = true;
				continue;
			}

			if(c == 'E') {
				endx = i, endy = j;
				mmp[i][j] = true;
				continue;
			}

			mmp[i][j] = c == '.';
		}
	}

	cin >> s;
	int length = strlen(s);

	// 0 <-
	// 1 up
	// 2 right
	// 3 down
	for (int i = 0; i < 24; ++i) {
		int currx = startx, curry = starty;

		for (int j = 0; j < length; ++j) {
			if(!mmp[currx][curry]) {
				break;
			}

			if(currx == endx && curry == endy) {
				++res;
				break;
			}

			currx += dx[goList[i][s[j] - '0']];
			curry += dy[goList[i][s[j] - '0']];
		}
	}

	cout << res << endl;
	return 0;
}
