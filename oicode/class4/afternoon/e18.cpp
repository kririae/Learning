#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	int a[10];
	for (int i = 0; i < 10; ++i)
	{
		scanf("%d",&a[i]);		
	}
	int high;
	scanf("%d",&high);
	int count=0;
	for (int i = 0; i < 10; ++i)
	{
		if(30+high>=a[i]) count+=1;
	}
	cout<<count;
	return 0;
}