#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int p[105][105];
struct item {
	int value;
	int index_x;
	int index_y;
};
item list[10005];
int summary = 0;
int maxnum;
const int go[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int res[4];

bool cmp(item a, item b);
int getMax();

int main() {
	freopen("dp1280.in", "r", stdin);
	memset(res, 0, sizeof(res));
	int r, c;
	cin >> r >> c;
	int count = 0;
	for(int i = 0; i < r; ++i) 
		for(int j = 0; j < c; ++j) {
			cin >> p[i][j];
			list[count].value = p[i][j];
			list[count].index_x = i;
			list[count].index_y = j;
			++count;
		}
	sort(list, list + count + 5, cmp);
	maxnum = list[0].value;
	for(int i = 0; i < count; ++i) {
		if(list[i].value == maxnum) {
			p[list[i].index_x][list[i].index_y] = 0;
			list[i].value = 0;
			for(int j = 0; j < 4; ++j) {
				int go_x = list[i].index_x + go[j][0];
				int go_y = list[i].index_y + go[j][1];
				if(go_x < 0 
					|| go_x > r
					|| go_y < 0 
					|| go_y > c) 
						continue;
				res[j] = p[go_x][go_y];	
			}
			maxnum = getMax();
			++summary;
		}
	}
	cout << summary;
	fclose(stdin);
	return 0;
}
bool cmp(item a, item b) {return a.value >= b.value;}
int getMax() {
	int maxn = -1;
	sort(res, res + 4);
	for(int i = 0; i < 4; ++i) {
		if(res[i] > maxn && res[i] < maxnum) maxn = res[i];
	}
	memset(res, 0, sizeof(res));
	return maxn;
}
