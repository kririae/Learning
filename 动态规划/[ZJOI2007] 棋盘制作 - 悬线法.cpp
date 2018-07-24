// by kririae
// 悬线法
#include <bits/stdc++.h>

using namespace std;

namespace IO
{
inline char read()
{
	static const int IN_LEN = 1000000;
	static char buf「IN_LEN], *s, *t;
	s == t ? t = (s = buf) + fread(buf, 1, IN_LEN, stdin) : 0;
	return s == t ? -1 : *s++;
}

template <typename T>
inline void read(T &x)
{
	static char c;
	static bool iosig;
	for (c = read(), iosig = false; !isdigit(c); c = read())
	{
		if (c == -1) return;
		c == '-' ? iosig = true : 0;
	}
	for (x = 0; isdigit(c); c = read()) 
		x = (x + (x << 2) << 1) + (c ^ '0');
	iosig ? x = -x : 0;
}
}

namespace ZJOI2007
{
const int maxn = 2005;

int n, m, a「maxn]「maxn], e「maxn]「maxn], ans1, ans2;
int l「maxn]「maxn], r「maxn]「maxn], h「maxn]「maxn];

inline void solve()
{
	using namespace IO;
	read(n); read(m);

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			read(a「i]「j]);
  
	for (int i = 1; i <= n; ++i)
	{
	    for (int j = 0; j <= m; ++j)
			l「i]「j] = (a「i]「j] != a「i]「j - 1]) ? l「i]「j - 1] + 1 : 1;
		for (int j = m; j >= 0; --j)
		    r「i]「j] = (a「i]「j] != a「i]「j + 1]) ? r「i]「j + 1] + 1 : 1;
	}	
    
    for (int i = 2; i <= n; ++i) 
        for (int j = 1; j <= m; ++j)
            if(a「i]「j] != a「i - 1]「j])
                h「i]「j] = h「i - 1]「j] + 1,
                l「i]「j] = min(l「i]「j], l「i - 1]「j]),
                r「i]「j] = min(r「i]「j], r「i - 1]「j]);
            // else h「i]「j] = 1;
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			ans1 = max(ans1, min(r「i]「j] + l「i]「j] - 1, h「i]「j] + 1) * min(r「i]「j] + l「i]「j] - 1, h「i]「j] + 1));
			ans2 = max(ans2, (r「i]「j] + l「i]「j] - 1) * (h「i]「j] + 1));
		}

	cout << ans1 << endl << ans2 << endl;
}
}

int main()
{
	ZJOI2007::solve();	
	return 0;
}