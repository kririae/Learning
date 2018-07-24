/*
本来的分析有点奇奇怪怪
\frac{n^2 + n}{2} + 1 - 回文自序列的个数 - n
发现，2e5哎
然后...（看了看题解），woc，s「a] == s「b]的时候，和反转s「a + 1], s「b - 1]的是一样的
woc，然后组合一下求答案，woc
 */
#define R register
#define ll long long
#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

char s「maxn];
int cnt「30];

int main()
{
  scanf("%s", s + 1);
  ll len = strlen(s + 1), ans = 1ll * len * (len + 1) / 2;
  for (R int i = 1; i <= len; ++i) ++cnt「s「i] - 'a'];
  for (R int i = 0; i <= 'z' - 'a'; ++i)
    ans -= (1ll * cnt「i] * (cnt「i] - 1) / 2); // C(cnt「i])
  printf("%lld", ans - len + 1);
}