#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int n,m;
struct node{
	int year,rain;
	node(){
	}
	node(int y,int r){year=y;rain=r;}
}v[50005];
int st[50005][16];
int cmp(int a,int b){
	return max(a,b);
}
void buildST(){//st[i][j]--->max[i,i+2^j-1]
	for(int i=1;i<=n;i++){
		st[i][0]=v[i].rain;
	}
	for(int j=1;(1<<j)<n;j++){
		for(int i=1;i<=n;i++){
			if(i+(1<<j)-1<=n){
				st[i][j]=cmp(st[i][j-1],st[i+(1<<(j-1))][j-1]);
			}
		}
	}
}
int getmax(int from,int to){
	int k=to-from;
	if(k<0) return -1;
	if(k==0) return st[from][0];
	int p=0;
	while(k!=0){//取最高位的1 
		k>>=1;p++;
	}
	p--;
	return cmp(st[from][p],st[to-(1<<p)+1][p]);
}
int lb(int from,int to,int key){
	int k=key;
	int left=from,right=to+1;
	while(left+1<right){
		int mid=(left+right)/2;
		if(k<v[mid].year) right=mid;
		else left=mid; 
	}
	return left;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&v[i].year,&v[i].rain); 
	}
	buildST();//建立ST
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		//这里有各种细节
		//询问的两年的降雨量可能本来就未知，还可能远小于已知数据 
		int from,now;int rainn,rainf;int left=0;int right=0;int sure=1;
		scanf("%d%d",&from,&now);
		//sj
		if(now<=v[1].year||from>=v[n].year){
			printf("maybe\n");continue;
		}
		int pf,pn;
		pf=lb(1,n,from);//二分查找  左闭右开 
		pn=lb(1,n,now);
		if(v[pf].year==from){
			rainf=v[pf].rain;left=pf+1;
		}else if(from<v[1].year){
			rainf=0x7fffffee;left=1;sure=0;
		}else{
			left=pf+1;sure=0;
			rainf=0x7fffffee;
		}
		if(v[pn].year==now){
			rainn=v[pn].rain;right=pn-1;
		}else{
			right=pn;
			rainn=rainf;sure=0;
		}
		
		if(rainn>rainf){
			printf("false\n");continue;
		}
		int maxx=getmax(left,right);//ST返回最值，左闭右闭 
		if(maxx>=rainn){
			printf("false\n");continue;
		}
		if(now-from>pn-pf||sure==0){
			printf("maybe\n");continue;
		}
		printf("true\n");
	}
	return 0;
}
