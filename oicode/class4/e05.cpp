#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main() {
	int n,res;
	cin>>n;
	bool f,if_first;
	if(n<0) {f = true;cout<<"-";n = -n;}
	else {f=false;}
	while(n%10==0){
		n/=10;
	}
	do{
		cout<<n%10;
		n/=10;
	}while(n>=1);
	return 0;
}