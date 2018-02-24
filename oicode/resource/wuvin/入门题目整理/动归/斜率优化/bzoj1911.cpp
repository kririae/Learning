/*
好像i的前缀单增，所以可以不用二分，直接维护队首队尾O(n)
本题维护上凸包
*/
#include<cstdio>
#include<iostream>
#define LL long long
#define N 1000005
using namespace std;
LL dp[N];
int que[N];
int head,tail;//[tail,head]默认加入原点坐标 
LL t[N];
int n,a,b,c;
inline double slope(int k,int j){
	return (dp[j]-dp[k]+a*t[j]*t[j]-a*t[k]*t[k]-b*t[j]+b*t[k])/(double)(t[j]-t[k]);
} 
int main(){
    scanf("%d%d%d%d",&n,&a,&b,&c);
    for(int i=1;i<=n;i++){
        scanf("%d",&t[i]);t[i]+=t[i-1];
    }
    head=tail=0;
    for(int i=1;i<=n;i++){
        while(tail<head&&(slope(que[tail],que[tail+1])>2*a*t[i])) tail++;
        int j=que[tail];
        dp[i]=dp[j]+a*(t[i]-t[j])*(t[i]-t[j])+b*(t[i]-t[j])+c;
        while(tail<head&&slope(que[head],que[head-1])<slope(que[head],i)) head--;
        que[++head]=i;
    }
    printf("%lld",dp[n]);
    return 0;
}
