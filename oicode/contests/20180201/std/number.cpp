#include<bits/stdc++.h>
using namespace std;

const int N = 1009;
const int MOD = 1000000007;

int f[N];

inline int read() {
    int ret = 0, f = 1; char c = getchar();
    while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
    while (c <= '9' && c >= '0') {ret = ret * 10 + c - '0'; c = getchar();}
    return ret * f;
}

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    f[0] = 1;
    for (int i = 1; i < N; i += 2) {
        for (int j = i; j <= N; j++) {
            f[j] = (f[j] + f[j - i]) % MOD;
        } 
    }
    for (int T = read(); T; T--) {
        cout<<f[read()]<<endl;
    }
    return 0;
}