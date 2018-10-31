#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Card {
  int fg, x, y;
  // fg -> t
} a[10], b[10];
int w, n, ans, cnt, wea[4], vis[10];
int my_point, enemy_point;
vector<Card> status[10];  // 每一行的牌的情况
// vis表示当前自己已经出的牌
/*
inline void dfs(int x, int my_point, int enemy_point) {
  // x表示自己已经出的牌数
  // (别忘了考虑先手后手的问题)
  if (x == n + 1) {
    if (my_point - enemy_point >= ans)
      if (my_point - enemy_point == ans)
        ++cnt;
      else
        ans = my_point - enemy_point, cnt = 1;
    return;
  }
  vector<int> use;
  vector<Card> use1;
  if (w == 1) {
    if (a[x].fg == 1) {
      if (wea[a[x].y]) {
        status[a[x].y].push_back(a[x]);
        ++enemy_point;
        goto collection01;
      } else {
        status[a[x].y].push_back(a[x]);
        enemy_point += a[x].x;
        goto collection01;
      }
    } else if (a[x].fg == 2) {
      if (!wea[a[x].x]) {
        wea[a[x].x] = 1;
        ll sum_m = 0, sum_e = 0;
        for (int i = 0; i < status[a[x].x].size(); ++i)
          sum_m += status[a[x].x][i].x, ++enemy_point;
        for (int i = 0; i < status[a[x].x - 3].size(); ++i)
          sum_e += status[a[x].x - 3][i].x, ++my_point;
        enemy_point -= sum_m;
        my_point -= sum_e;
        goto collection02;
      }
    }
  } else if (a[x].fg == 3) {
    ll sum_m = 0, sum_e = 0;
    for (int j = 1; j <= 3; ++j)
      // 去除这一行的天气影响
      if (wea[j]) {
        use.push_back(j);
        wea[j] = 0;
        for (int i = 0; i < status[j].size(); ++i)
          sum_m += status[j][i].x;
        my_point -= status[j].size();
        my_point += sum_m;
        for (int i = 0; i < status[j + 3].size(); ++i)
          sum_e += status[j][i].x;
        enemy_point -= status[j + 3].size();
        enemy_point += sum_e;
      }
    goto collection03;
  } else if (a[x].fg == 4) {
    int mx = 0;
    for (int j = 1; j <= 6; ++j)
      if (!wea[j])
        for (int k = 0; k < status[j].size(); ++k)
          if (mx <= status[j][k].x)
            if (mx == status[j][k].x)
              use1.push_back(status[j][k]);
            else {
              mx = status[j][k].x;
              use1.clear();
            }
    for (int j = 0; j < use1.size(); ++j) {
      status[use1[j].y].erase(find(status[use1[j].y].begin(), status[use1[j].y].end(), use1[j]));
      if (use1[j].y >= 1 && use1[j].y <= 3)
        my_point -= use1[j].x;
      else
        enemy_point -= use1[j].x;
    }
    goto collection04;
  }
  for (int i = 1; i <= n; ++i)
    if (!vis[i]) {
      // 枚举这次我要出的牌
      Card u = b[i];
      vis[i] = 1;
      // 对手的出牌情况
      if (u.fg == 1) {
        if (wea[u.y]) {
          status[u.y].push_back(u);
          ++my_point;
          dfs(x + 1, my_point, enemy_point);
          status[u.y].erase(find(status[u.y].begin(), status[u.y].end(), u));
        } else {
          status[u.y].push_back(u);
          my_point += u.x;
          dfs(x + 1, my_point, enemy_point);
          status[u.y].erase(find(status[u.y].begin(), status[u.y].end(), u));
        }
      } else if (u.fg == 2) {
        if (wea[u.x])
          dfs(x + 1, my_point, enemy_point);
        else {
          wea[u.x] = 1;
          ll sum_m = 0, sum_e = 0;
          for (int i = 0; i < status[u.x].size(); ++i)
            sum_m += status[u.x][i].x, ++my_point;
          for (int i = 0; i < status[u.x + 3].size(); ++i)
            sum_e += status[u.x + 3][i].x, ++enemy_point;
          my_point -= sum_m;
          enemy_point -= sum_e;
          dfs(x + 1, my_point, enemy_point);
          wea[u.x] = 0;
        }
      } else if (u.fg == 3) {
        vector<int> use;
        ll sum_m = 0, sum_e = 0;
        for (int j = 1; j <= 3; ++j)
          // 去除这一行的天气影响
          if (wea[j]) {
            use.push_back(j);
            wea[j] = 0;
            for (int i = 0; i < status[j].size(); ++i)
              sum_m += status[j][i].x;
            my_point -= status[j].size();
            my_point += sum_m;
            for (int i = 0; i < status[j + 3].size(); ++i)
              sum_e += status[j][i].x;
            enemy_point -= status[j + 3].size();
            enemy_point += sum_e;
          }
        dfs(x + 1, my_point, enemy_point);
        for (int j = 0; j < use.size(); ++j) wea[use[j]] = 1;
      } else if (u.fg == 4) {
        vector<Card> use;
        int mx = 0;
        for (int j = 1; j <= 6; ++j)
          if (!wea[j])
            for (int k = 0; k < status[j].size(); ++k)
              if (mx <= status[j][k].x)
                if (mx == status[j][k].x)
                  use.push_back(status[j][k]);
                else {
                  mx = status[j][k].x;
                  use.clear();
                }
        for (int j = 0; j < use.size(); ++j) {
          status[use[j].y].erase(find(status[use[j].y].begin(), status[use[j].y].end(), use[j]));
          if (use[j].y >= 1 && use[j].y <= 3)
            my_point -= use[j].x;
          else
            enemy_point -= use[j].x;
        }
        dfs(x + 1, my_point, enemy_point);
        for (int j = 0; j < use.size(); ++j)
          status[use[j].y].push_back(use[j]);
      } else if (u.fg == 5) {
        for (int j = 1; j <= 6; ++j)
          if (!wea[j]) {
            for (int k = 0; k < status[j].size(); ++k) {
              if (j >= 1 && j <= 3)
                my_point += status[j][k].x;
              else
                enemy_point += status[j][k].x;
              status[j][k].x += status[j][k].x;
            }
            dfs(x + 1, my_point, enemy_point);
            for (int k = 0; k < status[j].size(); ++k)
              status[j][k].x /= 2;
          }
      }
    }
collection01:
  status[a[x].y].erase(find(status[a[x].y].begin(), status[a[x].y].end(), a[x]));
  return;
collection02:
  wea[a[x].x] = 0;
  return;
collection03:
  for (int j = 0; j < use.size(); ++j) wea[use[j]] = 1;
  return;
collection04:
  for (int j = 0; j < use1.size(); ++j) wea[use1[j].x] = 1;
  return;
}
*/
int main() {
  freopen("gwent.in", "r", stdin);
  freopen("gwent.out", "w", stdout);
  scanf("%d%d", &w, &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i].fg);
    if (a[i].fg == 1)
      scanf("%d%d", &a[i].x, &a[i].y),
          a[i].y += 3;
    else if (a[i].fg == 2)
      scanf("%d", &a[i].x);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &b[i].fg);
    if (b[i].fg == 1)
      scanf("%d%d", &b[i].x, &b[i].y);
    else if (b[i].fg == 2)
      scanf("%d", &b[i].x);
  }
  // dfs(1, 0, 0);
  cout << ans << " " << cnt;
}
