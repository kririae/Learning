/*
f[i]表示在i建立工厂
枚举上一个工厂的位置
然后手推一下
*/
#include<cstdio>
#include<iostream>
#define N 1000005
#define LL long long
using namespace std;
int di[N],pi[N],ci[N];
int que[N];
LL dp[N];
LL t[N],sum[N];
int head,tail,n;
inline double getangle(int a,int b){
    return ((dp[a]-t[a+1]+sum[a]*di[a+1])-(dp[b]-t[b+1]+sum[b]*di[b+1]))/(double)(sum[a]-sum[b]);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&di[i],&sum[i],&ci[i]);
    }
    for(int i=1;i<=n;i++) sum[i]+=sum[i-1];
    for(int i=1;i<=n;i++) t[i]=t[i-1]+sum[i-1]*(di[i]-di[i-1]);
    for(int i=1;i<=n;i++){
        while(tail<head&&(getangle(que[tail],que[tail+1])<di[i])) tail++;
        int j=que[tail];
		dp[i]=ci[i]+t[i]+dp[j]-t[j+1]-sum[j]*(di[i]-di[j+1]);
        while(tail<head&&(getangle(que[head],que[head-1])>getangle(que[head],i))) head--;
        que[++head]=i;
    }
    printf("%lld",dp[n]);
    return 0;
}
