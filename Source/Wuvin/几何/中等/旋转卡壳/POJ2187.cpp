#include<cstdio>
#define eps 1e-8
#define db int
#include<algorithm> 
using namespace std;
struct point{
	db x,y;
	bool operator <(const point &b)const{
		if(x!=b.x) return x<b.x;
		return y<b.y;
	}
};
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
db sqr_dis(point &a,point &b){
	point buf=dec(a,b);
	return buf.x*buf.x+buf.y*buf.y;
}
db getS(point &p,point &l1,point &l2){
	return abs(cross(dec(p,l1),dec(l2,l1)));
}
db abs(db a){
	if(a<0) return -a;
	return a;
}

int n;
int cnt;
point p[50005];
int tb[50005];
void init(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&p[i].x,&p[i].y);
	}
}
void add_point(int a,int limit){//åŠ å…¥ä¸€ç‚¹
	if(cnt>0){
		if(p[tb[cnt-1]].x==p[a].x&&p[tb[cnt-1]].y==p[a].y) return;
	}
	if(cnt<limit){
		tb[cnt++]=a;return;
	}
	if(cross(dec(p[tb[cnt-1]],p[tb[cnt-2]]),dec(p[a],p[tb[cnt-1]]))>0){
		tb[cnt++]=a;
	}else{
		cnt--;add_point(a,limit);
	}
}
void get_tb(){//æ±‚å‡¸åŒ…
	sort(p+1,p+n+1);cnt=0;
	for(int i=1;i<=n;i++){
		add_point(i,2);
	}
	int p1=cnt;
	for(int i=n-1;i>=1;i--){
		add_point(i,p1+1);
	}
	return;
}
db ans=0;
void kq(){
	int q=1;cnt--;
	for(int i=0;i<cnt;i++){//Ã¶¾Ù±ß(i,i+1) ÓÃÃæ»ý´úÌæµãµ½Ïß¾àÀë 
		if(q==cnt) q=0;//²»ÄÜbreak 
		db dis=getS(p[tb[q]],p[tb[i]],p[tb[i+1]]);//Ó¦¸Ã¿ÉÒÔ²»ÓÃabs 
		while(q<cnt){
			int newans=max(sqr_dis(p[tb[q]],p[tb[i]]),sqr_dis(p[tb[q]],p[tb[i+1]]));
			if(newans>ans) ans=newans;
			db dis2=getS(p[tb[q+1]],p[tb[i]],p[tb[i+1]]);
			if(dis2<dis){
				break;
			}
			q++;dis=dis2;
		}
	}
}
int main(){
	init();
	get_tb();
	kq();//æ—‹è½¬å¡å£³
	printf("%d",ans);
	return 0;
} 
