#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main() {
	int a,b,c,res=1;
	c = a%10;
	//c是a的个位数
	for (int i = 0; i < b; ++i)
	{
		if(c*c<1000){
			continue;
		}
		else{
			c=c*c%10+(c*c/10)%10*10+(c*c/100)%10*100;
		}
		res*=c
		c = res;
	}
	cout<<res;
    return 0;
}