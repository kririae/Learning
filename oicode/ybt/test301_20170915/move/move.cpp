#include <iostream>
#include <cstdio>
using namespace std;
int n, r, minn = 0, m, p;
int test[10005];
int main() {
	freopen("move.in", "r", stdin);
	freopen("move.out", "w", stdout);
	scanf("%d%d", &n, &r);

	for(int i = 0; i < n; ++i)
		scanf("%d", &test[i]);

	int sumn = 0;

	for(int j = 0; j < n; ++j)
		sumn += (test[j] - r);

	int minm = 100000000;

	for(int i = 0; i < r; ++i) {
		int number = (sumn + i * n) % (r - i);

		if(number == 0) {
			m = (sumn + i * n) / (r - i);

			if(m < minm) {
				p = r - i;
				minm = m;
			}
		}
	}

	cout << minm << " " << p;
	cout << endl;

	if(p > r) cout << "T";
	else cout << "F";

	fclose(stdin);
	fclose(stdout);
	return 0;
}
