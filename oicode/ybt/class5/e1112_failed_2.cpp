#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int m;
	cin>>m;
	int a[m];
	for (int i = 0; i < m; ++i)
	{
		scanf("%d",&a[i]);
	}
	int maxn=a[0],minn=a[0];
	for (int i = 0; i < m; ++i)
	{
		if(maxn<a[i]) maxn=a[i];
		if(minn>a[i]) minn=a[i];
	}
	cout<<maxn-minn;
	return 0;
}