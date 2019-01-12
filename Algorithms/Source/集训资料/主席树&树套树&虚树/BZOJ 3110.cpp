#include<cstdio>
#include<cctype>
using namespace std;
 
const int N=50000+19,M=N*16*16;
int Lsn[M],Rsn[M],Root[N<<2],Add[M],sum[M];
int cc,n,m,a,b,c,tot,cnt,_sum,Flag;
 
inline void Read(int &x)
{
    while (!isdigit(cc=getchar()));
    x=cc-'0';
    while (isdigit(cc=getchar())) x=x*10+cc-'0';
}
inline void count(int x,int L,int R,int add)
{
    if (a<=L&&R<=b) {_sum+=sum[x]+add*(R-L+1);return;}
    int Mid=(L+R)>>1;
    if (a<=Mid) count(Lsn[x],L,Mid,add+Add[x]);
    if (b>=Mid+1) count(Rsn[x],Mid+1,R,add+Add[x]);
}
inline int query()
{
    int L=1,R=n,now=1;
    while (L^R)
    {
        int Mid=(L+R)>>1;_sum=0;
        count(Root[now<<1],1,n,0);
        if (_sum>=c) R=Mid,now=now<<1;else L=Mid+1,now=now<<1|1,c-=_sum;
    }
    return L;
}
inline void Update(int &x,int L,int R)
{
    if (!x) x=++tot;
    if (a<=L&&R<=b) Add[x]++;
        else
        {
            int Mid=(L+R)>>1;
            if (a<=Mid) Update(Lsn[x],L,Mid);
            if (b>=Mid+1) Update(Rsn[x],Mid+1,R);
        }
    sum[x]=sum[Lsn[x]]+sum[Rsn[x]]+Add[x]*(R-L+1);
}
inline void modify()
{
    int L=1,R=n,now=1;
    while (L^R)
    {
        int Mid=(L+R)>>1;
        Update(Root[now],1,n);
        if (c<=Mid) R=Mid,now<<=1;else L=Mid+1,now=now<<1|1;
    }
    Update(Root[now],1,n);
}
 
int main()
{
    scanf("%d%d",&n,&m);
    while (m--)
    {
        Read(Flag);Read(a);Read(b);Read(c);
        if (Flag==1) c=n-c+1,modify();
            else printf("%d\n",n-query()+1);
    }
}

