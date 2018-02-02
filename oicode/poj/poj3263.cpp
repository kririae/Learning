#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>
#include <deque>
#include <queue>
#include <set>

using std::cout;
using std::cin;
using std::endl;
using std::pair;

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
// 拓扑排序 ???
// 啊啊啊不对
/*
个人觉得可以这么实现
建立一个图，加上并查集维护
分块算了...
维护一个一维数组，然后每当出现了限制之后，中间的一定小于旁边的
可以构造一个数组，每次操作之后将中间-1...
然后拿最高的来加上这个数组的值...
恩，...时间复杂度O(NM), 稳炸...
不对啊我在学前缀和..
怎么就觉得差分可以解决？
啊..真的可以qwq

差分模板题
啊，因为题目本身很简单把模板删了...模板太庞大了
别人说是前缀和...的确有点像，但前缀和是前缀和，差分是差分啊qwq...
还是差分好.jpg
核心部分都标注了
 */
inline void swap(int &a, int &b) {
    int c = b; b = a, a = c;
}

const int maxn = 1e5;
int n, i, h, r;
int a, b;
int sub[maxn];
std::set<pair<int, int> > vis;
int main()
{
    read(n); read(i); read(h); read(r);
	for (int qwq = 0; qwq < n; ++qwq) 
	{
		read(a); read(b);
		if(a > b) swap(a, b);
		// md不早说要判重啊!!!
		if(vis.count(pair<int, int>(a, b))) continue;
		else vis.insert(pair<int, int>(a, b));
		// ----------------------
		--sub[a + 1]; // 差分构建
		++sub[b]; // 差分构建
		// ----------------------
	}
	for (int i = 1; i <= n; ++i) {
		// ----------------------
		h += sub[i];
		// ----------------------
		cout << h<< endl;
	}
	return 0;
}
