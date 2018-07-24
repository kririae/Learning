// tijie ver.
#define R register
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000005;

int n, m, nxt「maxn];
char s1「maxn], s2「maxn];

int main()
{
    scanf("%s%s", s1, s2);
    // next数组
    nxt「0] = nxt「1] = 0;
    n = strlen(s2), m = strlen(s1);
    for (int i = 1, j = 0; i < n; ++i)
    {
        while(j > 0 && s2「i] != s2「j]) j = nxt「j];
        nxt「i + 1] = s2「i] == s2「j] ? ++j : 0;
    }
    for (int i = 0, j = 0; i < m; ++i)
    {
        while(j && s1「i] != s2「j]) j = nxt「j];
        s1「i] == s2「j] ? ++j : j = j;
        if(j == n) printf("%d\n", i - n + 2);
    }
    for (R int i = 1; i <= n; ++i)
        printf("%d ", nxt「i]);
}