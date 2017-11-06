#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	int k,n,c=0;
	cin>>k>>n;
	int res;
	for (int i = 0; i < k; ++i)
	{
		cin>>res;
		if(res==n) c+=1;
	}
	cout<<c;
	return 0;
}