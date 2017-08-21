#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char char1[233],char2[2333],char3[233][100];
int main(){
	gets(char1);gets(char2);
	int index1=0,index2=0;
	strlwr(char1);strlwr(char2);
	int k = strlen(char2);
	for (int i = 0; i < k; ++i)
	{
		if(char2[i]==' '){index1+=1;index2=0;}
		else{char3[index1][index2]=char2[i];index2+=1;}
	}
	int count=0,r;
	for (int i = 0; i < k; ++i)
		if(strcmp(char1,char3[i])==0){r=i;break;}
	for (int i = 0; i < k; ++i)
		if(strcmp(char1,char3[i])==0){count+=1;}
	if(count==0){
		cout<<-1;
	}
	else{
		cout<<count<<" "<<r;
	}
	return 0;
}
