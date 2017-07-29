#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int res;
	cin>>res;
	int res1 = res/100;
	int res2 = res/10%10*10+res%10;
	cout<<res1+res2;
}