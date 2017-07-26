#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main() {
	double n,res1=0,res2=1;
	scanf("%lf",&n);
	for (int i = 1; i <= n; ++i)
	{
		res2*=i;
		res1+=1/res2;
	}
	printf("%.10lf",res1+1);
	return 0;
}