#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	scanf("%d",&a[0]);
	for (int i = 1; i < n; ++i)
	{
		scanf("%d",&a[i]);
	}
	int b[n];
	b[0]=a[0];
	int count=1;
	for (int i = 1; i < n; ++i)
	{
		if(a[i]!=a[i-1])
		{
			b[count]=a[i];count+=1;
		}
	}
	int maxn=0;
	for (int count2,i = 0; i < count; ++i)
	{
		count2=0;
		for (int j = 0; j < n; ++j)
		{
			if(b[i]==a[j])count2+=1;
		}
		if (count2>maxn) maxn=count2;
	}
	cout<<maxn;
	return 0;
}