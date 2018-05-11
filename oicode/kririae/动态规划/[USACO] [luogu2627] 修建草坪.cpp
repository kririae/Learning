// by kririae
/*
为啥必须用手写的双端队列？？？
反正吸取教训了...有些时候不要STL...
 */
#include <bits/stdc++.h>

using namespace std;

namespace luogu2627
{
const int maxn = 100005;

int n, k;
long long e[maxn], f[maxn], sum;
pair<int, long long> pq[maxn];
int head = 0, tail = 0;

inline void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> e[i], sum += e[i];
    
    for (int i = 1; i <= n; ++i)
    {
        // first -> time, second -> val
        f[i] = pq[head].second + e[i];
        while(head <= tail && f[i] < pq[tail].second) --tail;
        while(pq[head].first < i - k) ++head;
        pq[++tail].first = i, pq[tail].second = f[i];
    }
    
    long long ans = 1e16;
    for (int i = n - k; i <= n; ++i)
        ans = min(ans, f[i]);

    cout << sum - ans<< endl;
}
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    luogu2627::solve();
    return 0;
}