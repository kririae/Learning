#include<iostream> 
#include<cstdio>
#include<cmath>
using namespace std;

long long gcd(long long a,long long b)
{
  if(b==0) return a;
  return gcd(b,a%b);
}

void exgcd(long long a,long long b,long long &m,long long &n)
{
   if(b==0)
   {
      m=1;
      n=0;
      return ;
   }
   exgcd(b,a%b,m,n);
   long long t;
   t=m;
   m=n;
   n=t-a/b*n;
}

int main()
{
   freopen("qw.in","r",stdin);
   freopen("qw.out","w",stdout);
   long long x,y,m,n,l,a,b,c,k1,k2,r,t;
   while(scanf("%I64d%I64d%I64d%I64d%I64d",&x,&y,&m,&n,&l)!=EOF)
   {
      a=n-m;
      b=l;
      c=x-y;
      r=gcd(a,b);
      if(c%r)
      {
         printf("Impossible\n");
         continue;
      }
      a/=r;
      b/=r;
      c/=r;
      exgcd(a,b,k1,k2);
      t=c*k1/b;            //注
      k1=c*k1-t*b;
      if(k1<0)
        if (b>0) k1+=b;
      printf("%I64d\n",k1);
   }
   return 0;
}

/*
注：
此时方程的所有解为：x=c*k1-b*t,x的最小的可能值是0，
令x=0可求出当x最小时的t的取值，但由于x=0是可能的最小取值，
实际上可能x根本取不到0，那么由计算机的取整除法可知：
由 t=c*k1/b算出的t，代回x=c*k1-b*t中，求出的x可能会小于0，
此时令t=t+1，求出的x必大于0；如果代回后x仍是大于等于0的，
那么不需要再做修正。
*/ 
