#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int *res;
int main() {
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	int n;
	cin >> n;
	res = new int[n + 5];
	int minn;
	cin >> res[0];
	minn = res[0];
	for(int i = 1; i < n; ++i)  {
		cin >> res[i];
		if(res[i] < minn) minn = res[i];
	}
	int result;
	for(int i = minn; i >= 1; --i) {
		bool if_can = true;
		for(int j = 0; j < n; ++j) {
			if(res[j] % i != 0) {
				if_can = false;
				break;
			}
		}
		if(if_can) {
			result = i;
			break;
		}
	}
	cout<<result;
	fclose(stdin);fclose(stdout);
	return 0;
}
