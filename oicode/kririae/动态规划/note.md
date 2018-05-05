# 动态规划题目汇总

---

<!--more-->

## [luogu1273] 有线电视网
### 说明
一道比较普通的树形dp
### 代码
```cpp
// by kririae
// 树形dp（模板题？）
#include <bits/stdc++.h>

using namespace std;

namespace luogu1273
{
const int maxn = 3005;

struct Edge
{
	int from, to, val;
	Edge() {}
	Edge(int f, int t, int v) : from(f), to(t), val(v) {}
};

int n, m, k, ai, c, a[maxn], f[maxn][maxn], siz[maxn];
vector<Edge> edges[maxn];

inline void addedge(int from, int to, int val)
{
	edges[from].push_back(Edge(from, to, val));
// 	edges[to].push_back(Edge(to, from, val));
}

inline void dp(int k)
{
	f[k][0] = 0;
	if(!edges[k].size()) 
			return f[k][1] = a[k], siz[k] = 1, void();
	
	for (int i = 0; i < edges[k].size(); ++i)
	{
		Edge &e = edges[k][i];
				dp(e.to);
		for (int j = siz[k]; j >= 0; --j)
			for (int l = siz[e.to]; l >= 0; --l)
					f[k][j + l] = max(f[k][j + l], f[k][j] + f[e.to][l] - e.val); 
		siz[k] += siz[e.to];
	}
}

inline void solve()
{
	memset(f, ~0x3f, sizeof(f));
	cin >> n >> m;
	for (int i = 1; i <= (n - m); ++i)
	{
		cin >> k;
		for (int j = 1; j <= k; ++j)
		{
			cin >> ai >> c;
			addedge(i, ai, c);
		}
	}

	// for (int i = 1; i <= n; ++i)
	// cin >> a[i];
		
	for (int i = (n - m + 1); i <= n; ++i)
		cin >> a[i];
				
	dp(1);

	for (int i = m; i > 0; --i)
		if(f[1][i] >= 0)
			return cout << i << endl, void();
}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	luogu1273::solve();
	return 0;
}
```

## [ZJOI2005] 午餐
### 说明
实现思路
贪心 + dp
#### 贪心
##### 贪心算法：
按照$b[i]$排序
##### 贪心证明：
首先定义$s[i] = \sum_{j = 1}^{i}{a[i]}$
对于排序后的序列$S$中的某一个人，饭的总时间$t[i] = s[i] + b[i]$ ，所以当前队伍的集合时间是$max(t[i])$，假如说有一个更优算法,在处理这个人的时候首先处理$S_{i + 1}$。假如说最大值在$t[i]$和$t[i + 1]$中取得
很明显$s[i + 1] > s[i]$
那么之前$t[i + 1] = max(s[i] + b[i], s[i + 1] + b[i + 1])$
变为了$t[i + 1] = max(s[i] + b[i + 1], s[i + 1] + b[i])$
显然第二者 > 第一者，所以贪心算法（交换前的算法）最优。
#### DP
状态设计$f[i][j]$表示前$i$个人安排在第一个队列，打饭总时间为$j$所花费的最小时间。
显然，决策有两个，把当前这个人放在第一个队列里和第二个队列里。
$$f[i][j] = min(max(f[i - 1][j - a[i]], j + b[i]), max(f[i - 1][j], s[i] - j + b[i])$$
简单解释一下，第$f[i - 1][j - a[i]]$表示这个是放在第一个队列里的，同理，$f[i - 1][j]$表示这个放在第二个队列里
$j + b[i]$表示转移后的总时间，放在第二个队列里的话，有一个类似“守恒”的思想。
$s[i] - j$表示在第二个队列里打饭的总时间，$s[i] - j + b[i]$的意义就是总时间啦。
### 代码
```cpp
// by kririae
#include <bits/stdc++.h>

using namespace std;

namespace ZJOI2005
{
const int maxn = 203;

struct Person
{
	int a, b;
	Person() {}
	Person(int ai, int bi) : a(ai), b(bi) {} 

	bool operator < (Person val) const 
	{ return b == val.b ? a < val.a : b > val.b; }
};

int n, s[maxn], f[maxn][maxn * maxn];
Person g[maxn];

inline void solve()
{
	memset(f, 0x3f, sizeof(f));
	
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> g[i].a >> g[i].b;
	
	sort(g + 1, g + 1 + n);
	
	for (int i = 1; i <= n; ++i)
		s[i] = s[i - 1] + g[i].a;
		
	f[0][0] = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = s[i]; j >= 0; --j)
		{
			if(j - g[i].a >= 0) f[i][j] = min(f[i][j], max(f[i - 1][j - g[i].a], j + g[i].b));
			f[i][j] = min(f[i][j], max(f[i - 1][j], s[i] - j + g[i].b));
		}

	int ans = 1e9;
	for (int i = 0; i <= s[n]; ++i)
		ans = min(ans, f[n][i]);
	cout << ans << endl;
}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	ZJOI2005::solve();
	return 0;
}
```

## [BZOJ1801] 中国象棋
### 说明
这道题被作为省选题难度就在“压缩信息”上吧。
动态规划本质上是信息的压缩，这点大家都知道...可是这道题的信息要压缩两遍...
第一次，应该都想得到的状压dp，能够帮助这道题的转移，可以A 30分。
第二次，我们发现，状态的转移并不需要具体的情况，状压dp的思路提醒我们，应该按照行来处理，那么设计状态$f[i][j][k]$表示放到了第$i$行，前面所有只有一个棋子的列的个数是$j$，已经不能再放（有两个棋子）的列的个数是$k$。那么，并不容易想到，决策有五种：
* 第一种是直接向上放，转移方程$f[i + 1][j][k] += f[i][j][k]$
* 第二种是放在一个只有一个棋子的列上$f[i +1][j - 1][k + 1] += (f[i][j][k] * j)$，j是决策总数，由乘法原理易得。
* 第三种以及之后的都是“放两个棋子”，第三种是放两个棋子在两个空列$f[i][j][k] += (f[i][j][k]) * C_{2}^{m - j - k}$
* 第四种是放一个在一个空列，一个在一个已经有一颗棋子的列上$f[i + 1][j][k + 1] += (f[i][j][k]) \times (m - j - k) \times j$
* 第五种是放两个在已经有一个棋子的列上$f[i +1][j - 2][k + 2] += (f[i][j][k] * C_{2}^{j})$。由此看来...还是很难的（逃，不过是一道练习信息压缩的好题。
### 代码

```cpp
// by kririae
#include <bits/stdc++.h>

using namespace std;

namespace AHOI2009
{
const int maxn = 105;
const int mod = 9999973;

int n, m;
long long f[maxn][maxn][maxn];
// f[i][j][k]表示放到了第$i$行，有$j$列是一个旗子，有$k$列是两个棋子

template<typename T>
inline void inc(T &a, T b)
{
	a = (long long)(a + b) % mod;
}

inline long long C(int val)
{
	return val * (val - 1) / 2;
}

inline void solve()
{
	cin >> n >> m;
	
	f[0][0][0] = 1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j <= m; ++j)
			for (int k = 0; j + k <= m; ++k)
			{
				long long last = m - j - k;
				// 一个都不放
				inc(f[i + 1][j][k], f[i][j][k]);
				// 放一个在空列
				if(last > 0) inc(f[i + 1][j + 1][k], f[i][j][k] * last);
				// 放一个在有一个棋子的列
				if(j > 0) inc(f[i + 1][j - 1][k + 1], f[i][j][k] * j);
				// 放两个在空列
				if(last > 1) inc(f[i + 1][j + 2][k], f[i][j][k] * C(last));
				// 放一个在有一个棋子的列，放一个在没有棋子的列
				if(j > 0 && last > 0) inc(f[i + 1][j][k + 1], f[i][j][k] * last * j);
				// 放两个在有一个棋子的列
				if(j > 1) inc(f[i + 1][j - 2][k + 2], f[i][j][k] * C(j)); 
			}

	long long ans = 0;
	for (int j = 0; j <= m; ++j)
		for (int k = 0; j + k <= m; ++k)
				ans = (ans + f[n][j][k]) % mod;

	cout << ans << endl;
}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	AHOI2009::solve();
	return 0;
}
```

## [NOIP2017D2T3]逛公园
### 说明
蜜汁难调，状态转移也不是很好想...想出来要写WA，WA改好了之后又蜜汁RE。状态转移是：$f[i][j]$为到了点i，比正常最短路多$j$。
### 代码
```cpp
// by kririae
// dp
// vector ver
#include <bits/stdc++.h>

using namespace std;

namespace IO
{
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
	for (x = 0; isdigit(c); c = read()) 
		x = (x + (x << 2) << 1) + (c ^ '0');
	iosig ? x = -x : 0;
}
}

namespace NOIP2017D1T3
{
const int maxn = 120000 + 5;
const int maxk = 50 + 5;

struct Edge {
	int from, to, val;
	Edge() {}
	Edge(int f, int t, int v) : from(f), to(t), val(v) {}
};

int t, n, m, k, p, ai, bi, ci, flag;
int dist[maxn], f[maxn][maxk];
vector<Edge> edges[maxn], redges[maxn];
bitset<maxn> vis, r[maxk];
deque<int> q;

template<typename T>
inline void inc(T &a, T b)
{
	a = (long long)(a + b) % p;
}

inline void addedge(int from, int to, int val)
{
	edges[from].push_back(Edge(from, to, val));
	redges[to].push_back(Edge(to, from, val));
}

inline void reSPFA()
{
	q.push_back(n); dist[n] = 0; vis[n] = 1;

	while(!q.empty())
	{
		int curr = q.front(); q.pop_front(); vis[curr] = 0;

		for (int i = 0; i < redges[curr].size(); ++i)
		{
			Edge &e = redges[curr][i];
			if(dist[curr] + e.val < dist[e.to])
			{
				dist[e.to] = dist[curr] + e.val;
				if(!vis[e.to]) vis[e.to] = 1, q.push_back(e.to);
			}
		}
	}
}

inline int dp(int curr, int val)
{	
	if(r[val][curr]) return flag = 1, 0;
	if(f[curr][val]) return f[curr][val];
	
	r[val][curr] = 1;
	
	int sum = 0;
	for (int i = 0; i < edges[curr].size(); ++i)
	{
		Edge &e = edges[curr][i];
		int sub = val - (dist[e.to] - dist[e.from] + e.val);
		if(sub >= 0 && sub <= k)
			inc(sum, dp(e.to, sub));
	}
	
	r[val][curr] = 0;
	
	return f[curr][val] = (curr == n && val == 0) ? 1 : sum;
}

inline void init()
{
	memset(f, 0, sizeof(f));
	for (int i = 0; i < maxn; ++i)
		edges[i].clear(), redges[i].clear();
	vis.reset();
	memset(dist, 0x3f, sizeof(dist));
	flag = 0;
	q.clear();
}

inline void solve()
{
	freopen("park.in", "r", stdin);
	using namespace IO;
	read(t);
	while(t--)
	{
		init();
		read(n), read(m), read(k), read(p);
		for (int i = 1; i <= m; ++i)
			read(ai), read(bi), read(ci), addedge(ai, bi, ci);
		
		reSPFA();
		
		int ans = 0;
		for (int i = 0; i <= k; ++i)
		{
			for (int j = 0; j <= k; ++j)
				r[j].reset();
			inc(ans, dp(1, i));
		}
				
		cerr << (flag ? -1 : ans) << endl;
	}
}
}

int main()
{
	NOIP2017D1T3::solve();
	return 0;
}
```