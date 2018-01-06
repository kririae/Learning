#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main() {
	int n;
	double jwj, a, b, c, d;
	cin >> n >> a >> b;
	jwj = b / a;

	for (int i = 0; i < n - 1; ++i) {
		cin >> a >> b;

		if((b / a - jwj) > 5 / 100.0) cout << "better" << endl;

		if((b / a - jwj) < -5 / 100.0) cout << "worse" << endl;

		if((b / a - jwj) < 5 / 100.0 && (b / a - jwj) > -5 / 100.0) cout << "same" << endl;
	}

	return 0;
}