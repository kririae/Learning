// 题目本身是很简单的
/*
可以这么想
既然总共只有一个奇数点
那么除了这个点以外的所有数都是偶数
既然是位置，那么就可以二分
二分出奇数点的位置就对啦！
题目比较简单，template就免了
想到了二分是第一个问题...问题在于怎么统计每一个位置的..
emmmmm......怎么做啊（...想简单了（
emmmmm是每check一次都要重新跑一次么qwq...好像还行的样子，毕竟是二分
O(nlogn)
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
const int maxn = 200005;
int t, n;
int s[maxn], e[maxn], d[maxn];
inline bool check(int val)
{
	int count = 0;
	for (int i = 1; i <= n; ++i) {
		if(s[i] <= val) {
			if(e[i] <= val) count += (e[i] - s[i]) / d[i] + 1;
			else count += (val - s[i]) / d[i] + 1;
		}
	}
	return (count % 2 != 0);
}

int main() 
{
	t = read();
	for (int rp = 0; rp < t; ++rp)
	{
		n = read();
		for (int i = 1; i <= n; ++i) {
			s[i] = read(); e[i] = read(); d[i] = read();
		}
    	// init finished
    	int l = 1, r = n, mid = (l + r) >> 1;
    	while(true) 
    	{
    		int mid = (l + r) >> 1;
    		if(check(mid))
    		{
    			l = mid + 1;
    		}
    		else {
    			r = mid;
    		}
    		if(l == r) break;
    	}
    	cout << l << endl;
	}
}