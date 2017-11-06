#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
	int x,y,para;
	char format,kg=32;
	cin>>x>>y>>format>>para;
	if(para==1){
		for(int i = 0;i<x;++i)
		{
			for(int j = 0;j<y;++j)
			{
				cout<<format;
			}
			cout<<endl;
		}
	}
	if(para==0){
		for(int i = 0;i<y;++i)
		{
			cout<<format;
		}
		cout<<endl;
		for(int i = 0;i<x-2;++i)
		{	
			cout<<format;
			for(int j = 0;j<y-2;++j){ cout<<kg; }
			cout<<format;
			cout<<endl;
		}

		for(int i = 0;i<y;++i)
		{
			cout<<format;
		}
	}
	return 0;
}