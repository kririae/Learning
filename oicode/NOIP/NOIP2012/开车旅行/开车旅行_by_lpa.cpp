#include<cstdio>
#include<cctype>
#include<cstring>
#include<set>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
#define R register
#define IN inline
#define gc getchar()
#define W while
#define ll long long 
#define Lg 21
#define MX 100005
struct sd
{
    int num,height;
    bool operator <(const sd &x)const
    {
        return x.height>height;
    }
};
sd data[MX];
set <sd> city;
set<sd>::iterator it;
int st[Lg][MX];
ll dista[Lg][MX],distb[Lg][MX];
int nxta[MX],nxtb[MX];
bool fu;
IN void in(int &x)
{
    fu=false;
    R char c=gc;x=0;
    W(!isdigit(c)){
    if(c=='-')fu=true;c=gc;}
    W(isdigit(c))
    {x*=10,x+=c-48,c=gc;}
    if(fu)x=-x;
}
struct Message
{
    int city,value;
    bool operator < (const Message &x)const
    {
        if(value!=x.value)return value<x.value;
        return data[city].height<data[x.city].height;
    }
}chance[5];
IN void Find(int i)
{
    R int tot=0;
    it=city.find(data[i]);
    if(it!=city.begin())
    {
        --it;
        chance[tot++]=(Message){it->num,abs(it->height-data[i].height)};
        if(it!=city.begin())
        {
            --it;
            chance[tot++]=(Message){it->num,abs(it->height-data[i].height)};
            ++it;
        }
        ++it;
    }
    if((++it)!=city.end())
    {
        chance[tot++]=(Message){it->num,abs(it->height-data[i].height)};
        if((++it)!=city.end())
        {
            chance[tot++]=(Message){it->num,abs(it->height-data[i].height)};
            --it;
        }
        --it;
    }
    sort(chance,chance+tot);
    nxtb[i]=chance[0].city;
    if(tot==1)return;
    nxta[i]=chance[1].city;
}
IN void query(int now,int x,ll &a, ll &b)
{
    for(R int i=19;~i;--i)
    {
        if(st[i][now]&&dista[i][now]+distb[i][now]<=x)
        {
            a+=dista[i][now],b+=distb[i][now];
            x-=dista[i][now]+distb[i][now];now=st[i][now];
        }
    }
    if(!nxta[now])return;
        int dis=abs(data[nxta[now]].height-data[now].height);
        if(x>=dis)a+=dis;
}
int main()
{
    int numm;
    in(numm);
    for(R int i = 1 ;i<=numm;++i)
    {
        in(data[i].height);
        data[i].num=i;
    }
    for(R int i=numm;i>=1;--i)
    {
        city.insert(data[i]);
        if(i^numm)
        Find(i);
    }
    for(R int i=1;i<=numm;++i)
    {
        int pos1=nxta[i],pos2=nxtb[nxta[i]];
        dista[0][i]=pos1?abs(data[pos1].height-data[i].height):0;
        distb[0][i]=pos2?abs(data[pos2].height-data[pos1].height):0;
        st[0][i]=pos2;
    }
    for(R int i=1;i<=19;++i)
    {
        for (R int j = 1; j <= numm; ++j)
        {
            st[i][j]=st[i-1][st[i-1][j]];
            dista[i][j]=dista[i-1][j]+dista[i-1][st[i-1][j]];
            distb[i][j]=distb[i-1][j]+distb[i-1][st[i-1][j]];
        }
    }
    int x0,ans=0;
    in(x0);
    ll ansa=1e15,ansb=0ll,ta,tb;
    for (R int i = 1; i <=numm ; ++i)
    {
        ta=0ll,tb=0ll;
        query(i,x0,ta,tb);
        if(tb&&(!ans||ansa*tb>ansb*ta))
        {
            ansa=ta;ansb=tb;ans=i;
        }
    }
    printf("%d\n",ans);

    int que;
    int s1,x1;
    in(que);
    while(que--)
    {
        in(s1),in(x1);
        ansa=0,ansb=0;
        query(s1,x1,ansa,ansb);
        printf("%lld %lld\n",ansa,ansb);
    }
    return 0;
}
