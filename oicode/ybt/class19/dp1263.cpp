#include <iostream>
#include <algorithm>
using namespace std;
struct point {
	int a;
	int b;
	int c;
	point(): a(0), b(0), c(0) {};
};
point p[50005];
bool cmp(const point a, const point b)
{
	return a.a <= b.a;
}
int main()
{
	int n;
	cin >> n;

	for(int i = 0; i < n; ++i)
		cin >> p[i].a >> p[i].b;

	sort(p, p + n, cmp);

	for(int i = 0; i < n; ++i) {
		int maxn = 0;

		for(int j = 0; j <= i; ++j)
			if(p[i].b >= p[j].b && p[j].c > maxn)
				maxn = p[j].c;

		p[i].c = maxn + 1;
	}

	int res = 0;

	for(int i = 0; i < n; ++i)
		res = max(res, p[i].c);

	cout << res;
	return 0;
}
