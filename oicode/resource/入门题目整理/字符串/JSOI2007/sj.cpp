#include<bits/stdc++.h>
using namespace std;

int main(){
	srand(time(0));
	int n,m;
	n=rand()%10+99990;
	for(int i=1;i<=n;i++){
		char c;
		do{
			c=rand()%256;	
		}while(!(('0'<=c&&c<='9')||('a'<=c&&c<='z')||('A'<=c&&c<='Z')));
		printf("%c",c);
	}
	return 0;
}
