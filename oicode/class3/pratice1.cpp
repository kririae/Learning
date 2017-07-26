#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	long int paper=1,count=0;
	while(paper<=8848.43*100*10*10){
		++count;
		paper*=2;
	}
	cout<<count;
	return 0;
}