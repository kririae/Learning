#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int main(){
	int n,x;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a[i]);
	}
	cin>>x;
	int index;
	for (int i = 0; i < n; ++i)
	{
		if(a[i]==x) {
			index=i+1;
			break;}
		if(i==n-1) index=-1;
	}
	cout<<index;
	return 0;
}