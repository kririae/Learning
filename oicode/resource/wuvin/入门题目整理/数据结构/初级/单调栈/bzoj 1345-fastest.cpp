#include<cstdio>
using namespace std;
int n, t, a;
long long ans = 0;
inline void read(int &x)
{
	char c;
	x = 0;
	while((c = getchar()) < '0' || c > '9');
	while(c >= '0' && c <= '9') (x *= 10) += c - '0', c = getchar();
}
int main()
{
	read(n);
	read(t);
	for(int i = 1; i < n; i++, t = a) {
		read(a);
		ans += (a < t ? t : a);
	}
	printf("%lld", ans);
	return 0;
}
