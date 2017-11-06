#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	char a;
	int ascii;
	a = getchar();
	ascii=a;
	if(ascii%2==0) cout<<"NO";
	else cout<<"YES";
	return 0;
}