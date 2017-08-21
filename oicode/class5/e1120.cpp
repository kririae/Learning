#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n,i,j;
	cin>>n>>i>>j;
	for (int x = 1; x <= n; ++x)
	{
		printf("(%d,%d) ",i,x);
	}
	cout<<endl;
	for (int x = 1; x <= n; ++x)
	{
		printf("(%d,%d) ",x,j);
	}
	cout<<endl;
	for (int x = 1; x <= n; ++x)
	{
		if(x+(j-i)<=n)
		printf("(%d,%d) ",x,x+(j-i));
	}
	cout<<endl;
	for (int x = 1; x <= n; ++x)
	{
		if(j+i-x<=n)
		printf("(%d,%d) ",(j+i-x),x);
	}
	return 0;
}
//炸毛....