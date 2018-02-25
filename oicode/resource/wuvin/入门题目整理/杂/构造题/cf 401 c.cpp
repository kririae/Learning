#include<cstdio>
using namespace std;
/*
codeforces ×¢ÒâÑ¡Ôñ±àÒëÆ÷ 
*/
int zero;
int one;
int n; 
int main(){
	scanf("%d%d",&zero,&one);
	if((zero*2+2<one)||(zero>one+1)){
		printf("-1");
	}else{
		if(one> zero) {
			printf("11");
			one-=2;
		}
		for(int i=zero;i>0;i--){
			printf("0");
			if(one>i){
				printf("11");
				one-=2;
			}else if(one>0){
				printf("1");
				one--;
			}
		}
	}
	return 0;
}
