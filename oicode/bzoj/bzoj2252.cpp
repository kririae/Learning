#include <bits/stdc++.h>
using namespace std;

namespace kririae
{
const int maxn = 1005;
bitset<maxn> a[maxn];
int b[maxn][maxn];
char ch[maxn];
int n, m; 
queue<pair<int, int> > q;
const int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};

inline void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> (ch + 1);
        for (int j = 1; j <= m; ++j)
            a[i][j] = ch[j] == '1' ? 1 : 0, b[i][j] = -1;
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) if(a[i][j]) 
            q.push(make_pair(i, j)), b[i][j] = 0;
    while(!q.empty())
    {
        pair<int, int> curr = q.front(); q.pop();
        for (int i = 0; i < 4; ++i)
        {
            pair<int, int> next(curr.first + dx[i], curr.second + dy[i]);
            if(next.first < 1 || next.second < 1 || next.first > n || next.second > m) continue;
            if(b[next.first][next.second] == -1)
            {
                b[next.first][next.second] = b[curr.first][curr.second] + 1;
                q.push(next);
            }
        }
    }
    for (int i = 1; i <= n; ++i) 
    {
        for (int j = 1; j <= m; ++j) cout << b[i][j] << " ";
        cout << endl;
    }
}
}
// 3 4 
// 0001 
// 0011 
// 0110 
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    kririae::solve();
    return 0;
}