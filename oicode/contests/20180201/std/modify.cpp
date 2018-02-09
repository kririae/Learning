#include<bits/stdc++.h>
#define LL long long
using namespace std;
 
const int N = 1009;
const int SGZ = 27;
 
int n,k;
char S[N],T[N];
queue<int> que;
 
inline int read(){
    char c=getchar(); int ret=0,f=1;
    while (c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
    while (c<='9'&&c>='0') {ret=ret*10+c-'0';c=getchar();}
    return ret*f;
}
 
inline bool judge(int len) {
    for (int d=0,cur=0,p1,p2,tmp;d<=n-len;d++,cur=0) {
        while (!que.empty()) que.pop(); que.push(0); p1 = 0, p2 = p1 + d;
        for (int i=1;i<len;i++) 
            tmp = (S[++p1] != T[++p2]), 
            cur += tmp, que.push(tmp);
        while (p2 < n) {
            tmp = (S[++p1] != T[++p2]);
            cur += tmp, cur -= que.front();
            que.pop(), que.push(tmp); 
            if (cur <= k) return true;
        }
    } 
    for (int d=0,cur=0,p1,p2,tmp;d<=n-len;d++,cur=0) {
        while (!que.empty()) que.pop(); que.push(0); p1 = 0, p2 = p1 + d;
        for (int i=1;i<len;i++) 
            tmp = (T[++p1] != S[++p2]), 
            cur += tmp, que.push(tmp);
        while (p2 < n) {
            tmp = (T[++p1] != S[++p2]);
            cur += tmp, cur -= que.front();
            que.pop(), que.push(tmp); 
            if (cur <= k) return true;
        }
    } 
    return false;
}
 
int main(){
    freopen("modify.in","r",stdin);
    freopen("modify.out","w",stdout);
    n = read(); k = read();
    scanf("%s%s",S+1,T+1);
    int l=1,r=n,ret=0;
    while (l <= r) {
        int mid = l + r >> 1;
        if (judge(mid)) ret = mid, l = mid+1;
        else r = mid-1;
    } 
    printf("%d\n",ret);
    return 0;
}