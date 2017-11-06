#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int m, n;
struct requests {
	int money;
	int jj;
	double res;
};
requests req[50000];
bool compare(const requests& a, const requests& b) {
	if(a.res > b.res) return true;
	return false;
}
int main() {
	freopen("teacher.in", "r", stdin);
	freopen("teacher.out", "w", stdout);
	int all = 0;
	cin >> m >> n;
	for(int i = 1; i <= m; ++i) {
		//request
		int num;
		cin >> num;
		for(int j = 0; j < num; ++j) {
			cin >> req[all].money;
			cin >> req[all].jj;
			req[all].res = (double)req[all].jj / (double)req[all].money;
			++all;
		}
	}
	sort(req, req + all + 3, compare);
	long long summary = 0;
	summary += m * 100;
	int sumnum = 0;
	for(int i = 0; i < all; ++i) {
		if((sumnum + req[i].money) <= n) {
			summary += req[i].jj;
			sumnum += req[i].money;
		}
	}
	cout<<summary;
	fclose(stdin);fclose(stdout);
	return 0;
}
