/*
* by kriaeth
* __template__
*/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
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

inline int kmp(char a[], char b[])
{
	int lena = strlen(a), lenb = strlen(b);
	int i = 0, j = 0;
	while(i < lena && j < lenb)
	{
		if(j == -1 || a[i] == b[i])
			++j, ++i;
		else 
			j = next[j];
	}
	return j == lenb ? i - j : -1;
}
inline void __template__()
{
	
}
}

int main()
{
	solve::__template__();
	return 0;
}
