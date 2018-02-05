#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
typedef double db;
typedef long long ll;
const int N=100010;
const db eps=1e-6;
db b[N],c[N];
int a[N];
ll ans=0;
int n;
void solve(int l,int r){
    if(l==r) return;
    int M=l+r>>1;
    solve(l,M);solve(M+1,r);
    int i=l,j=M+1,k=l-1;
    while(i<=M&&j<=r){
        if(b[i]<b[j]) c[++k]=b[i++];
        else c[++k]=b[j++],ans+=M-i+1;
    }
    while(i<=M) c[++k]=b[i++];
    while(j<=r) c[++k]=b[j++];
    for(i=l;i<=r;i++) b[i]=c[i];
}
ll calc(db x){
    b[0]=0;
    for(int i=1;i<=n;i++) b[i]=a[i]-x+b[i-1];
    ans=0;
    solve(0,n);
    return ans;
}
int main(){
    freopen("ave.in","r",stdin);
    freopen("ave.out","w",stdout);
    int mx=0,i;
    db lb,rb,mid;
    ll x;
    scanf("%d %lld",&n,&x);
    for(i=1;i<=n;i++) scanf("%d",&a[i]),mx=max(mx,a[i]);
    lb=0;rb=mx;
    while(rb-lb>eps){
        mid=(lb+rb)/2;
        if(calc(mid)<x) lb=mid;
        else rb=mid;
    }
    printf("%.4lf\n",lb);
    return 0;
}
