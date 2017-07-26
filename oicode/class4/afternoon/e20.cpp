#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	//double b[10],count=0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a[i]);		
	}
	for (int i = n-1; i >=0 ; --i)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}