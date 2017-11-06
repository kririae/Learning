#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

double rb()
{
	char num[100];
	scanf("%s",num);
	if(num[0] == '+') return rb()+rb();
	if(num[0] == '-') return rb()-rb();
	if(num[0] == '*') return rb()*rb();
	if(num[0] == '/') return rb()/rb();
	double digit;
	sscanf(num,"%lf",&digit);
	return digit;
}
int main(){
	printf("%lf\n",rb());
	return 0;
}