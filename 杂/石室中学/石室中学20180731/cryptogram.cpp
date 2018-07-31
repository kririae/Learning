#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;

char s[maxn], t[maxn];
int cnt1[maxn], cnt2[maxn], cnt3[maxn], cnt4[maxn];
int main()
{
  freopen("cryptogram.in", "r", stdin);
  freopen("cryptogram.out", "w", stdout);
  scanf("%s%s", s + 1, t + 1);
  int len1 = strlen(s + 1), len2 = strlen(t + 1);
  if(len1 != len2) return puts("NO"), 0;
  for (int j = 1; j <= len1; ++j) ++cnt1[s[j] - 'A'];
  for (int j = 1; j <= len2; ++j) ++cnt2[t[j] - 'A'];
  for (char i = 0; i <= 30; ++i) ++cnt3[cnt1[i]];
  for (char i = 0; i <= 30; ++i) ++cnt4[cnt2[i]];
  for (int i = 0; i < 105; ++i) if(cnt3[i] != cnt4[i]) return puts("NO"), 0;
  puts("YES");
}