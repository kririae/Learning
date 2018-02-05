#include<bits/stdc++.h>
using namespace std;
const int maxn=55,maxm=211;
struct cpx{
	int x,y;
	cpx(){}
	cpx(int _x,int _y):x(_x),y(_y){}
};
ostream& operator<<(ostream& os,cpx a){cout<<'('<<a.x<<','<<a.y<<')'; return os;}
cpx operator+(cpx a,cpx b){return cpx(a.x+b.x,a.y+b.y);}
cpx operator-(cpx a,cpx b){return cpx(a.x-b.x,a.y-b.y);}
int operator*(cpx a,cpx b){return a.x*b.y-a.y*b.x;}
struct Tedge{
	int a,b,V; cpx v;
}e[maxm];
int n,m,ans;
void init(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i) scanf("%d%d%d%d",&e[i].a,&e[i].b,&e[i].v.x,&e[i].v.y);
}
int fa[maxn];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
inline bool cmp_V(Tedge a,Tedge b){return a.V>b.V;}
cpx mst(int vx,int vy){
	for (int i=1;i<=m;++i) e[i].V=vx*e[i].v.x+vy*e[i].v.y;
	sort(e+1,e+m+1,cmp_V); cpx s=cpx(0,0);
	for (int i=1;i<=n;++i) fa[i]=i;
	for (int i=1,cnt=1;i<=m;++i){
		if (find(e[i].a)==find(e[i].b)) continue;
		fa[find(e[i].a)]=find(e[i].b);
		s=s+e[i].v;
		if (++cnt==n){ans=max(ans,s.x*s.x+s.y*s.y); return s;}
	}
	assert(false);
}
void solve(cpx a,cpx b){
	cpx mid=mst(b.y-a.y,a.x-b.x);
	if ((mid-a)*(b-a)==0) return;
//	cout<<a<<' '<<b<<' '<<mid<<endl; getchar();
	solve(a,mid); solve(mid,b);
}
void work(){
	ans=0; cpx a=mst(-1000000,1),b=mst(1000000,-1);
//	cout<<'A'<<endl;
	solve(a,b);
//	cout<<'B'<<endl;
	solve(b,a);
	printf("%.6f\n",sqrt(ans));
}
int main(){
	freopen("mst.in","r",stdin);
	freopen("mst.out","w",stdout);
	init();
	work();
	return 0;
}
