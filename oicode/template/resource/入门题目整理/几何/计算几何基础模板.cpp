#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#define LL long long
#define db double
#define eps 1e-8
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
	return sqrt(c.x*c.x+c.y*c.y);
}
inline bool equ(db a,db b){
	return fabs(a-b)<eps;
}
inline db cross(point a,point b){
	return a.x*b.y-b.x*a.y;
}
inline bool onleft(const point &o,const point &a,const point &b){
	return cross(a-o,b-o)>eps;
}
///////////////////////////////////////////¿â 
int T;
int main(){
	scanf("%d",&T);
	while(T--){
		
	}
	return 0;
} 
