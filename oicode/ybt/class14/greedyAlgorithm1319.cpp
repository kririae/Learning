#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct people {
	int time;
	int __index__;
};
people res[1005];
bool compare(const people& a, const people& b) {
	if(a.time < b.time) return true;
	return false;
}
double summary[1005];
int main() {
	double summary = 0;
	int n, first;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> res[i].time;
		res[i].__index__ = i;
	}
	sort(res + 1, res + n + 1, compare);
	for(int i = 1; i <= n; ++i) {
		cout << res[i].__index__<< " ";
	}
	cout<<endl;
	printf("%.2lf", summary / (n - 1));
}
