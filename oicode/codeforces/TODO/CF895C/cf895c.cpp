/*
 * by kririae 2018/2/3 -> 14:39
 */
#include <bits/stdc++.h>
using namespace std;

inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
const int maxn = 1e5 +5;
int n;
unsigned int array[maxn];
vector<unsigned int> res;
int main() {
	n = read();
	for (register int i = 1; i <= n; ++i) array[i] = read();
	// 	求1 -> 70 上的素数
	for (int i = 2; i <= 70; ++i) {
		if(!last[i]) res.push_back(i);
		for (int j = i << 1; j <= n; j += i) last[j] = true;
	}
	// 求出素数之后建立一个[19]元素长度的a，来储存状态qwq
	// give up
}