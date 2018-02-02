// 题目本身是很简单的
// statuc: WA???
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
bzoj卡住了，趁机写一写注释 
 */
#include <bits/stdc++.h>
using namespace std;
// 快读，不解释 
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
// t表示总问题组数 n表示输入组数 
int t, n;
// 题中输入的三组数据
 
int s[maxn], e[maxn], d[maxn];
/*
二分的本质就是将求数字的问题转化为判定
所以基本上每一个二分的程序都需要一个判定
由于是logn次判定，哪怕判定复杂点都没有问题的说
这个判定就比较复杂 是O(n)的...
原理嘛，从左向右扫描 之前输入的数据(其实排序了好像还可以更快，不过没必要了
判断当前数字之前所有的个数
之前已经描述了，如果是奇数，就代表奇数点在当前judge的之前，如果是偶数就在之后
最后加了一个特判，因为怕跑过了，val后面多算...
为啥bzoj还没好啊...
总之这个judge的意义就在这里 
啊 WA了...算了... 
 */ 
inline bool check(long long val)
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
// 下面是二分的精华 
inline long long bina(long long l, long long r) 
{
	while(l < r) {
		long long mid = (l + r) >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;		
	} 
	return l;
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
    	long long posi = bina(1, n);
    	long long cnt = 0;
    	for (int i = 1; i <= n; ++i) {
    	    // 这里是求“夹在中间的点数”
    	    // 所以有一个s[i] <= posi && e[i] >=
    		if(s[i] <= posi && e[i] >= posi && (posi - s[i]) % d[i] == 0) ++cnt;
    	}
    	if(cnt % 2 == 0) cout << "Poor QIN Teng:(" << endl;
    	else cout << posi << " " << cnt << endl;
	}
}
