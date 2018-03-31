// status: WA
#include <bits/stdc++.h>

using namespace std;

namespace BZOJ1646
{
const int maxn = 100005;

struct node
{
    int pl, st;
    node() {}
    node(int t, int s): pl(t), st(s) {}
};

int f[maxn];
queue<node> q;

inline void solve()
{
    memset(f, 0, sizeof(f));
    int n, k;
    cin >> n >> k;
    f[n] = 0;
    q.push(node(n, 1));
    
    while(!q.empty())
    {
        node curr = q.front(); q.pop();
        if(f[k] != 0) { cout << f[k] - 1 << endl; return; }
        if(curr.pl + 1 <= 100000 && f[curr.pl + 1] == 0) {
            f[curr.pl + 1] = curr.st + 1;
            q.push(node(curr.pl + 1, curr.st + 1));
        }
        if(curr.pl - 1 >= 0 && f[curr.pl - 1] == 0) {
            f[curr.pl - 1] = curr.st + 1;
            q.push(node(curr.pl - 1, curr.st + 1));
        }
        if((curr.pl) << 1 <= 100000 && f[curr.pl << 1] == 0) {
            f[curr.pl << 1] = curr.st + 1;
            q.push(node(curr.pl << 1, curr.st + 1));
        }
    }
    // cout << f[k] << endl;
}
}

int main()
{
    BZOJ1646::solve();
    return 0;
}