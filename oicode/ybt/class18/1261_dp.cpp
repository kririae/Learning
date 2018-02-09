#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
int mmp[1005][1005];
int go[1005];
int indexi[1005];
int main()
{
	// freopen("test.in", "r", stdin);
	cin >> n;
	memset(mmp, -1, sizeof(mmp));
	memset(go, -1, sizeof(go));

	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			cin >> mmp[i][j];

	go[n] = 0;

	for(int i = n - 1; i >= 1; --i) {
		int maxn = 10000000;

		for(int j = i + 1; j <= n; ++j)
			if(mmp[i][j] > 0 && go[j] != -1) {
				if(maxn > mmp[i][j] + go[j]) {
					maxn = mmp[i][j] + go[j];
					indexi[i] = j;
				}
			}

		go[i] = maxn;
	}

	cout << "minlong=" << go[1] << endl;
	int start = 1;

	while(start != 0) {
		cout << start << " ";
		start = indexi[start];
	}

	return 0;
}
