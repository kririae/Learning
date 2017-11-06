#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
double arctanx(double x){
	int f=1;
	int count=1;
	double res=0;
	//res = res+x-x*x/3;
	while(f*pow(x,count)/count>=1.0e-6){
		res+=f*pow(x,count)/count;
		count+=2;
		f=-f;
	}
	return res;
}
int main(){
	cout<<6*arctanx(1/sqrt(3.0));
	return 0;
}
