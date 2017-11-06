#include<iostream>
#include<cstdio>
using namespace std;
int calc(int a,char c,int b){
	switch(c){
		case '+':return a+b;
		case '-':return a-b;
		case '*':return a*b;
		case '/':return a/b;
		case '%':return a%b;
	}
}
int main(){
	int a,b;
	char c;
	cin>>a>>c>>b;
	cout<<calc(a,c,b);
}