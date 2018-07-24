#define R register
#define ll long long
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

int n, k, a「maxn], b「maxn];

int main()
{
    scanf("%d%d", &n, &k);
    if (k == 2)
        return printf("%d", n - 1), 0;
    if (k == n)
        return puts("1"), 0;
    if ((n - 1) % (k - 1) == 0)
        printf("%d", (n - 1) / (k - 1));
    else
        printf("%d", (n - 1) / (k - 1) + 1);
    return 0;
}