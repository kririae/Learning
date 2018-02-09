#include<cstdio>
#include<iostream>
using namespace std;
typedef unsigned long long ULL;
const int H=60;
int f[H+5],inc[1000];

inline ULL sqr(const ULL &x)
{return x*x;}

inline unsigned h(const ULL &i)
{
	return (sqr(i%20000116)+i+804)/233;
}

int main()
{
	freopen("fantasy.in","r",stdin);
	freopen("fantasy.out","w",stdout);
	register ULL p,L,R;
	register int CT,k,i,sum;
	register unsigned ans;
	for(cin>>CT;CT--;)
	{
		cin>>k>>L>>R;
		ans=sum=0;
		for(int i=0;i<k;i++)inc[i]=i+1;
		inc[k-1]=0;
		for(p=L,i=0;i<H;i++,p/=k)
			sum+=(f[i]=p%k);
		sum%=k;
		for(p=L;p<=R;p++)
		{
			ans=(ans+sum*h(p));
			sum=inc[sum];
			f[0]++;
			for(i=0;f[i]==k;i++)
				f[i]=0,f[i+1]++,sum=inc[sum]; 
		}
		printf("%u\n",ans);
	}
	return 0;
}

