//有三点共线 
/*
附上一组特卡数据
1 0 3 2 2 1
5
5 4
4 3
2 0
3 0
4 0


0
0
4
8
12
rank1 不错不错 
*/
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<set>
#define LL long long
#define db long long
#define eps 1e-8
using namespace std;
inline int abs(int a){
	return a<0? -a:a;
}
inline int read(){
	char c=getchar();int ret=0,f=1;
	while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') ret=ret*10+c-'0',c=getchar();
	return ret*f;
}
struct point{int x,y;};
inline point operator -(const point &a,const point &b){
	return (point){a.x-b.x,a.y-b.y};
}
inline db cross(point a,point b){
	return a.x*(LL)b.y-b.x*(LL)a.y;
}
inline bool onleft(const point &o,const point &a,const point &b){
	return cross(a-o,b-o)>-eps;
} 
//--------------------------------------
db ans;
point base;//0，0 
double xx,yy; 
struct node{
	double angle;
	point p;
	bool operator <(const node &b)const{
		return angle<b.angle;
	}
};
set<node> st;
inline void insert(point p){//当点与在凸包外时会错 so还是浮点坐标避免共线_浮点卡精度 
	set<node>::iterator l,r,ll,rr;
	node t=(node){atan2(p.y-yy,p.x-xx),p};
	l=st.lower_bound(t);
	if(l==st.end()){
		r=l;r--;l=st.begin();
	}else if(l==st.begin()){
		r=st.end();r--;
	}else{
		r=l;r--;
	}
	if(onleft((*r).p,(*l).p,p)) return;
	ans-=cross((*r).p,(*l).p);
	while(1){
		ll=l;ll++;
		if(ll==st.end()) ll=st.begin();
		if(onleft((*l).p,(*ll).p,p)) break;
		ans-=cross((*l).p,(*ll).p);
		st.erase(l);
		l=ll;
	}
	ans+=cross(p,(*l).p);
	while(1){
		rr=r;
		if(rr==st.begin()) rr=st.end(),rr--;
		else rr--;
		if(onleft((*rr).p,(*r).p,p)) break;
		ans-=cross((*rr).p,(*r).p);
		st.erase(r);
		r=rr;
	}
	ans+=cross((*r).p,p);
	st.insert(t);
}
//--------------------------------------
int n;
int le,ri; 
int main(){
	int x1,y1,x2,y2,x3,y3;
	x1=read();y1=read();x2=read();y2=read();x3=read();y3=read();
	xx=(x1+x2+x3)/3.0;yy=(y1+y2+y3)/3.0;
	point p1=(point){x1,y1},p2=(point){x2,y2},p3=(point){x3,y3};
	ans=abs(cross(p2-p1,p3-p1));
	if(ans!=0){
		st.insert((node){atan2(p1.y-yy,p1.x-xx),p1});
		st.insert((node){atan2(p2.y-yy,p2.x-xx),p2});
		st.insert((node){atan2(p3.y-yy,p3.x-xx),p3});
	}else{//三点共线 
		point buf=p1.x<p2.x? p1:p2;
		buf=buf.x<p3.x? buf:p3;
		base=buf;
		buf=p1.x>p2.x? p1:p2;
		buf=buf.x>p3.x? buf:p3;
		p1=buf; 
	}
	n=read();
	for(int i=1;i<=n;i++){
		x1=read();y1=read();
		if(ans==0){
			point buf=(point){x1,y1};
			ans=abs(cross(p1-base,buf-base));
			if(ans!=0){
				xx=(p1.x+buf.x+base.x)/3.0;
				yy=(p1.y+buf.y+base.y)/3.0;
				st.insert((node){atan2(base.y-yy,base.x-xx),base});
				st.insert((node){atan2(p1.y-yy,p1.x-xx),p1});
				st.insert((node){atan2(buf.y-yy,buf.x-xx),buf});
			}else{
				if(buf.x<base.x) base=buf;
				else if(buf.x>p1.x) p1=buf;
			}
		}else	insert((point){x1,y1});
		printf("%lld\n",ans);
	}
	return 0;
}
