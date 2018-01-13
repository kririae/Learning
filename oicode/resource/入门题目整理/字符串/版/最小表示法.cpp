#include<cstdio>
#include<cstring>
using namespace std;
/*最小表示法*/
/*----------------------
最小表示法就是在对一个字符串从不同位置开始的串比较大小
一直保留最小的
避开同串匹配
确保一个在前一个在后 
-----------------------*/
int getM(char *s){//返回最小表示法开始的下标（start from 0） 
	int len=strlen(s);
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
			if(p>len) break;//不可能有匹配了 
		} else if(s[p1]<s[q1]){
			q+=k+1;
			k=0;
			if(q>len) break;
		}else{
			k++;
		}
	}
	return p;//p==q
}
int main(){
	char c[]="cbba";
	printf("%d",getM(c));
	return 0;
}
