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
	int res[count];
	for (int count2,i = 0; i < count; ++i)
	{
		count2=0;
		for (int j = 0; j < n; ++j)
		{
			if(b[i]==a[j])count2+=1;
		}
		res[i]=count2;
	}
	for (int t,k,i = 0; i < count-1; ++i)
	{
		k=i;
		for (int j = i+1; j < count; ++j)
		{
			if(res[k]>res[j]) k=j;
		}
		if(k!=i) t=res[k],res[k]=res[i],res[i]=t;
	}
	cout<<res[count-1];
	return 0;
}