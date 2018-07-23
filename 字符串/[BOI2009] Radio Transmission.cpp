#include <bits/stdc++.h>

using namespace std;
const int maxn = 1001005;

char a[maxn]; 
int n, nxt[maxn];

int main()
{
    scanf("%d", &n);
    scanf("%s", a + 1);
    for (int i = 2, j = 0; i <= n; ++i)
    {
        while(j > 0 && a[i] != a[j + 1]) j = nxt[j];
        if(a[i] == a[j + 1]) ++j;
        nxt[i] = j;
    }
    printf("%d\n", n - nxt[n]);
}