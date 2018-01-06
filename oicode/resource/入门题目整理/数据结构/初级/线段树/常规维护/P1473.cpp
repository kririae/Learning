#include<cstdio>
#define lowbit(x) x&(-x)
#define N 50005
using namespace std;
int a[N], b[N]; //aÇ°×º£¬bºó×º
int n, m, ins, f, t;
inline void add(int *arr, int x, int c) { //Ç°×º1~x +1
	for(int i = x; i <= n; i += lowbit(i))	arr[i] += c;
}
inline int query(int *arr, int x) {
	int ret = 0;

	if(x == 0) return 0;

	for(int i = x; i > 0; i -= lowbit(i))	ret += arr[i];

	return ret;
}
int main() {
	scanf("%d%d", &n, &m);
	int ret = 0;

	for(int i = 1; i <= m; i++) {
		scanf("%d%d%d", &ins, &f, &t);

		if(ins == 1) {
			ret++;
			add(a, t, 1);
			add(b, n - f + 1, 1);
		} else if(ins == 2) {
			printf("%d\n", ret - query(a, f - 1) - query(b, n - t));
		}
	}

	return 0;
}
