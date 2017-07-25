#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n;
	cin>>n;
	int j=0,y=0,t=0,res;
	int a,b,c;
	for(int i=0;i<n;i++){
		cin>>a>>b>>c;
		j+=a;y+=b;t+=c;
	}
	cout<<j<<" "<<y<<" "<<t<<" "<<j+y+t;
	return 0;
}