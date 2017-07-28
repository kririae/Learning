#include<iostream>
#include<cstdio>
#include<cstring>
const int N=256;
char c1[N],c2[N],c[N][N];
using namespace std;
int main(){
	gets(c1);strlwr(c1);
	gets(c2);strlwr(c2);
	int count=0;
	for(int index=0,i=0;i<=strlen(c2);++i){
		if(c2[i]!=' '){
			c[index][count]=c2[i];
			count+=1;
		}
		else{
			count=0;
			index+=1;
		}
	}
	int res=-1;
	int ans=0;
	for (int i = 0; i <= count; ++i)
	{
		if(strcmp(c1,c[i])==0){res = i;break;}
	}
	for (int i = 0; i <= count; ++i)
	{
		if(strcmp(c1,c[i])==0){ans+=1;}
	}
	cout<<ans<<" "<<res;
	return 0;
}