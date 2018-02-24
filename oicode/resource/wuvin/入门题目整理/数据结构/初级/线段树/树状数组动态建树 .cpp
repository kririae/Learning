#include<cstdio>
#include<iostream>
#include<cstring>
#define LL long long
/*
***洛谷1198 
***树状数组动态建树 
***ST算法解决RMQ
***支持A x在队尾增加一个数x
***Q L查询末尾L个数中的最大值 
*/
using namespace std;
LL last;//上一次的答案
LL lis[200005][18];
LL nums[200005];//start from 1
LL D,n;
int len;


LL ask(LL from,LL to){//RMQ查询最大值 
	if(from>to) return -1;
	int L=to-from+1;
	int buf=0;
	while((1<<(buf+1))<=L){
		buf++;
	}//2^buf
	return max(lis[from][buf],lis[to-(1<<buf)+1][buf]);
}

LL modd(LL x){
	if(x>=0) return x%D;
	return (D-(-x)%D);
}

void add(int x){
	len++;
	nums[len]=modd(x+last);
	int b=0;
	while(len-(1<<b)+1>0){//更改 [len-(1<<b)+1,b] 
		LL le=len-(1<<b)+1;
		//if(lis[le][b]==-1){
		lis[le][b]=max(nums[len],ask(le,len-1));
		b++;
	}
	return;
}


int main(){
	memset(lis,-1,sizeof(lis));
	scanf("%d%d",&n,&D);
	for(int kk=1;kk<=n;kk++){
		char ins;LL x;
		cin>>ins;
		scanf("%lld",&x);
		if(ins=='A'){
			add(x);
		}else{
			last=ask(len-x+1,len);
			cout<<last<<endl;
		}
	}
	return 0;
}
