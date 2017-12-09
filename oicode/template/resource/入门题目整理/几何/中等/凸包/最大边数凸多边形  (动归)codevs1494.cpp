#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#define LL long long
#define db int
#define eps 0
#define N 105
using namespace std;
inline int read(){
	char c=getchar();int ret=0;
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') ret=ret*10+c-'0',c=getchar();
	return ret;
}
struct point{db x,y;};
struct seg{point a,b;};
inline point operator -(const point &a,const point &b){
	return (point){a.x-b.x,a.y-b.y};
}
inline db getdis(point &a,point &b){
	point c=a-b;
	return sqrt(c.x*c.x-c.y*c.y);
}
inline bool equ(db a,db b){
	return fabs(a-b)<eps;
}
inline db cross(point a,point b){
	return a.x*b.y-b.x*a.y;
}
inline bool onleft(const point &o,const point &a,const point &b){
	return cross(a-o,b-o)>=eps;
}
///////////////////////////////////////////库 
//算了，不优化到n^2logn了
//快速水过
inline bool cmp1(const point &a,const point &b){
	db c=cross(a,b);
	if(cross==0){
		return a.x>b.x;
	}else{
		return c<0;
	}
}
int n,ans=3;
point p[N];
int dp[N][N];//dp(i,j)//现在在i，从j来 
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		p[i].x=read();p[i].y=read();
	}
	sort(p+1,p+n+1,cmp1);
	for(int i=1;i<=n;i++){
		dp[i][0]=2;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			for(int k=i+1;k<=n;k++){
				if(!onleft(p[j],p[i],p[k])){
					dp[k][i]=max(dp[k][i],dp[i][j]+1);
					ans=max(ans,dp[k][i]);
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
} 
