#include<cstdio>
#include<cstring>
#include<iostream>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

int n,m;
int a[2005][2005];
int qiax[2005][2005];
int qiin[2005][2005];
int hoax[2005][2005]={0};
int hoin[2005][2005]={0};

bool pan(int r)
{
    int p[2005]={0};
    int ax=0;
    int in=0x3f3f3f3f;
    p[0]=m;
    for(int i=1;i<=n;i++)
    {
        int x=ax,y=in;
        p[i]=p[i-1]+1;
        if(p[i-1]==0)
          break;
        do
        {
            p[i]--; 
            x=max(ax,qiax[i][p[i]]);
            y=min(in,qiin[i][p[i]]);
        }while(x-y>r);
        ax=x;
        in=y;
    }
    ax=0;
    in=0x3f3f3f3f;
    for(int i=1;i<=n;i++)
    {
        ax=max(ax,hoax[i][p[i]+1]);
        in=min(in,hoin[i][p[i]+1]);
    }
    if(ax-in<=r)
      return true;
      
      
    
    ax=0;
    in=0x3f3f3f3f;
    memset(p,0,sizeof(p));
    p[n+1]=m;
    for(int i=n;i>=1;i--)
    {
        int x=ax,y=in;
        p[i]=p[i+1]+1;
        if(p[i+1]==0)
          break;
        do
        {
            p[i]--; 
            x=max(ax,qiax[i][p[i]]);
            y=min(in,qiin[i][p[i]]);
        }while(x-y>r);
        ax=x;
        in=y;
    }
    ax=0;
    in=0x3f3f3f3f;
    for(int i=1;i<=n;i++)
    {
        ax=max(ax,hoax[i][p[i]+1]);
        in=min(in,hoin[i][p[i]+1]);
    }
    if(ax-in<=r)
      return true;
    return false;
}

int er(int fir,int las)
{
    if(fir==las)
    {
        return fir;
    }
    int mid=(fir+las)/2;
    if(pan(mid))
      return er(fir,mid);
    else
      return er(mid+1,las);
} 

int main()
{
    memset(qiin,0x7f,sizeof(qiin));
    memset(hoin,0x7f,sizeof(hoin));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
      {
        qiax[i][j]=max(qiax[i][j-1],a[i][j]);
        qiin[i][j]=min(qiin[i][j-1],a[i][j]);
      }
    for(int i=1;i<=n;i++)
      for(int j=m;j>=1;j--)
      {
      	hoax[i][j]=max(hoax[i][j+1],a[i][j]);
      	hoin[i][j]=min(hoin[i][j+1],a[i][j]);
      }
    printf("%d",er(0,1000000000));
}
