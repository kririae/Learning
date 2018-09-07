// 写不动了，对着题解的板子看的
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 10005;
int a[5] = {0, 1, 2, 5}, cnt[5], x[N], y[N], s;
int main() {
  while(cin >> cnt[1] >> cnt[2] >> cnt[3] 
  && cnt[1] && cnt[2] && cnt[3]) {
    memset(x, 0, sizeof(x));
    memset(y, 0, sizeof(y));
    s = 0;
    for (int i = 0; i <= cnt[1]; ++i) x[i] = 1;
    for (int i = 1; i <= 3; ++i) s += a[i] * cnt[i];
    for (int i = 2; i <= 3; ++i) {
      for (int j = 0; j <= s; ++j) {
        if(x[j] == 0) continue;
        for (int k = 0; k <= a[i] * cnt[i]; k += a[i])
          if(j + k <= s) y[j + k] += x[j];
      } 
      memcpy(x, y, sizeof(y));
      memset(y, 0, sizeof(y));
    }
    int i;
    for (i = 0; i <= s; ++i)
      if(x[i] == 0) break;
    printf("%d\n", i);
  }
}