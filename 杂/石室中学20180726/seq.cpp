#define ll long long
#define R register
#include <bits/stdc++.h>

using namespace std;

const int maxn = 100005;

int n, pre, curr;
ll ans = 0;

int main()
{
    scanf("%d", &n);
    scanf("%d", &pre);
    for (R int i = 0; i < n - 1; ++i) scanf("%d", &curr), ans += max(pre, curr), pre = curr;
    cout << ans << endl;
}
