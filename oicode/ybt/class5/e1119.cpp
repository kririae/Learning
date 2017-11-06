#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int x[5][5];
	int y[5][5];
	for (int i = 0; i < 5; ++i)
	{
		for (int k,j = 0; j < 5; ++j)
		{
			cin>>k;
			x[i][j]=k;
			y[i][j]=k;
		}
	}
	int m,n;
	cin>>m>>n;
	for (int i = 0; i < 5; ++i)
	{
		x[m-1][i]=x[n-1][i];
	}
	for (int i = 0; i < 5; ++i)
	{
		x[n-1][i]=y[m-1][i];
	}
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			printf("%d ",x[i][j]);
		}
		cout<<endl;
	}
	return 0;
}