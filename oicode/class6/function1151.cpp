#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
bool is_prime(int p){
	bool prime=true;
	int k;
	k=sqrt(p);
	for (int i = 2; i <= k; ++i)
	{
		if(p%i==0) prime=false;
	}
	return prime;
}
int main(){
	int n;
	cin>>n;
	int count=0;
	for(int i = 2;i<=n;++i){
		if(is_prime(i)) count+=1;
	}
	cout<<count;	
	return 0;
}