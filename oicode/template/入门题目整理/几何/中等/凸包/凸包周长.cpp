#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#define TT long double
using namespace std;
const long double eps=1e-8;
struct point{
	TT x,y;
	point(TT xx,TT yy){
		x=xx;y=yy;
	}
	point(){}
	bool operator <(const point &b)const{
		if(x==b.x) return y<b.y;
		return x<b.x;
	}
};
struct vec{
	TT x,y;
	vec(TT xx,TT yy){
		x=xx;y=yy;
	}
	vec(point b){//o->b
		x=b.x;y=b.y;
	}
	vec(point a,point b){//a->b
		x=b.x-a.x;y=b.y-a.y;
	}
	TT theta(){//get the rdx
		return atan2(y,x);
	}
};
TT cross(vec a,vec b){//以a为参照 
	return a.x*b.y-a.y*b.x;
}
TT dot(vec &a,vec &b){
	return a.x*b.x+a.y*b.y;
}
point map[100005];
int n;TT s;//周长 
vector<point> x;
void xtb(){//下凸包 
	x.push_back(map[1]);int len=1;
	for(int i=2;i<=n;i++){//待加入点
		while(len!=1&&cross(vec(x[len-2],x[len-1]),vec(x[len-1],map[i]))<eps){
			x.pop_back();len--;
		}
		x.push_back(map[i]);len++;
	}
	return;
}
void stb(){//上凸包 
	int bt=x.size();
	int len=bt;
	for(int i=n-1;i>=1;i--){
		while(len!=bt&&cross(vec(x[len-2],x[len-1]),vec(x[len-1],map[i]))<eps){
			x.pop_back();len--;
		}
		x.push_back(map[i]);len++;
	}
	return;
}
point check[5005];
int main(){
	scanf("%d",&n);
	for(int a,b,i=1;i<=n;i++){
		scanf("%d%d",&a,&b);map[i].x=a;map[i].y=b;
	}
	//特处 n=1\2 
	if(n==1){
		printf("0.0");return 0;
	}else if(n==2){
		s=2*sqrt((map[2].x-map[1].x)*(map[2].x-map[1].x)+(map[2].y-map[1].y)*(map[2].y-map[1].y));
		printf("%.1f",(float)s);
		return 0;
	}
	sort(map+1,map+n+1);
	xtb();
	stb();
	for(int i=0,len=x.size();i<len;i++){
		check[i]=x[i];
	}
	for(int i=1,len=x.size();i<len;i++){
		s+=sqrt((x[i].x-x[i-1].x)*(x[i].x-x[i-1].x)+(x[i].y-x[i-1].y)*(x[i].y-x[i-1].y));
	}
	printf("%.1f",(float)s);
	return 0;
}
