// by kririae
#define R register
#include <bits/stdc++.h>
 
using namespace std;
 
namespace BZOJ1072
{
const int maxn = 10;
 
char a[maxn];
int t, s[maxn], d, l, f[1 << maxn][1005], cnt[maxn];
inline void solve()
{
	cin >> t;
	while(t--)
	{
		memset(a, 0, sizeof(a));
		memset(f, 0, sizeof(f));
		memset(cnt, 0, sizeof(cnt));
		cin >> a >> d;
		l = strlen(a);
		for (int i = 0; i < l; ++i)
			++cnt[s[i] = a[i] - '0'];
		 
		f[0][0] = 1;
		for (int S = 0; S < (1 << l); ++S)
			for (int j = 0; j < d; ++j)
				for (int k = 0; k < l; ++k)
					f[S | (1 << k)][(j * 10 + s[k]) % d] += ((S & (1 << k)) == 0 ? f[S][j] : 0);
 
		for (int i = 0; i < 10; ++i)
			for (int j = 1; j <= cnt[i]; ++j)
				f[(1 << l) - 1][0] /= j;
 
		printf("%d\n", f[(1 << l) - 1][0]);
	}
}
}
 
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	BZOJ1072::solve();
	return 0;
}