#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	int m,n,p,count=0;
	cin>>m>>n;
	for (int i = 0; i < n; ++i)
	{
		if(m-p>=0){m-=p;}
		else{count+=1;}
	}
	cout<<count;
	return 0;
}