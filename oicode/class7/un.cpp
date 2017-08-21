#include<iostream>
#include<cstdio>
using namespace std;
bool prime(int x){
	double k=sqrt(x);bool is_prime=true;
	for(int i=2;i<=k;++i)
		if(x%i==0) is_prime=false;
	return is_prime;
}
bool is_upper(char st){
	bool isu=false;
	for (int i = 65; i < 91; ++i)
		if(st==i){isu=true;break;}
	return isu;
}
int main(){
	char char1[101];
	cin>>char1;
	int maxn=0,minn=0;
	int k = strlen(char1);
	int x[27];
	memset(x,0,sizeof(x));
	for (int i = 0; i < k; ++i)
	{
		if(is_upper(char1[i])) ++x[char1[i]-65];
		else ++x[char1[i]-97];
	}
	for (int i = 0; i < 26; ++i)
	{
		if(x[i]>maxn) maxn=x[i];
		if(x[i]<minn) minn=x[i];
	}
	if(is_prime(maxn-minn)) cout<<"Lucky Word"<<endl<<maxn-minn;
	else cout<<"No Answer";
	return 0;
}	