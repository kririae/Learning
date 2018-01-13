#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
bool input[50][50];
struct point {
	int x;
	int y;
	int deepth;
	point(): x(0), y(0), deepth(0) {};
};
point p[10000000];
const int go[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int main()
{
	int r, c;
	cin >> r >> c;
	memset(input, false, sizeof(input));

	for(int i = 1; i <= r; ++i)
		for(int j = 1; j <= c; ++j) {
			char x;
			cin >> x;
			input[i][j] = (x == '.');
		}

	int curr = 0, proc = 1;
	p[curr].x = 1;
	p[curr].y = 1;
	p[curr].deepth = 0;
	int maxn = 0;

	while(curr <= proc) {
		input[p[curr].x][p[curr].y] = false;

		for(int i = 0; i < 4; ++i) {
			int gox = p[curr].x + go[i][0];
			int goy = p[curr].y + go[i][1];

			if(input[gox][goy]) {
				input[gox][goy] = false;
				p[proc].x = gox, p[proc].y = goy, p[proc].deepth = p[curr].deepth + 1;

				if(gox == r && goy == c) {
					cout << p[proc].deepth + 1;
					return 0;
				}

				++proc;
			}
		}

		++curr;
	}

	cout << maxn;
	return 0;
}