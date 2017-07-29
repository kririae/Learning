#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char charar[256];
int main(){
	gets(charar);
	int count=0;
	for (int i = 0; i < strlen(charar); ++i)
	{
		if(charar[i]>='0'&&charar[i]<='9') count+=1;
	}
	cout<<count;
	return 0;
}