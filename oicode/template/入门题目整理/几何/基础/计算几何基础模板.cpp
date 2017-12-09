#include<cstdio>
#include<cmath>
#define eps 1e-8
#define db double
using namespace std;
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

int main(){
	
	return 0;
} 
