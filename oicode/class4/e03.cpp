#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main() {
	double sn,k,res,count=0;
	cin>>k;
	do{
		count+=1;
		sn+=1/count;
	}while(sn<=k);
	res = count;
	printf("%.0lf",res);
    return 0;
}