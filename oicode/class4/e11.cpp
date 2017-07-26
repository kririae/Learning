#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
bool z(int x);
int main(){
	int n,count=0,l,r;
	cin>>l>>r;
	for (int i = l; i <= r; ++i)
	{
		int x = i;
		while(x>=1){
			if(x%10==2){count+=1;x/=10;}
			else x/=10;
		}
	}
	cout<<count;
	return 0;
}