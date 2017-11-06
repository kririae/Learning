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
bool is_h(int p){
	return p/100+p/10%10*10+p%10*100==p?true:false;
}
int main(){
	for (int i = 100; i < 1000; ++i)
	{
		if(is_h(i)&&is_prime(i)) cout<<i<<endl;
	}
	return 0;
}