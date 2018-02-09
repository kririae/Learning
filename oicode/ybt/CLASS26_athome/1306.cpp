/*
* by kriaeth 2017/11/8 17:32
* lis
*/
#include <bits/stdc++.h>
using namespace std;
struct posi {
	int v;
	int a;
	int b;
};
int v[505][505] = {0};
int a[505] = {0};
int b[505] = {0};
int memo[505][505] = {0};
posi value[505];
vector<int> res;
vector<int> res2;
void initlcs()
{
	int length = res.size();

	for(int i = 0; i < length; ++i) {
		value[i + 1].v = res[i];
		value[i + 1].a = 1;
		value[i + 1].b = 0;
	}

	for(int i = 1; i <= length; ++i) {
		int maxn = 0;

		for(int j = i - 1; j >= 1; --j) {
			if(value[i].v > value[j].v && value[j].a > maxn) {
				maxn = value[j].a;
				value[i].b = j;
			}
		}

		value[i].a = maxn + 1;
	}

	int result = 0;
	int max_index = 0;

	for(int i = 1; i <= length; ++i)
		if(value[i].a > result) {
			result = value[i].a;
			max_index = i;
		}

	cout << result << endl;

	while(max_index >= 1) {
		res2.push_back(value[max_index].v);
		max_index = value[max_index].b;
	}

	for(int i = res2.size() - 1; i >= 0; --i)
		cout << res2[i] << " ";
}
void initres(int x, int y)
{
	if(x == 0 || y == 0) return;

	if(memo[x][y] == 1) {
		initres(x - 1, y - 1);
		res.push_back(a[x]);
	} else {
		if(memo[x][y] == 0) initres(x, y - 1);
		else if(memo[x][y] == -1) initres(x - 1, y);
	}
}
int main()
{
	int n, m;
	cin >> n;

	for(int i = 1; i <= n; ++i)
		cin >> a[i];

	cin >> m;

	for(int i = 1; i <= m; ++i)
		cin >> b[i];

	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(a[i] == b[j]) {
				v[i][j] = v[i - 1][j - 1] + 1;
				memo[i][j] = 1;
			} else {
				v[i][j] = max(v[i - 1][j], v[i][j - 1]);

				if(v[i - 1][j] < v[i][j - 1]) {
					v[i][j] = v[i][j - 1];
					memo[i][j] = 0;
				} else {
					v[i][j] = v[i - 1][j];
					memo[i][j] = -1;
				}
			}
		}
	}

	initres(n, m);
	initlcs();
	return 0;
}