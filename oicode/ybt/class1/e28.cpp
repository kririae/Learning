#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
double counts(double xa,double ya,double xb, double yb);
int main(){
	double x1,y1,x2,y2,x3,y3;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	double len1,len2,len3;
	double p;
	len1 = counts(x1,y1,x2,y2);
	len2 = counts(x1,y1,x3,y3);
	len3 = counts(x2,y2,x3,y3);
	p = (len1+len2+len3)/2;
	printf("%.2lf",sqrt(p*(p-len1)*(p-len2)*(p-len3)));
	return 0;
}
double counts(double xa,double ya,double xb, double yb){
	return sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
}