#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n;
	double res,sum;
	cin>>n;
	sum=0;
	for(int i = 0;i < n;++i){
		cin>>res;
		sum += res;
	}
	printf("%g %.5lf",sum,sum/n);
	return 0;
}