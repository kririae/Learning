#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
bool is_upper(char st){
	bool isu=false;
	for (int i = 65; i < 91; ++i)
		if(st==i){isu=true;break;}
	return isu;
}
char breakc(char st1,char st2){
	bool is_upper_st1=is_upper(st1);
	int int_st1=is_upper(st1)?st1-65:st1-97;
	int int_st2=is_upper(st2)?st2-65:st2-97;
	char res;
	if(int_st1-int_st2<0){
		res=is_upper_st1?26-abs(int_st1-int_st2)+65:26-abs(int_st1-int_st2)+97;}
	else{
	res=is_upper_st1?abs(int_st1-int_st2)+65:abs(int_st1-int_st2)+97;}
	return res;
}	
int main(){
	char a[1001],b[101];
	cin>>b>>a;
	for (int i = 0; i < strlen(a); ++i)
		cout<<breakc(a[i],b[i%strlen(b)]);
}
