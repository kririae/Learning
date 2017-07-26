#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
bool is_prime_number(int x);
int main(){
	int n,a,b;
	cin>>n;
	for (int i = 2; i < sqrt(n); ++i)
	{
		if(n%i==0&&is_prime_number(n/i)&&is_prime_number(i)){
			a = i;b=n/i;
			break;
		}
	}
	printf("%d",a>b?a:b);
	return 0;
}
bool is_prime_number(int x){
	bool is_prime=true;
	for (int i = 2; i < sqrt(x); ++i)
	{
		if(x%i==0){is_prime = false;}
	}
	return is_prime;
}