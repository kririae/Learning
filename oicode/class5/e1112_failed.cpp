#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	int m;
	cin>>m;
	int a[m];
	for (int i = 0; i < m; ++i)
	{
		scanf("%d",&a[i]);
	}
	int t;
	for (int i = 0; i < m; ++i)
	{
		for (int j = i; j < m; ++j)
		{
			if(a[i]<a[j]) t=a[j],a[j]=a[i],a[i]=t; 
		}
	}
	cout<<a[0]-a[m-1];
}