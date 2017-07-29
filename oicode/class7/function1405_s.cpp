#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char char1[200],char2[200],char3[200],res[200][100];
int main(){
	gets(char1);gets(char2);gets(char3);
	int k=strlen(char1);
	int index1=0,index2=0;
	for (int i = 0; i < k; ++i)
	{
		if(char1[i]==' '){index1+=1;index2=0;}
		else{res[index1][index2]=char1[i];index2+=1;}
	}
	for (int i = 0; i < index1+1; ++i)
	{
		if(strcmp(res[i],char2)==0) strcpy(res[i],char3);
	}
	for (int i = 0; i < index1+1; ++i)
	{
		cout<<res[i]<<" ";
	}
	return 0;
}
