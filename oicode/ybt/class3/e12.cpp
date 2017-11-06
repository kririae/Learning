#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	double x,n;
	cin>>x>>n;
	for (int i = 0; i < n; ++i)
	{
		x*=1+0.1/100;
	}
	printf("%.4lf",x);
	return 0;
}