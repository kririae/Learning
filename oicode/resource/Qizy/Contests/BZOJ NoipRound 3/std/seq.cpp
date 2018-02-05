#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int N=200010;
vector<int> b[N],c[N];
int a[N],s[N],r1[N],r2[N];
struct A{
    int l,r,s;
}t[N*40];
int cnt=0,n;
void update(int &x,int px,int l,int r,int v){
    x=++cnt;t[x]=t[px];t[x].s++;
    if(l==r) return;
    int M=l+r>>1;
    if(v<=M) update(t[x].l,t[px].l,l,M,v);
    else update(t[x].r,t[px].r,M+1,r,v);
}
int query(int x,int l,int r,int v){
    if(r<=v) return t[x].s;
    int M=l+r>>1;
    if(v<=M) return query(t[x].l,l,M,v);
    else return t[t[x].l].s+query(t[x].r,M+1,r,v);
}
int calc(int x,int y){
    return query(r1[x],1,n,y)-query(r2[x],1,n,y);
}
int main(){
    freopen("seq.in","r",stdin);
    freopen("seq.out","w",stdout);
    int l,r,z,i,j,m,q;
    long long ans=0,x,y;
    scanf("%d %d %d",&n,&m,&q);
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&l,&r,&z);
        b[l].push_back(z);
        if(r<n) c[r+1].push_back(z);
    }
    for(i=1;i<=n;i++){
        r1[i]=r1[i-1];
        r2[i]=r2[i-1];
        for(j=0;j<b[i].size();j++) update(r1[i],r1[i],1,n,b[i][j]);
        for(j=0;j<c[i].size();j++) update(r2[i],r2[i],1,n,c[i][j]);
    }
    for(i=1;i<=n;i++) ans+=s[i]=calc(i,a[i]);
    printf("%lld\n",ans);
    while(q--){
        scanf("%lld %lld\n",&x,&y);
        x^=ans;y^=ans;
        ans-=s[x];s[x]=calc(x,y);ans+=s[x];
        printf("%lld\n",ans);
    }
    return 0;
}
