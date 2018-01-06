#include<cstdio>
using namespace std;
double f[5005];
inline double max(const double &a, const double &b) {
	return a < b ? b : a;
}
int main() {
	int r, b, t = 1;
	scanf("%d%d", &r, &b);

	for(int i = 1; i <= r; i++) {
		f[0] = i;

		for(int j = 1; j <= b; j++) {
			f[j] = max(0, i / (double)(i + j) * (f[j] + 1) + j / (double)(i + j) * (f[j - 1] - 1));
		}
	}

	printf("%.6lf", f[b] - 5e-7);
	return 0;
}
