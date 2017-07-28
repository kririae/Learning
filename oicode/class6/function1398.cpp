#include<iostream>
#include<cstdio>
using namespace std;
int price(int p){
	if(p%70==0) return p/70;
	else return (p/70)+1;
}
int main(){
	int n;
	cin>>n;
	double count=0;
	for (int j,i = 0; i < n; ++i)
	{
		scanf("%d",&j);
		count+=price(j)*0.1;
	}
	//cout<<147/70;
	printf("%.1lf",count);
}