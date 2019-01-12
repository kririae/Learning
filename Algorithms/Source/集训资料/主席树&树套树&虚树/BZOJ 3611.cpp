#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
 
#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;
 
int IN()
{
    int c,x;
    while (!isdigit(c=getchar()));x=c-'0';
    while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}
 
const int N=2000000+19;
typedef long long LL;
typedef int one[N];
struct Edge {int y,nxt;} E[N*2];
one Last,D,is_h,ID,f,S,B;
int Fa[N][20],h[2*N],n,x,y,cnt,Q,m,Time,Min,Max;
LL g[N],Sum;
 
bool cmp(int a,int b) {return ID[a]<ID[b];}
void Link(int x,int y)
{
    E[cnt]=(Edge){y,Last[x]};Last[x]=cnt++;
    E[cnt]=(Edge){x,Last[y]};Last[y]=cnt++;
}
void DFS(int x)
{
    ID[x]=++Time;
    for (int i=Last[x];~i;i=E[i].nxt)
        if (E[i].y!=Fa[x][0]) Fa[E[i].y][0]=x,D[E[i].y]=D[x]+1,DFS(E[i].y);
}
int LCA(int x,int y)
{
    if (D[x]>D[y]) swap(x,y);
    for (int i=D[y]-D[x],k=0;i;i>>=1,k++) if (i&1) y=Fa[y][k];
    if (x==y) return x;
    for (int i=19;~i;i--) if (Fa[x][i]!=Fa[y][i]) x=Fa[x][i],y=Fa[y][i];
    return Fa[x][0];
}
 
void DP(int x,int Fa)
{
    S[x]=(is_h[x]?0:(1<<30)-1);
    B[x]=(is_h[x]?0:-(1<<30));
    f[x]=is_h[x],g[x]=0;
    for (int i=Last[x],y;~i;i=E[i].nxt)
        if ((y=E[i].y)!=Fa)
        {
            DP(y,x);
            Sum+=(g[x]+1LL*f[x]*(D[y]-D[x]))*f[y]+1LL*g[y]*f[x];
            Min=min(Min,S[x]+(D[y]-D[x])+S[y]);
            Max=max(Max,B[x]+(D[y]-D[x])+B[y]);
            f[x]+=f[y];
            g[x]+=g[y]+1LL*(D[y]-D[x])*f[y];
            S[x]=min(S[x],S[y]+(D[y]-D[x]));
            B[x]=max(B[x],B[y]+(D[y]-D[x]));
        }
    Last[x]=-1,is_h[x]=0;
}
 
int main()
{
    memset(Last,-1,sizeof(Last));
    n=IN();
    For(i,1,n) Link(IN(),IN());
    DFS(1);
    For(i,1,20) for (x=1;x<=n;x++) Fa[x][i]=Fa[Fa[x][i-1]][i-1];
    memset(Last,-1,sizeof(Last));cnt=0;
 
    for (Q=IN();Q--;)
    {
        m=IN();
        For(i,1,m+1) is_h[h[i]=IN()]=1;
        sort(h+1,h+m+1,cmp);
        For(i,1,m) h[i+m]=LCA(h[i],h[i+1]);h[m=m*2]=1;
        sort(h+1,h+m+1,cmp);
        m=unique(h+1,h+m+1)-h-1;
        For(i,2,m+1) Link(LCA(h[i],h[i-1]),h[i]);
        Sum=0,Min=(1<<30)-1,Max=-Min;
        DP(1,-1);cnt=0;
        printf("%lld %d %d\n",Sum,Min,Max);
    }
}
