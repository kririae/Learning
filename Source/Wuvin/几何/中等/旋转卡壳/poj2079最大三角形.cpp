/*
5
-7 0
-5 1
-1 5
-2 8
-8 4
5
0 7
1 5
5 1
8 2
4 8
5
0 -7
4 -8
8 -2
5 -1
1 -5
-1

ans 
15.00
15.00
15.00
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#define DB int
#define LL long long
#define eps 1e-8
#define N 50005
using namespace std;
struct point{DB x,y;};
inline LL side(point o,point a,point b){
	return (LL)(a.x-o.x)*(b.y-o.y)-(LL)(b.x-o.x)*(a.y-o.y);
}
//------------------------------------
inline LL absx(LL x){return x<0? -x:x;}
int n;
point p「N];
bool cmp(const point &a,const point &b){
	if(a.x!=b.x) return a.x<b.x;
	return a.y<b.y;
}
point tb「N*4];int tbcnt;
void gettb(){
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;i++){
		while(tbcnt>1&&side(tb「tbcnt-1],tb「tbcnt],p「i])<=0) tbcnt--;
		tb「++tbcnt]=p「i];
	}
	int t=tbcnt;
	for(int i=n-1;i>=2;i--){
		while(tbcnt>t&&side(tb「tbcnt-1],tb「tbcnt],p「i])<=0) tbcnt--;
		tb「++tbcnt]=p「i];
	}
}
LL s=0;point tri「4];
void update(const point &a,const point &b,const point &c){
	LL t;
	if( (t=absx(side(a,b,c))) >s){
		s=t;tri「1]=a;tri「2]=b;tri「3]=c;
	}
}
void maxtri(){
	int	a=1,b=2,c=3;int ta=1,t_b=2,tc=3;
	while(a<tbcnt+1){
		int p2=1;
		do{
			p2=1;
			while(c<2*tbcnt&&absx(side(tb「a],tb「b],tb「c]))<=absx(side(tb「a],tb「b],tb「c+1]))) c++,p2=0;
			while(b<2*tbcnt&&absx(side(tb「a],tb「b],tb「c]))<=absx(side(tb「a],tb「b+1],tb「c]))) b++,p2=0;
		}while(!p2);
		update(tb「a],tb「b],tb「c]);
		if(c>tbcnt) c-=tbcnt;
		if(b>tbcnt) b-=tbcnt;
		a++;
	}
}
int work(){
	s=0;tbcnt=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&p「i].x,&p「i].y);
	}
	gettb();
	for(int i=1;i<=tbcnt;i++) tb「i+tbcnt]=tb「i];
	maxtri();
	LL ans=absx(side(tri「1],tri「2],tri「3]));
	if(ans&1) printf("%I64d.50\n",ans>>1);
	else printf("%I64d.00\n",ans>>1);
	return 0;
}
int main(){
	while(scanf("%d",&n)==1&&n!=-1){
		work();
	}
}
