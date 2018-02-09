#include<bits/stdc++.h>
#define LL long long
using namespace std;
 
const int MOD = 1000000007;
 
int f[2][200+9][1000+9],n,arr[1000+9],w,p,k,cnt[500+9],tot,que[1000+9];
 
inline int read(){
    char c=getchar(); int ret=0,f=1;
    while (c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
    while (c<='9'&&c>='0') {ret=ret*10+c-'0';c=getchar();}
    return ret*f;
}
 
int main() {
    n = read(); k = read(); w = 1, p = 0;
    for (int i=1;i<=n;i++) cnt[arr[i]=read()]++;
    for (int i=1;i<=500;i++) {
        if (cnt[i]) {
            que[++tot] = i; 
            cnt[tot] = cnt[i];
        }
    }
    que[0] = que[1];
     
    f[p][0][k] = 1;
    for (int i=1,delta;i<=tot;i++) {
        memset(f[w],0,sizeof(f[w]));
        delta = que[i] - que[i-1];
        for (int j=0;j<=n;j++) {
            for (int t=j*delta;t<=k;t++) {
                f[w][j][t-j*delta] += f[p][j][t];
            }
        }
        swap(w, p);
         
        for (int x=1;x<=cnt[i];x++,w^=1,p^=1) {
            memset(f[w],0,sizeof(f[w]));    
            for (int j=0;j<=n;j++) {
                for (int t=0;t<=k;t++) {
                    if (f[p][j][t]) {
                        LL tmp = f[p][j][t];
                        (f[w][j][t] += tmp * (j + 1) % MOD) %= MOD;
                        if (j) (f[w][j-1][t] += tmp * j % MOD) %= MOD;
                        (f[w][j+1][t] += tmp) %= MOD;               
                    }
                }
            }
        }
    }
    int ret = 0;
    for (int i=0;i<=k;i++) 
        ret = (ret + f[p][0][i]) % MOD;
    printf("%d\n",ret);
    return 0;
}
