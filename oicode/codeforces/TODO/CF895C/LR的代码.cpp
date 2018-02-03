#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>

using namespace std;
typedef long long LL;
inline LL read(LL &x) {
    x = 0; char c = getchar();
    while(!isdigit(c)) c = getchar();
    while(isdigit(c)) x = x * 10 + c - '0', c = getchar();
}
const LL MOD = 1e9+7;
int prime[19] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
int s[73], cnt[73], powmod[100003], dp[73][(1 << 19)];
inline void fenjie(LL x) {
    int t = x;
    //cout<<x<<" ";
    for(int j = 0; j < 19; ++j) {
        //cout<<x<<" "<<prime[i]<<endl;
        while(t % prime[j] == 0) 
            s[x] ^= (1 << j), t /= prime[j]; // 分解当前状态到s[i]
    }
}
int main() {
    //freopen("pai.txt", "w", stdout);
    LL n; read(n);
    LL tmp;
    for(int i = 1; i <= 70; ++i) fenjie(i); // 和今天那道题很像（prime素数），把分解后的状态装在s数组里qwq
    //for(int i = 1; i <= 70; ++i) cout<<s[i]<<endl;
    for(int i = 1; i <= n; ++i) read(tmp), cnt[tmp]++; // 获取某一个数出现的次数...qwq
    powmod[0] = 1;
    for(int i = 1; i <= n; ++i) powmod[i] = ((1LL) * powmod[i - 1] * 2) % MOD;
    dp[0][0] = 1;
    for(int i = 1; i <= 70; ++i) {
        if(!cnt[i]) for(int j = 0; j < (1 << 19); ++j) dp[i][j] = dp[i - 1][j];
        else 
            for(int j = 0; j < (1 << 19); ++j) {
                dp[i][j ^ s[i]] = ((1LL)*dp[i][j ^ s[i]] + (1LL)*powmod[cnt[i] - 1] * dp[i - 1][j]) % MOD;
                dp[i][j] = ((1LL)*dp[i][j] + (1LL)*powmod[cnt[i] - 1] * dp[i - 1][j]) % MOD;
            }   
    }
    //cout<<dp[1][0]<<endl;
    cout<<(dp[70][0] - 1) % MOD<<endl; 
    return 0;
}
