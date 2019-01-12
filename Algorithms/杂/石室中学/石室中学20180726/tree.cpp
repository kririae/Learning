#define ll long long
#define R register
#include <bits/stdc++.h>

using namespace std;

const int maxn = 10005;

char s[maxn];
ll ans = 0;
int n, curr, a[maxn];

inline int solve()
{
    ++curr;
    if(s[curr] == 'X') return 1;
    if(s[curr] == 'A') return solve() + solve();
    if(s[curr] == 'B') return max(solve(), solve());
}

int main()
{
    scanf("%s", s + 1);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    sort(a + 1, a + 1 + n);
    int all = solve();
    for (int i = 0; i < all; ++i) ans += a[n - i];
    cout << ans << endl;
}