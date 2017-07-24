#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	double a,b,res;
	int k;
	cin>>a>>b;
	k = a/b;
	res = a/b-k;
	cout<<res*b;
	return 0;
}