#include<iostream>
#include<cstdio>
#include<cmath>
#include<time.h>
using namespace std;
bool is_prime_number(int x);
int main(){
	int n,res,count=0,i = 2;
	//cin>>n;
	n = 10000;
	do{
		bool is_prime = true;
		for (int j = 2; j < i; ++j){
			if(i%j==0){is_prime = false;break;}
		}
		if(is_prime){
			++count;
			if(count==n)
			{
				res = i;
				break;
			}
		}
		++i;
	}while(true);
	cout<<res<<endl;
	cout<<(double)clock() /CLOCKS_PER_SEC<<"s";
	return 0;
}