#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a[n];
	//一号人的操作w 
	memset(a,-1,sizeof(a));
	for (int i = 2; i <= m; ++i)
	{
		//i是人的编号，j是灯的编号 
		for (int j = 1; j <= n; ++j)
		{
			if(j%i==0) a[j-1]=-a[j-1];
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if(a[i-1]==-1) {if(i+1==n) cout<<i; else cout<<i<<",";}
	}
	return 0;
}