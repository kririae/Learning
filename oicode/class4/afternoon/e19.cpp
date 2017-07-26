#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	int a[10];
	double b[10],count=0;
	for (int i = 0; i < 10; ++i)
	{
		scanf("%d",&a[i]);		
	}
	b[0]=28.9;
	b[1]=32.7;
	b[2]=45.6;
	b[3]=78;
	b[4]=35;
	b[5]=86.2;
	b[6]=27.8;
	b[7]=43;
	b[8]=56;
	b[9]=65;
	for (int i = 0; i < 10; ++i)
	{
		count+=a[i]*b[i];
	}
	printf("%.1lf",count);
	return 0;
}