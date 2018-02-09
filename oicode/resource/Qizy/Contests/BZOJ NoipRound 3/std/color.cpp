#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
typedef long long ll;
const int N=105,mod=998244353;
int c[N][N],s[N][N],f[N][N];
struct mat{
    int a[N][N];
}ans,tmp;
int p;
mat operator*(mat a,mat b){
    int i,j,k;mat c;
    for(i=1;i<=p;i++)
        for(j=1;j<=p;j++){
            c.a[i][j]=0;
            for(k=1;k<=p;k++) c.a[i][j]=(c.a[i][j]+(ll)a.a[i][k]*b.a[k][j])%mod;
        }
    return c;
}
int ksm(int x,int y){
    int tmp=x,ans=1;
    while(y){
        if(y&1) ans=(ll)ans*tmp%mod;
        tmp=(ll)tmp*tmp%mod;
        y>>=1;
    }
    return ans;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int n,m,q,i,j,k,x,sum=0;
    scanf("%d %d %d %d %d",&n,&m,&p,&q);
    c[0][0]=1;
    for(i=1;i<=p;i++){
        c[i][0]=c[i][i]=1;
        for(j=1;j<i;j++)
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
    }
    f[0][0]=1;
    for(i=1;i<=n;i++)
        for(j=1;j<=p;j++)
            f[i][j]=((ll)f[i-1][j-1]*(p-j+1)+(ll)f[i-1][j]*j)%mod;
    for(j=1;j<=p;j++)
        for(k=1;k<=p;k++){
            for(x=max(q,max(j,k));x<=p;x++)
                tmp.a[j][k]=(tmp.a[j][k]+(ll)c[j][j+k-x]*c[p-j][x-j])%mod;
            tmp.a[j][k]=(ll)f[n][k]*tmp.a[j][k]%mod*ksm(c[p][k],mod-2)%mod;
          //  printf("%d ",tmp.a[j][k]);
        }
    m--;
    for(i=1;i<=p;i++) ans.a[i][i]=1;
    while(m){
        if(m&1) ans=ans*tmp;
        tmp=tmp*tmp;m>>=1;
    }
    for(i=1;i<=p;i++)
        for(j=1;j<=p;j++)
            sum=(sum+(ll)f[n][i]*ans.a[i][j])%mod;
    printf("%d\n",sum);
    return 0;
}
