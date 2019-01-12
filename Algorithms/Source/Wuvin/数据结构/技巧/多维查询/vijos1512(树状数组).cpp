#include<cstdio>
#define lowbit(x) x&(-x)
#define N 1030 
using namespace std;
/*
貌似二维树状数组异常好写
子底向上
*/
inline int read(){
	char c=getchar();int ret=0;
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') ret=ret*10+c-'0',c=getchar();
	return ret;
}
int a[N][N];
int n,m,x,y,t,x2,y2;
void change(int x,int y,int c){
	for(int i=x;i<=n;i+=lowbit(i)){
		for(int j=y;j<=n;j+=lowbit(j)){
			a[i][j]+=c;
		}
	}
}
int getsum(int x,int y){//前缀和
	int ret=0;
	for(int i=x;i>0;i-=lowbit(i)){
		for(int j=y;j>0;j-=lowbit(j)){
			ret+=a[i][j];
		}
	}
	return ret;
}
int main(){
	n=read(); 
	while(scanf("%d",&m)==1&&m!=3){
		if(m==1){
			x=read()+1;y=read()+1;t=read();
			change(x,y,t);
		}else if(m==2){
			x=read()+1;y=read()+1;x2=read()+1;y2=read()+1;
			printf("%d\n",getsum(x2,y2)+getsum(x-1,y-1)-getsum(x-1,y2)-getsum(x2,y-1) );
		}
	}
}
