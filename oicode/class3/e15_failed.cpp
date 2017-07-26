#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	int n,sum=0;
	cin>>n;
	double a,b,c,distance;
	for (int i = 0; i < n; ++i)
	{
		cin>>a>>b>>c;
		distance = sqrt(a*a+b*b);
		sum+=ceil(distance/50+1*c+distance/50+0.5*c);
	}
	cout<<sum;
	return 0;
}