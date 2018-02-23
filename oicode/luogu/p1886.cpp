/*
 * by kririae
 * 2018/2/23
 * luogu 1886
 * 双端队列模板题
 */

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;

namespace solve {
    
template <typename T>
inline T min(T a, T b) 
{
	 return a < b ? a : b; 
}

template <typename T> 
inline T max(T a, T b) 
{
	return a < b ? b : a; 
}

inline char read()
{
	static const int IN_LEN = 1000000;
	static char buf[IN_LEN], *s, *t;
	s == t ? t = (s = buf) + 
	fread(buf, 1, IN_LEN, stdin) : 0;
	return s == t ? -1 : *s++;
}

template <typename T>
inline void read(T &x)
{
	static char c;
	static bool iosig;
	for (c = read(), iosig = false; 
		!isdigit(c); c = read()) {
		if (c == -1) return;
		c == '-' ? iosig = true : 0;
	}
	for (x = 0; isdigit(c);
		c = read())
		x = (x + (x << 2) << 1) + (c ^ '0');
	iosig ? x = -x : 0;
}

using std::deque;
using std::pair;

const int maxn = 1e6 + 5;
deque<std::pair<int, int> > dq;
// 两个队列，一个单增，一个单减
int n, k;
int a[maxn];

inline void get(int opt)
{
	dq.clear();
	for (int i = 1; i <= n; ++i)
	{
		if(opt) while(dq.size() != 0 && dq.back().first < a[i]) dq.pop_back();
		else while(dq.size() != 0 && dq.back().first > a[i]) dq.pop_back();
		dq.push_back(std::make_pair(a[i], i));
		while(dq.front().second <= (i - k)) dq.pop_front();
		if(i >= k) cout << dq.front().first << " ";
	}
	cout << endl;
}

inline void init() 
{
	read(n); read(k);
	for (int i = 1; i <= n; ++i)
		read(a[i]);
}

inline void solve() 
{
	init();	
	get(false);
	get(true);
}
} 

int main()
{
	solve::solve();
	return 0;
}
