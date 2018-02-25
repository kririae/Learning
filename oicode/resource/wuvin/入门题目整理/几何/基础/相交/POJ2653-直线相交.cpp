#include<cstdio>
#include<cmath>
#define eps 1e-8
#define db double
/*
¶ÁÈëµÄbug 
*/
using namespace std;
struct point{db x,y;};
struct seg{point a,b;};
inline point dec(point a,point b){
	point ret;ret.x=a.x-b.x;ret.y=a.y-b.y;return ret;
}
inline db cross(point a,point b){
	return a.x*b.y-a.y*b.x;
}
inline bool equ(db a,db b){
	if(abs(a-b)<eps) return true;
	return false; 
}
const int L=1,R=0;
inline db side(point &a,seg &b){
	point a1=dec(a,b.b);
	point a2=dec(b.a,b.b);
	return cross(a2,a1);
}
inline bool inter(seg &a,seg &b){
	if(side(a.a,b)*side(a.b,b)<0){
		if(side(b.a,a)*side(b.b,a)<0){
			return true;
		}
	}
	return false;
}
int n;
seg xd[100005];
int que[100005];
int cnt=0;
int main(){
	while((scanf("%d",&n)==1)&&n){
		for(int i=1;i<=n;i++){
			scanf("%lf%lf%lf%lf",&xd[i].a.x,&xd[i].a.y,&xd[i].b.x,&xd[i].b.y);
		}
		cnt=0;
		for(int i=1;i<=n;i++){
			int p=0;
			for(int j=0;j<cnt;j++){
				if(!inter(xd[i],xd[que[j]])){
					que[p++]=que[j];
				}
			}
			que[p++]=i;cnt=p;
		}
		printf("Top sticks: %d",que[0]);
		for(int i=1;i<cnt;i++){
			printf(", %d",que[i]);
		}
		puts(".");
	}
	return 0;
} 
