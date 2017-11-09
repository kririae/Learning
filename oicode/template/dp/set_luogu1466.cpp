/*
* by kriaeth 2017/11/8 22:00
* set luogu1466
*/
#include <bits/stdc++.h>
using namespace std;
long long g[50000] = {0};
int main() {
    long long n, summ = 0, m;
    cin >> n;
    if(((n + 1) * n / 2) % 2) {
        cout << 0;
        return 0;
    }
    g[0] = 1;
    for(int i = 1; i <= n; ++i) {
        summ += i;
    }
    m = summ / 2;
    for(int i = 1; i <= n; ++i) {
        for(int j = m; j >= i; --j) {
            g[j] += g[j - i];
        }
    }
    cout << g[m] / 2; 
    return 0;
}