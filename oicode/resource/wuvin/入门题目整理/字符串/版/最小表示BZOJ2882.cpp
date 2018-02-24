#include<cstdio>
#include<cstring>
using namespace std;
/*最小表示法*/
int n;
int getM(int *s){//返回最小表示法开始的下标（start from 0） 
	int len=n;
	int p=0;int q=1;
	int k=0;int p1=0,q1=1;
	while(k<=len){
		if(p==q) q++;
		p1=p+k;q1=q+k;
		if(p1>=len) p1-=len;
		if(q1>=len) q1-=len;
		if(s[p1]>s[q1]){
			p+=k+1;//请仔细琢磨 
			k=0;
			if(p>=len) break;//不可能有匹配了 
		} else if(s[p1]<s[q1]){
			q+=k+1;
			k=0;
			if(q>=len) break;
		}else{
			k++;
		}
	}
	return p;//p<q
}
int c[300005];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&c[i]);
	}
	int p=getM(c);//讨厌的格式错误 
	/* 
	for(int i=p;i<n;i++){
		printf("%d ",c[i]);
	}
	for(int i=0;i<p;i++){
		printf("%d ",c[i]);
	}*/
	for(int i=0;i<n;i++){
		int p1=(p+i)%n;
		if(i!=n-1){
			printf("%d ",c[p1]);
		}else{
			printf("%d",c[p1]);
		}
	} 
	return 0;
}
