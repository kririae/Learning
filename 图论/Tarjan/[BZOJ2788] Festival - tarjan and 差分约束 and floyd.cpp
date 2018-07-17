// by kririae
// q234rty 的常数是我的1/7...怎么做到的（（（
/*
这道题需要证明的地方有仨
第一个：差分约束的连边
这个相对比较简单，但是之前还是难了我好久（（（
x -> y (a)表示y - x = a
题中的y = x + 1 -> x -> y (1), y -> x (-1)
题中的y >= x -> y -> x (0)
这里简单解释一下y >= x表示y不小于x
第二个，是SCC之间互不影响
首先来说吧，SCC缩完之后一定是一个DAG，所以不会形成依赖
第二点，需要感性理解~任意个SCC的总价值是可以抬高的（在不满足SCC之间的边限制的情况下
所以SCC之间互不影响
第三个，最难的，怎么计数
Po姐的证明如下 
http://blog.csdn.net/popoqqq/article/details/48249845
证明： 
由于边权只有{0,1,−1}三种，因此取值数=最大值-最小值+1 
不妨设最短路的最大值为ans，那么对于这个差分约束系统的任意一组解，我选择最小的数x和最大的数y，由于这个图强连通，因此x到y必然存在至少一条路径 
不妨设x−>y的最短路径长度为z，那么取值数−1=y−x≤z≤ans 
显然我们可以构造出一组解使得取值数−1=ans，故ans就是最大的取值数
EMMMMMMM
emmmmmmmmmmmmmmmm
 */
#define ll long long
#define R register
#include <bits/stdc++.h>

using namespace std;

const int maxn = 605;

namespace IO
{
inline char gc()
{
  static char buf[1 << 18], *fs, *ft;
  return (fs == ft && (ft = (fs = buf) + fread(buf, 1, 1 << 18, stdin)), fs == ft) ? EOF : *fs++;
}
inline int read()
{
  register int k = 0, f = 1;
  register char c = gc();
  for (; !isdigit(c); c = gc()) if (c == '-') f = -1;
  for (; isdigit(c); c = gc()) k = (k << 3) + (k << 1) + (c - '0');
  return k * f;
}
}

namespace BZOJ2788
{
vector<int> edges[maxn];
stack<int> s;
bitset<maxn> vis;
int n, m1, m2, f[maxn][maxn], cnt;
int dfn[maxn], low[maxn], tot, cnt2;
vector<int> belong[maxn];

inline void addedge(R int from, R int to, R int val)
{
  edges[from].push_back(to);
  f[from][to] = min(f[from][to], val);
}

inline void tarjan(R int x)
{
  // 打板子~
  dfn[x] = low[x] = ++cnt;
  s.push(x);
  vis[x] = 1;
  for (R int i = 0; i < edges[x].size(); ++i)
  {
    R int to = edges[x][i];
    if(!dfn[to]) 
      tarjan(to), low[x] = min(low[x], low[to]);
    else if (vis[to]) low[x] = min(low[x], dfn[to]);
  }
  if(dfn[x] == low[x])
  {
    R int curr;
    ++tot;
    do {
      curr = s.top(), s.pop(), vis[curr] = 0;
      belong[tot].push_back(curr);
    } while(curr != x);
  }
}
inline void solve()
{
  using namespace IO;
  memset(f, 0x3f, sizeof(f));
  n = read(), m1 = read(), m2 = read();
  R int x, y;
  for (R int i = 1; i <= m1; ++i)
  {
    x = read(), y = read();
    addedge(x, y, 1), addedge(y, x, -1);
  }
  for (R int i = 1; i <= m2; ++i)
  {
    x = read(), y = read();
    addedge(y, x, 0);
  }
  R int i, j, k;
  // Po姐这个写法挺不错的，利用floyd避免后面的计算
  for (k = 1; k <= n; ++k)
    for (i = 1; i <= n; ++i)
      if(f[i][k] <= n)
        for (j = 1; j <= n; ++j)
          f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
  for (R int i = 1; i <= n; ++i)
    if(f[i][i] < 0) return puts("NIE"), void();
  for (R int i = 1; i <= n; ++i)
    if(!dfn[i]) tarjan(i); // 进行tarjan
  int ans = 0, res = 0;
  for (i = 1; i <= tot; ++i)
  {
    ans = 0;
    for (j = 0; j < belong[i].size(); ++j)
      for (k = 0; k < belong[i].size(); ++k)
        if(f[belong[i][j]][belong[i][k]] <= 1e9)
          ans = max(ans, f[belong[i][j]][belong[i][k]]);
    res += (ans + 1);
  }
  printf("%d\n", res);
}
}

int main()
{
  return BZOJ2788::solve(), 0;
}