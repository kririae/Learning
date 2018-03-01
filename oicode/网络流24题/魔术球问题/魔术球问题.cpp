#include <bits/stdc++.h>
using namespace std;

int n, cnt;
vector<int> res[100];

inline bool can_sqrt(int t)
{
    return (int)sqrt(t) == sqrt(t);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; ; ++i)
    {
        bool flag = false;
        for (int j = 1; j <= n; ++j)
        {
            if(res[j].size() == 0 || can_sqrt(res[j][res[j].size() - 1] + i)) {
                res[j].push_back(i);
                flag = true;
                break;
            }
        }
        if(flag) ++cnt;
        else break;
    }
    cout << cnt << endl;
    for (int i = 1; i <= n; ++i) 
    {
        for (int j = 0; j < res[i].size(); ++j) 
            cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}