#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	int h,r,k;
	double v,t;
	cin>>h>>r;
	v = h*3.14159*r*r/1000;
	cout << (int)(20/v+1);
	return 0;
}