# 动态规划题目汇总

---

<!--more-->

## 优化策略汇总
TODO

## [luogu1273] 有线电视网
### 说明
一道比较普通的树形dp
树形dp套路挺深的...这道题可以概括一小半了。
有时间写点复杂点的树形dp。
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

## [POJ1742] Coins
### 说明
好蛇皮啊。
男人八题之一。
这题搞细节，贪心优化dp
我们发现$N$很小，所以优化的时候时间复杂度一定会带上$N$（大雾
如果仔细看英文会发现，本题关注的是可行性而不是最优解
蛇皮操作开始了，我们需要一个$g[maxn]$数组
$g[j]$表示用到放第i种硬币的时候，$f[j]$为1最少用多少枚$i$硬币。这样可以保证不超过$c[i]$
所以时间复杂度是$O(nm)$
### 代码
```cpp
// by kririae
#include <iostream>
#include <cstring>

using namespace std;

namespace Coins
{
const int maxn = 105;
const int maxm = 1e5 + 5;

int n, m, c[maxn], a[maxn], f[maxm], g[maxm];

inline void solve()
{
	while(cin >> n >> m && n && m)
	{
		memset(f, 0, sizeof(f));
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		for (int i = 1; i <= n; ++i)
			cin >> c[i];

		int ans = 0;
		f[0] = 1;
		for (int i = 1; i <= n; ++i)
		{
			memset(g, 0, sizeof(g));
			for (int j = a[i]; j <= m; ++j)
				// 如果f[j]没有被到达过，并且可以由f[j - a[i]]转移过来，并且当前硬币还可以用。
				// 喂喂喂这是dp套贪心套dp啊！
				if(!f[j] && f[j - a[i]] && g[j - a[i]] < c[i])	
					f[j] = 1, g[j] = g[j - a[i]] + 1, ++ans;
		}

		cout << ans << endl;
	}
}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	Coins::solve();
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

## [IOI1998] POLYGON
### 说明
一开始会觉得很简单，仔细一看
卧槽，两者一正一负，乘积不是更小么！
那么转移两个吧，转移一个最大值一个最小值。
$f[i][j][2]$中，$f[i][j][0]$表示合并$[i, j]$的最小值，$f[i][j][1]$表示合并$[i, j]$的最大花费。
转移自然也简单了，看代码吧，代码量不大。
### 代码
```cpp
// by kririae
#include <iostream>

using namespace std;

namespace IOI1998
{
const int maxn = 55;
int n;
int a[maxn << 2];
char op[maxn << 2];
int f[maxn << 2][maxn << 2][2];

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) 
    {
        cin >> op[i] >> a[i]; 
        op[i + n] = op[i];
        a[i + n] = a[i];
    }
    
    // for (int i = 1; i <= n << 1; ++i) cout << a[i] << " ";
    // cout << endl;
    // for (int i = 1; i <= n << 1; ++i) cout << op[i] << " ";
    
    for (int i = 1; i <= n << 1; ++i)
        for (int j = 1; j <= n << 1; ++j)
            f[i][j][0] = (1 << 31), f[i][j][1] = ~(1 << 31);
    for (int i = 1; i <= n << 1; ++i) f[i][i][0] = f[i][i][1] = a[i];
    
    for (int len = 2; len <= n << 1; ++len)
        for (int l = 1; l <= (n << 1) - len + 1; ++l)
        {
            int r = l + len - 1;
            for (int k = l; k < r; ++k)
            {
                if(op[k + 1] == 't')
                {
                    f[l][r][0] = max(f[l][r][0], f[l][k][0] + f[k + 1][r][0]);
                    f[l][r][1] = min(f[l][r][1], f[l][k][1] + f[k + 1][r][1]);
                }
                
                if(op[k + 1] == 'x')
                {
                    f[l][r][0] = max(f[l][r][0], max(f[l][k][0] * f[k + 1][r][0], f[l][k][1] * f[k + 1][r][1]));
                    f[l][r][1] = min(f[l][r][1], min(f[l][k][1] * f[k + 1][r][1],min(f[l][k][1] * f[k + 1][r][0], f[l][k][0] * f[k + 1][r][1])));
                }
            }
        }

    int res = (1 << 31);
    for (int i = 1; i <= n; ++i)
        res = max(res, f[i][i + n - 1][0]);
        
    cout << res << endl;
    
    for (int i = 1; i <= n; ++i)
        if(f[i][i + n - 1][0] == res) cout << i << " "; 
}
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    IOI1998::solve();
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

## [SCOI2005] 最大子矩阵
### 说明
### 代码
```cpp

```
## Prime 和 [NOI2015]寿司晚宴
> 分组背包
### 统一解释
这两道题利用一个共同的性质：
对于任意一个数$n$，$\sqrt{n}$以上的素因子只有一个。
首先对$\sqrt{n}$以下的数进行质因数分解，然后把剩下的一个数（一个素数）作为归类标准进行分组背包。
#### Prime
首先说Prime吧，Prime应该是由寿司晚宴改编的
### Prime
> 互质

这是一道dp神题(我发过
#### 题面
##### 互质
###### 题目描述
Shy有$n$个数，问这$n$个数里最多有几个数两两之间互质。
###### 输入
第一行一个整数$n$。
第二行$n$个数表示数组。
###### 输出
输出一个数表示答案。
###### 输入样例
```
5
1 2 3 4 5
```
###### 输出样例
```
4
```
###### 数据范围
对于$30\%$的数据，$1\leq n \leq10$;
对于$100\%$的数据，$1\leq n \leq1000$，$1 \leq 数字 \leq 1000$;
##### 数据
https://pan.baidu.com/s/1B7FTs6mhBDaD1CUOxRaN1w
vhkq
#### 代码
```cpp
#include <bits/stdc++.h>

using namespace std;

namespace Prime
{
const int maxn = 1005;

int t, n, val, f[1 << 11], g[1 << 11];
bitset<maxn> vis;
vector<int> p, s[maxn];

inline void solve()
{
	cin >> n;
	
	for (int i = 2; i <= sqrt(maxn); ++i)
	{
		if(!vis[i]) p.push_back(i);
		for (int j = (i << 1); j <= sqrt(maxn); j += i)
			vis[j] = 1;
	}	
	
	t = 1 << p.size();
	
	for (int i = 1; i <= n; ++i)
	{
		cin >> val;
		
		int S = 0;
		for (int j = 0; j < p.size(); ++j)
			while(val % p[j] == 0) S |= (1 << j), val /= p[j];
		if(val > 33) s[val].push_back(S);
		else for (int j = 0; j < t; ++j)
				if((j & S) == 0) f[j | S] = max(f[j | S], f[j] + 1);
	}
	
	for (int i = 0; i <= 1000; ++i)
	{
		if(!s[i].size()) continue;
		memcpy(g, f, sizeof(f));
		for (int k = 0; k < s[i].size(); ++k)
			for (int j = 0; j < t; ++j)
				if((j & s[i][k]) == 0) g[j | s[i][k]] = max(g[j | s[i][k]], f[j] + 1);
		swap(g, f);
	}
	
	cout << f[t - 1] << endl;
}	
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);	
	Prime::solve();
	return 0;
}
```

### [NOI2015] 寿司晚宴
#### 代码
```cpp
// by kririae
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

namespace SSWY
{
const int maxn = 505;

int n, t, ans, f[1 << 8][1 << 8], g[2][1 << 8][1 << 8];
// f[S_1][S_2]表示两个人选择的质因子的集合是？
// G[S_1][S_2][0/1]表示 
long long P;
bitset<maxn> vis;
vector<int> p, s[maxn];

template<typename T>
inline void inc(T &a, T b)
{
	a = (long long)(a + b) % P;
}

inline void solve()
{
	register int s1, s2;
	cin >> n >> P;
	
	for (int i = 2; i <= sqrt(500); ++i)
	{
		if(!vis[i]) p.push_back(i);
		for (int j = (i << 1); j <= sqrt(500); j += i)
			vis[j] = 1;
	}	
	t = 1 << p.size();	

	f[0][0] = 1;
	
	for (int i = 1; i < n; ++i)
	{
		int val = i + 1, S = 0;
		for (int j = 0; j < p.size(); ++j)
			while(val % p[j] == 0) S |= (1 << j), val /= p[j];
		s[val].push_back(S);  
	}
	
	for (int i = 0; i < s[1].size(); ++i)
	{
		for (s1 = t - 1; s1 >= 0; --s1)
			for (s2 = t - 1; s2 >= 0; --s2)
				inc(f[s1 | s[1][i]][s2], f[s1][s2]),
				inc(f[s1][s2 | s[1][i]], f[s1][s2]);
	}

	for (int i = 2; i <= 500; ++i)
	{
		if(!s[i].size()) continue;
		memcpy(g[0], f, sizeof(f));
		memcpy(g[1], f, sizeof(f));
		
		for (int j = 0; j < s[i].size(); ++j)
		{
			int S = s[i][j];
			for (s1 = t - 1; s1 >= 0; --s1)
				for (s2 = t - 1; s2 >= 0; --s2)
				{
					// 如果选取当前的数，加入S1集合之后不冲突，那么可以加入S1集合，这个时候是小G选择 
					if((S & s2) == 0) inc(g[0][s1 | S][s2], g[0][s1][s2]);
					// 如果加入S2集合不冲突，那么这时候是小W选择 
					if((S & s1) == 0) inc(g[1][s1][s2 | S], g[1][s1][s2]);
				}
		} 
		
		for (s1 = 0; s1 < t; ++s1)
			for (s2 = 0; s2 < t; ++s2)
				f[s1][s2] = ((g[0][s1][s2] + g[1][s1][s2] - f[s1][s2]) % P + P) % P;
	}
	
	for (s1 = 0; s1 < t; ++s1)
		for (s2 = 0; s2 < t; ++s2)
			if((s1 & s2) == 0) 
				inc(ans, f[s1][s2]);
	
	cout << ans << endl;
}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);	
	SSWY::solve();
	return 0;
}
```