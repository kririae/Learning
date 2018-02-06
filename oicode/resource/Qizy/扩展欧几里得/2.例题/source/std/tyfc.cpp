#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

long long EXT_GCD(long long a, long long b, long long &x, long long &y)
{
   if(a<b) swap(a, b);
   if(b == 0)
   {
       x = 1;
       y = 0;
       return a;
   }
   long long ret = EXT_GCD(b, a % b, x, y);
   long long temp = x;
   x = y;
   y = temp - a / b * y;
   return ret;
}

int main()
{
   //freopen("mod.in","r",stdin);
   //freopen("mod.out","w",stdout);

   long long a, b, x, y;

   scanf("%I64d %I64d", &a, &b);
   EXT_GCD(a, b, x, y);
   if(a * x + b * y == 1)
       printf("%I64d\n", (x % b + b) % b);
   else
       printf("%I64d\n", (y % b + b) % b);
   return 0;
}
