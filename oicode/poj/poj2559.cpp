/*
 * by kririae
 * 2018/2/23
 */

#include <iostream>
#include <cstdio>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

namespace solve {

template <typename T> T min(T a, T b) 
{
	 return a < b ? a : b; 
}

template <typename T> T max(T a, T b) 
{
	return a < b ? b : a; 
}

inline char read()
{
	static const int IN_LEN = 1000000;
	static char buf[IN_LEN], *s, *t;
	s == t ? t = (s = buf) + fread(buf, 1, IN_LEN, stdin) : 0;
	return s == t ? -1 : *s++;
}

template <typename T>
inline void read(T &x)
{
	static char c;
	static bool iosig;
	for (c = read(), iosig = false; !isdigit(c); c = read()) {
		if (c == -1) return;
		c == '-' ? iosig = true : 0;
	}
	for (x = 0; isdigit(c); c = read()) x = (x + (x << 2) << 1) + (c ^ '0');
	iosig ? x = -x : 0;
}

const int maxn = 1e5 + 5;
const int inf = ~(1 << 31);
int n;
int height[maxn], width[maxn], a[maxn];
int toptr; // 栈顶指针
int t;

inline void init() 
{
	
}

inline void solve() 
{
	init();
	for (;;)
	{
		read(n);
		if(n == 0) break;
		long long ans = 0;
		for (register int i = 1; i <= n; ++i) read(a[i]);
		a[n + 1] = 0;
		for (register int i = 1; i <= n + 1; ++i)
		{
			if(a[i] > height[toptr])
			{
				height[++toptr] = a[i], width[toptr] = 1;
			} else {
				int wid = 0;
				while(height[toptr] > a[i] && toptr >= 0)
				{
					wid += width[toptr];
					ans = max(ans, (long long)wid * height[toptr]);
					--toptr;
				}
				height[++toptr] = a[i], width[toptr] = wid + 1;
			}
		}
		std::cout << ans << std::endl;
		memset(height, 0, sizeof(height));
		memset(width, 0, sizeof(width));
		memset(a, 0, sizeof(a));
		toptr = 0;
	}
}
} 

int main() {
  solve::solve();
  return 0;
}
