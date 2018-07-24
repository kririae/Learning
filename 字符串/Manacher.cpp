#define R register
#define ll long long
#include <bits/stdc++.h>

using namespace std;

const int maxn = 11000005;

int n, len1, len2, p[maxn  << 1], ans;
char a[maxn], s[maxn << 1];
int main()
{
    scanf("%s", a);
    len1 = strlen(a);
    s[0] = '$', s[1] = '#';
    for (int i = 0; i < len1; ++i)
        s[(i << 1) + 2] = a[i], s[(i << 1) + 3] = '#';
    len2 = (len1 << 1) + 2, s[len2] = '*';
    // manacher
    int id, mx; id = mx = 0;
    for (int i = 1; i < len2; ++i)
    {
        if(mx > i) p[i] = min(p[(id << 1) - i], mx - i);
        else p[i] = 1;
        for (; s[i + p[i]] == s[i - p[i]]; ++p[i]);
        if(p[i] + i > mx) mx = p[i] + i, id = i;
    }
    for (int i = 0; i < len2; ++i)
        ans = max(ans, p[i]);
    printf("%d\n", ans - 1);
}