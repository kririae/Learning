#include<cstdio>
#include<queue>
#include<cmath>
#include<cstdlib>
#define db double
using namespace std;
struct point{double x,y,ans;};
inline double dis(point &a,point &b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
inline bool operator <(const point &a,const point &b){
	return a.ans>b.ans;
}
point p[105];
int n;
int sx[4]={1,0,-1,0};
int sy[4]={0,1,0,-1};
inline void count(point &a){
	double dans=0;
	for(int i=1;i<=n;i++){
		dans+=dis(a,p[i]);
	}
	a.ans=dans;
	return;
}
double ans=1e10;
double xx,yy;
void tuihuo(){
	point start=(point){xx/(double)n,yy/(double)n,0};
	queue<point> pq;
	count(start);
	ans=start.ans;
	pq.push(start);
	int t=10000;
	while(t>800){
		point po=pq.front();point p2;
		pq.pop();
		int flag=0;
		for(int j=0;j<4;j++){
			p2.x=po.x+sx[j]*t/2000.0;
			p2.y=po.y+sy[j]*t/2000.0;
			count(p2);
			if(p2.ans>po.ans){
				/*flag++; ÍË»ð/ÅÀÉ½ 
				if(p2.ans>po.ans*3) continue;
				if(!(rand()<(t>>1))){
					continue;
				}*/
				continue;
			}
			flag=1;
			if(p2.ans<ans) 
				ans=p2.ans;
			pq.push(p2);
		}
		if(flag==0) pq.push(po);
		t--;
	}
}
void init(){
	xx=0;yy=0;
	for(int i=1;i<=n;i++){
		scanf("%lf%lf",&p[i].x,&p[i].y);
		xx+=p[i].x;yy+=p[i].y;
	}
}
int main(){
	while(scanf("%d",&n)==1&&n){
		init();
		ans=1e10;
		tuihuo();
		printf("%.0f\n",ans);
	}
	return 0;
} 
