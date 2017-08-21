#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[10];
bool cmp(int a,int b){
	if(a>=b)return false;
	return true;
}
int main(){
	int n,i=0,count=0;
	cin>>n;
	int count2=0;
	while(n>0){
		a[i]=n%10;
		n/=10;
		++i;
		//if(a[i]%10==0)count2+=1;
		count+=1;
	}
	for(int i=0;i<count;++i){
		if(a[i]==0)count2+=1;
	}
	sort(a,a+count,cmp);
	cout<<a[count2];
	for(int i=0;i<count2;i++){
		cout<<0;
	}
	for(int i=count2+1;i<count;++i){
		cout<<a[i];
	}
}
