#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
double maxn(int a,int b,int c){
	double maxx=a;
	if(maxx<b) maxx=b;
	if(maxx<c) maxx=c;
	return maxx;
}
int main(){
	double m;
	int a,b,c;
	cin>>a>>b>>c;
	m=maxn(a,b,c)/(maxn(a+b,b,c)*maxn(a,b,b+c));
	printf("%.3lf",m);
	return 0;
}