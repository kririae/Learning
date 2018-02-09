/*
* by kriaeth
* status: RE
*/
#pragma GCC optimize(2)
#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>
#include <deque>
#include <queue>
#include <cmath>
#include <algorithm>

namespace solve
{
template<typename T>
inline T min(T a, T b)
{
	return a < b ? a : b;
}

template<typename T>
inline T max(T a, T b)
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
	for (c = read(), iosig = false; !isdigit(c); c = read()) 
	{
		if (c == -1) return;
		c == '-' ? iosig = true : 0;
	}
	for (x = 0; isdigit(c); c = read()) x = (x + (x << 2) << 1) + (c ^ '0');
	iosig ? x = -x : 0;
}

const int maxn = 200005;
int spr[maxn], belong[maxn], to[maxn], step[maxn];
int n, m;
int i, j, k;
int size, block_cnt;

inline void vio_init()
{
	read(n);
	for (int s = 0; s < n; ++s) read(spr[s]);
	read(m);
}
inline void vio_solve()
{
	// freopen("test.txt", "r", stdin);
    vio_init();
	for (int s = 0; s < m; ++s)
	{
		read(i); read(j);
		if(i == 1)
		{
		    int cnt = 0, summ = j;
			for (cnt = 0; summ < n;)
			{
				summ += spr[summ];
				++cnt;
			}
			std::printf("%d\n", cnt);
		}
		if(i == 2)
		{
			read(k);
			spr[j] = k;
		}
	}
}

struct Block
{
	int to; // 从当前块跳出后所在的位置
	int times; // 从这个块开始多少次可以跳出去
	int l, r;
	Block() {}
	Block(int t, int ti):to(t), times(ti) {}
}

Block *blocks;
inline void init()
{
	read(n);
	for (int s = 1; s <= n; ++s) read(spr[s]);
	read(m);
	
	size = int(sqrt(n));
	block_cnt = n % size ? n / size : n / size + 1;

	blocks = new Block[block_cnt];

	// initialize 
	// like buildTree
	for (int i = 1; i <= block_cnt; ++i)
	{
		blocks[i].l = blocks[i - 1].r + 1;
		blocks[i].r = blocks[i].l + size - 1;
	}
	blocks[block_cnt].r = n;	 
    for (int i = 1, j = 1; i <= block_cnt; ++j)
    {
    	belong[j] = i;
    	if(j == blocks[i].r) ++i;
    	// 初始化每一个点属于哪一个块
    }

    for (int i = n; i >= 1; --i)
    {
    	to[i] = i + spr[i];
    	if(to[i] > blocks[belong[i]]) step[i] = 1;
    	else step[i] = step[to[i]] + 1, to[i] = to[to[i]]; //?????
    }
}
inline void solve()
{
	init();
	for (int s = 1; s <= m; ++s)
	{
		read(i); read(j);
		if(i == 1)
		{
			ans = 0; summ = j + 1;
			while(summ <= n) ans += step[summ]; summ = to[summ];
			std::printf("%d\n", ans);
		}
		if(i == 2)
		{
			read(k); ++i;
			spr[i] = j;

			for (int rp = blocks[belong[i]].r; rp >= blocks[belong[i]].l; --rp)
			{
				to[i] = i + spr[i];
    			if(to[i] > blocks[belong[i]]) step[i] = 1;
    			else step[i] = step[to[i]] + 1, to[i] = to[to[i]]; //?????
			}
		}
	}
}
}

int main()
{
	solve::solve();
	return 0;
}
