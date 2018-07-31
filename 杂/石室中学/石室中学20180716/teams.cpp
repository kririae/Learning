/*
???¡¤¨º??¨®21¨ª?
?¨®¨ª¨º21¨ª???o¨®?¨¹?t¡¤?¨ª?~
¦Ì?¨º?o¨®??¨®|??¨®D¨°???dp...
¨¤¡ä2??¡ãD¡ädp?¨ªD¡ä¨¬¡ãD?¡ê¡§?¡À?
¡ã?¡ã?¡ã?o?D?¨¤?
QAQ我凉了
 */
#define R register
#define ll long long
#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;

int n, val, g[maxn][maxn], g2[maxn][maxn], col[maxn], cnt1, cnt2, ans = 1e9;
bitset<maxn> vis;
queue<int> q;

inline int color(int s)
{
  while(!q.empty()) q.pop();
  vis[s] = 1, q.push(s), col[s] = 1;
  while(!q.empty())
  {
    int curr = q.front(); q.pop();
    if(col[curr] == 1) ++cnt1;
    else ++cnt2;
    for (R int i = 1; i <= n; ++i)
    {
      if(g2[curr][i])
      {
        if(!vis[i])
          col[i] = 1 - col[curr], vis[i] = 1, q.push(i);
        else 
          if(col[curr] == col[i]) return -1;
      }
    }
  }
  return abs(cnt1 - cnt2);
}

int t;

int main()
{
  freopen("teams.in", "r", stdin);
  freopen("teams.out", "w", stdout);
  cin >> t;
  while(t--)
  {
  memset(g, 0, sizeof(g));
  memset(g2, 0, sizeof(g2));
  memset(col, 0x3f, sizeof(col));
  cnt1 = 0, cnt2 = 0;
  vis.reset();
  int flag = 0;
  cin >> n;
  for (R int i = 1; i <= n; ++i)
  {
    for (; ; )
    {
      cin >> val;
      if(val == 0) break;
      g[i][val] = 1;
    }
  }
  for (R int i = 1; i <= n; ++i)
    for (R int j = 1; j <= n; ++j)
    if(g[i][j] == 0 && i != j) g2[i][j] = 1;
  // ?¨®21¨ª?¡ê??¨´?Y?a¦Ì¨¤¨¬a¦Ì?D??¨º¡ê?21¨ª??D?¨¤¨¢¨²¦Ì?¦Ì?¨°??¡§2??¨²¨°???¡Á¨¦?D
  for (R int i = 1; i <= n; ++i)
    if(!vis[i]) color(i);
  for (R int i = 1; i <= n; ++i)
    if(!vis[i]) cout << -1 << endl, i = n + 1, flag = 1;
  // ?a¨º??1D¡ä~
  if(!flag)
  {
    for (R int i = 1; i <= n; ++i)
    {
      int fl = 1;
      for (R int j = 1; j <= n; ++j)
      if(g2[i][j]) fl = 0;
      if(fl && cnt1 > cnt2)
        --cnt1, ans = min(ans, abs(cnt1 - cnt2));
      if(fl && cnt2 > cnt1)
        --cnt2, ans = min(ans, abs(cnt1 - cnt2));
    }
  }
  if(!flag) cout << ans << endl;
  }
}