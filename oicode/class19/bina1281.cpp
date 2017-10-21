#include <iostream>
using namespace std; 
int i,j,n,s,t,a[100001];
int main()
{ 
    cin>>n;
    a[0]=-1000000;
    for(i=0;i<n;i++)
    {
        cin>>t;
        if(t>a[s]) a[++s]=t;
        else
        {
            int l=1,h=s,m;
            while(l<=h)
            {
                m=(l+h)/2;
                if(t>a[m]) l=m+1;
                else h=m-1;
            }
            a[l]=t;
        }
    }
    cout<<s<<endl;
}
