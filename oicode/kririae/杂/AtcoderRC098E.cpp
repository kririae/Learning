// by kririae
#include <bits/stdc++.h>

using namespace std;

namespace IO
{
inline char gc()
{
  static char buf[1 << 18], *fs, *ft;
  return (fs == ft && (ft = (fs = buf) + fread(buf, 1, 1 << 18, stdin)), fs == ft) ? EOF : *fs++;
}
inline int read()
{
  register int k = 0, f = 1;
  register char c = gc();
  for (; !isdigit(c); c = gc()) if (c == '-') f = -1;
  for (; isdigit(c); c = gc()) k = (k << 3) + (k << 1) + (c - '0');
  return k * f;
}
}

namespace AtcoderRC098E
{
const int maxn = 2005;

int n, k, q, a[maxn], b[maxn], c[maxn], cnt, cnt1, ans = 1e9;
bitset<maxn> vis;

inline void solve()
{
	using namespace IO;
	n = read(), k = read(), q = read();
	for (R int i = 1; i <= n; ++i) a[i] = read();
	for (R int i = 1; i <= n; ++i)
	{
		vis.reset();
		for (R int j = 1; j <= n; ++j) if(a[j] < a[i]) vis[j] = 1;
		for (R int j = 1; j <= n; ++j) 
		{
			if(vis[j] == 1) 
			{
				sort(b + 1, b + 1 + cnt), cnt = 0;
				for (int w = 1; w <= n - k + 1; ++w) c[++cnt1] = b[i];
				continue;
			}	
			b[++cnt] = a[j];
		}
		sort(c + 1, c + 1 + cnt1);
		ans = min(ans, c[q]);
	}
	printf("%d\n", ans);
}
}

int main()
{
	return AtcoderRC098E::solve(), 0;
}