#include<cstdio>
#include<cmath>
#include<algorithm>
#define N 2005
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
db getS(point &a,point &b,point &c){
	return abs(cross(dec(a,b),dec(c,b)))/2;
}




point p[N];
int n;
db ans=0;
struct xl{
	double  k;
	int from,to;//from>to
	inline bool operator <(const xl &b)const{
		return k<b.k;
	}
}x[N*N];
int ip[N],pi[N];//index to place  /place to index
bool cmp1(const int &a,const int &b){
	if(equ(p[a].x,p[b].x)){
		return p[a].y>p[b].y;
	}
	p[a].x<p[b].x;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lf%lf",&p[i].x,&p[i].y);
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			x[cnt].k=(p[i].y-p[j].y)/(p[i].x-p[j].x);//double inf
			x[cnt].from=i;x[cnt].to=j;cnt++;
		}
	}
	sort(x,x+cnt);
	for(int i=1;i<=n;i++) pi[i]=i;
	sort(pi+1,pi+n+1,cmp1);
	for(int i=1;i<=n;i++) ip[pi[i]]=i;
	for(int i=0;i<cnt;i++){
		int f=x[i].from;int t=x[i].to;//f<t;
		if(ip[f]>ip[t]) swap(f,t);
		db an1=getS(p[f],p[t],p[pi[1]])+getS(p[f],p[t],p[pi[n]]);
		if(an1>ans) ans=an1;
		swap(pi[ip[f]],pi[ip[t]]);
		swap(ip[f],ip[t]);
	}
	printf("%.3lf",ans);
	return 0;
} 
