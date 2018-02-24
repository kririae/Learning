#include<cstdio>
#include<cmath>
#include<algorithm>
#define for(a,b,c) for(int i=a;i<=b;c)
#define eps 1e-8
#define INF 999999
using namespace std;
struct point{
	double x,y;
	point(int x_,int y_){
		x=x_;y=y_;
	}
};
int cmp(double a,double b){
	if(abs(a-b)<eps) return 0;
	if(a-b>0) return 1;//>
	return -1;//<
} 
struct line{
	double a,b;
	int name;
	double get_intersection(const line& c){//return x
		if(cmp(a,c.a)==0) return INF;
		double x=(c.b-b)/(a-c.a);
		return x;
	}
	bool operator <(const line& c)const{
		if(cmp(a,c.a)==0){
			return cmp(b,c.b)>0;
		}else{
			return cmp(a,c.a)<0;
		}
	}
};
line ls[50005];
int n;
int ans[50005];
double jd[50005];
int cnt_ans=0;
int cnt_jd=0;
void add(int xd,double x){
	ans[cnt_ans++]=xd;
	jd[cnt_jd++]=x;
}
void pop(){
	cnt_ans--;cnt_jd--;
}
bool cmp1(const int a,const int b){
	return ls[a].name<ls[b].name;
}
int main(){
	scanf("%d",&n);
	for(1,n,i++){
		scanf("%lf%lf",&ls[i].a,&ls[i].b);
		ls[i].name=i;
	}
	sort(ls+1,ls+n+1);
	add(1,-INF);
	for(2,n,i++){
		if(cmp(ls[i].a,ls[ans[cnt_ans-1]].a)==0) continue; 
		while(cmp(ls[ans[cnt_ans-1]].get_intersection(ls[i]),jd[cnt_jd-1])<=0) pop();
		add(i,ls[ans[cnt_ans-1]].get_intersection(ls[i]));
	}
	sort(ans,ans+cnt_ans,cmp1);
	for(0,cnt_ans-1,i++){
		printf("%d ",ls[ans[i]].name);
	}
	return 0;
} 
