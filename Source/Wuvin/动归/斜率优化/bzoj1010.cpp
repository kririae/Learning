/*²Ö¿â½¨ÉèÈõ»¯°æ*/
#include<cstdio>
#include<iostream>
#define N 50005
#define LL long long
using namespace std;
LL dp[N];
LL t[N];
int que[N];
int head,tail,n,L;
double slope(int a,int b){
    return (dp[a]-dp[b]+(t[a]+L+1)*(t[a]+L+1)-(t[b]+L+1)*(t[b]+L+1))/(double)(2*(t[a]-t[b]));
}
int main(){
    scanf("%d%d",&n,&L);
    for(int i=1;i<=n;i++) scanf("%d",&t[i]);
    for(int i=1;i<=n;i++) t[i]+=t[i-1];
    for(int i=1;i<=n;i++) t[i]+=i;
    for(int i=1;i<=n;i++){
        while(head>tail&&(slope(que[tail],que[tail+1])<t[i])) tail++;
        LL j=que[tail];
        dp[i]=dp[j]+(t[i]-t[j]-L-1)*(t[i]-t[j]-L-1);
        while(head>tail&&(slope(que[head],que[head-1])>slope(que[head],i))) head--;
        que[++head]=i;
    }
    printf("%lld",dp[n]);
    return 0;
}
