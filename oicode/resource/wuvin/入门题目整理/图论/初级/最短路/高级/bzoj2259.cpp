/*
看大家的做法那么玄乎，我还是来写一写O（nlogn）的DP吧
首先hzwer的做法是对的，多余的边不影响答案。
DP的话f[i]表示到i的最小值，绝对值要开括号分情况讨论
左侧贪心保留一个，右侧维护单调队列关键字分别为跳到的点（为下标）费用（值 单调增）
由于单调队列的插入不是单调的，所以有点麻烦
所以我不想写了
*/
#include<cstdio>
#include<iostream>
#define N 1000005
#define INF 0x3f3f3f3f
using namespace std;
int n;
int a[N];
struct dddl{
    int x,val;
}right[N];
dddl left;
int head,tail;
int main(){
    head=tail=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]++;
    left.x=-INF;left.val=0;dp[1]=0;right[++head]=(dddl){1+a[1],0};
    for(int i=2;i<=n;i++){
        dp[i]=min(left.val+i-left.x,right[tail+1].val+right[tail+1].x-i);
        while(head>tail&&right[head].val>=)
    }
    return 0;
}