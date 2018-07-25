// luogu-judger-enable-o2
// by kririae
// IDA*
#include <bits/stdc++.h>

using namespace std;

namespace BZOJ1085
{
const int dest[5][5] = {{1, 1, 1, 1, 1},
            {0, 1, 1, 1, 1},
            {0, 0, 2, 1, 1},
            {0, 0, 0, 0, 1},
            {0, 0, 0, 0, 0},};
const int _to_x[] = {1, -1, 1, -1, 2, -2, 2, -2};
const int _to_y[] = {2,  2,-2, -2, 1,  1,-1, -1};

int flag, t, a[10][10];

inline int g()
{
  int cnt = 0;
  for (int i = 0; i < 5; ++i)
    for (int j = 0; j < 5; ++j)
      if(a[i][j] != dest[i][j]) ++cnt;
  return cnt;
}

inline void IDAstar(int x, int y, int limit_layer, int current_layer)
{
  // if(g() + current_layer > limit_layer + 1) return;
  // cout << x << " " << y << endl;
  if(limit_layer == current_layer)
  {
    if(g() == 0) flag = 1;
    return;
  }
  if(flag == 1) return;
  for (int i = 0; i < 8; ++i)
  {
    int to_x = x + _to_x[i], to_y = y + _to_y[i];
    if(to_x >= 0 && to_y <= 4 && to_y >= 0 && to_y <= 4)
    {
      swap(a[x][y], a[to_x][to_y]);
      if(g() + current_layer > limit_layer) IDAstar(to_x, to_y, limit_layer, current_layer + 1);
      swap(a[x][y], a[to_x][to_y]);
    }
  }
}

inline void solve()
{
    scanf("%d", &t);
  while(t--)
  {
    memset(a, 0, sizeof(a));
    flag = 0;
    char s[10];
    int empty_position_x, empty_position_y;
    for (int i = 0; i < 5; ++i)
    {
      scanf("%s", s);
      for (int j = 0; j < 5; ++j)
      {
        if(s[j] == '0') a[i][j] = 0;
        if(s[j] == '1') a[i][j] = 1;
        if(s[j] == '*') a[i][j] = 2, 
                        empty_position_x = i, 
                        empty_position_y = j;
      }
    }
    for (int layer = 1; layer <= 15; ++layer)
    {
      IDAstar(empty_position_x, empty_position_y, layer, 0);
      if(flag == 1)
      {
        printf("%d\n", layer);
        break;
      }
    }
    if(!flag) puts("-1");
  }
}
}

int main()
{
  return BZOJ1085::solve(), 0;
}