#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	double xa,ya,xb,yb;
	cin>>xa>>ya>>xb>>yb;
	printf("%.3lf",sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb)));
	return 0;
}