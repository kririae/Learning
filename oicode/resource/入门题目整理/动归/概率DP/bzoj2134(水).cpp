/*水水地分析一下就是了
*/
#include<cstdio>
using namespace std;
int n, A, B, C, a[10001000];
inline int max(const int &a, const int &b) {
	return a < b ? b : a;
}
int main() {
	scanf("%d%d%d%d%d", &n, &A, &B, &C, a + 1);

	for(int i = 2; i <= n; i++) a[i] = ((long long)a[i - 1] * A + B) % 100000001;

	for (int i = 1; i <= n; i++) a[i] = a[i] % C + 1;

	float ans = 0;
	a[n + 1] = a[1];

	for(int i = 1; i <= n; i++) ans += 1 / (float)max(a[i], a[i + 1]);

	printf("%.3lf", ans);
	return 0;
}
