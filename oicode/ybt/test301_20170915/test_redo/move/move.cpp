#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;
int *result;
int main()
{
	freopen("move.in", "r", stdin);
	//freopen("move.out", "w", stdout);
	int n, r, m, p, minn;
	cin >> n >> r;
	long long summary = 0;
	result = new int[n + 5];
	int minnum;

	for(int i = 0; i < n; ++i) {
		cin >> result[i];

		if(i == 0) minnum = result[0];

		if(minnum > result[i]) minnum = result[i];

		if(result[i] < r) {
			r = result[i];
		}

		//summary += result[i] - r;
	}

	//为了不错误，修改为一种低效率的方案....
	int min_res = 0, sumn_res = INT_MAX;

	for(int i = minnum; i > 0; --i) {
		int sumn = 0;

		for(int j = 0; j < n; ++j)
			sumn += result[j] - i;

		if(sumn % i == 0 && sumn_res > sumn / i) {
			min_res = i;
			sumn_res = sumn / i;
		}
	}

	cout << sumn_res << ' ' << min_res << endl;

	if(min_res > r) cout << 'T';
	else cout << 'F';

	fclose(stdin);//fclose(stdout);
}
