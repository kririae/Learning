#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
struct point {
	int x;
	int y;
};
const int go[2][2] = {{-1, 0}, {0, -1}};
const int go_h[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
long long memo[23][23];
bool gcan[23][23];
bool horse[23][23];
point p[10000];
int main() {
	memset(gcan, false, sizeof(gcan));
	memset(horse, false, sizeof(gcan));
	memset(memo, 0, sizeof(memo));
	int posibx, posiby;
	int hposix, hposiy;
	cin >> posibx >> posiby >> hposix >> hposiy;
	++posibx, ++posiby, ++hposix, ++hposiy;
	horse[hposix][hposiy] = true;
	for(int i = 0; i < 8; ++i)  {
		int gox = hposix + go_h[i][0];
		int goy = hposiy + go_h[i][1];
		if(gox < 1 || goy < 1 || gox > posibx || goy > posiby) continue;
		horse[gox][goy] = true;
	}
	gcan[1][1] = true;
	memo[1][1] = 1;
	for(int i = 1; i <= posibx; ++i) {
		for(int j = 1; j <= posiby; ++j) {
			if(!horse[i][j]) {
				for(int k = 0; k < 2; ++k) {
					if(gcan[i + go[k][0]][j + go[k][1]] && !horse[i + go[k][0]][j + go[k][1]]) {
							memo[i][j] += memo[i + go[k][0]][j + go[k][1]];
							gcan[i][j] = true;
					}
				}
			}	
		}
	} 
	cout << memo[posibx][posiby];
}