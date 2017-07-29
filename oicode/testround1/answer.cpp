#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("answer.cpp","r",stdin);
	char j[100][100];
	for(int i=0;i<12;++i){
		gets(j[i]);
		cout<<j[i]<<endl;
	}
	fclose(stdin);
}
