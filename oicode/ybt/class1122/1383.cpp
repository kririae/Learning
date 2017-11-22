#include<iostream>
#include<cstdio>
using namespace std;
int a[10000];
int b[10000];
int main()
{
    int n,z;
    cin>>n;
    for(int i=1;i<=n;i++)
     {   
        cin>>z;
        a[z]=1;
         while(z!=0)
          {
              cin>>z;
              a[z]=1;
          }
     }
     int tot=0;
     for(int i=1;i<=n;i++)
      {
          if(a[i]==0)
           {
               tot++;
           }
      }
      cout<<tot;
      return 0;
}
