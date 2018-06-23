#define ll long long
#include <bits/stdc++.h>
 
using namespace std;
 
int cnt;
ll m, ans;
 
int main()
{
    cin >> m;
    while(ans + (1 << cnt) <= m)
        ans += (1 << cnt), ++cnt;
    cout << (m - ans ? cnt + 1: cnt) << endl;
}