#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
struct AC_Automaton {
int son[N][30], f[N], cnt[N], tot;
inline void Insert(char s[]) {
  int l = strlen(s + 1);
  int u = 0;
  for (int i = 1; i <= l; ++i) {
    if (!son[u][s[i] - 'a'])
      son[u][s[i] - 'a'] = ++tot;
    u = son[u][s[i] - 'a'];
  }
  ++cnt[u];
}
inline void Bfs() {
  static queue<int> q;
  while (!q.empty()) q.pop();
  for (int i = 0; i < 30; ++i) 
    if (son[0][i])
      q.push(son[0][i]);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < 30; ++i)
      if (son[u][i]) 
        f[son[u][i]] = son[f[u]][i],
        q.push(son[u][i]);
      else
        son[u][i] = son[f[u]][i]; 
  }
}
inline int Match(char t[]) {
  int l = strlen(t + 1);
  int u = 0, ans = 0;
  for (int i = 1; i <= l; ++i) {
    u = son[u][t[i] - 'a'];
    for (int j = u; j && ~cnt[j]; j = f[j]) 
      ans += cnt[j],
      cnt[j] = -1;
  }
  return ans;
}
} AC;
int n; char s[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s + 1);
    AC.Insert(s);
  }
  AC.Bfs(); 
  scanf("%s", s + 1);
  cout << AC.Match(s) << endl;
}