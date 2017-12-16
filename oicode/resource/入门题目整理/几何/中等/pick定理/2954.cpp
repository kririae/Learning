#include<cstdio>
#include<cmath>
#include<iostream>
#define eps 1e-8
#define db int
using namespace std;
int abs(int a){
	if(a<0) return -a;return a;
}
struct point{db x,y;};
struct seg{point a,b;};
point dec(point a,point b){
	point ret;ret.x=a.x-b.x;ret.y=a.y-b.y;return ret;
}
db cross(point a,point b){
	return a.x*b.y-a.y*b.x;
}
bool equ(db a,db b){
	if(abs(a-b)<eps) return true;
	return false; 
}
int gcd(int a,int b){//a<b
	if(a>b) swap(a,b);
	if(a==0) return b;
	int c=b%a;
	if(c==0) return a;
	return gcd(c,a);
}

point p1,p2,p3;
bool cp(point a,point b){
	if(a.x==b.x&&a.y==b.y ) return true;
	return false;
}
bool pd(){
	if((p1.x==p2.x&&p2.x==p3.x)||(p1.y==p2.y&&p2.y==p3.y)) return true;
	if((cp(p1,p2))||cp(p2,p3)||cp(p1,p3)) return true;
	return false;
}
int main(){
	while(scanf("%d%d%d%d%d%d",&p1.x,&p1.y,&p2.x,&p2.y,&p3.x,&p3.y)==6){
		if(p1.x+p1.y+p2.x+p2.y+p3.x+p3.y==0) break;
		if(pd()){
			puts("0");continue;
		}
		int pone=0;int S=0;
		S=abs(cross(dec(p2,p1),dec(p3,p1)));
		pone+=gcd(abs(p1.x-p2.x ),abs(p1.y-p2.y ));
		pone+=gcd(abs(p2.x-p3.x ),abs(p2.y-p3.y ));
		pone+=gcd(abs(p3.x-p1.x ),abs(p3.y-p1.y ));
		printf("%d\n",(S+2-pone)/2);
	}
	return 0;
} 
