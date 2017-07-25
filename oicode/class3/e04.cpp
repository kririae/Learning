#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n;
	cin>>n;
	int res,max;
	cin>>max;
	for(int i=0;i<n-1;++i){
		cin>>res;
		if(res>=max) max=res;
	}
	cout<<max;
	return 0;
}