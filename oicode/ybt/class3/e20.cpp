#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	double n,pi=1,qi=2,sum=0,p;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		sum+=qi/pi;
		p=qi;
		qi=pi+qi;
		pi=p;
	}
	printf("%.4lf",sum);
	return 0;
}