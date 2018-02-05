#include<bits/stdc++.h>
using namespace std;
const int maxn=55,maxm=211;
struct Tedge{
	int u,v; double a,b,s;
}e[maxm];
int n,m;
void init(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i) scanf("%d%d%lf%lf",&e[i].u,&e[i].v,&e[i].a,&e[i].b);
}
inline bool cmp_s(Tedge a,Tedge b){return a.s>b.s;}
int fa[maxn];
inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
double ans;
void gao(double a){
	double cs=cos(a),sn=sin(a);
	for (int i=1;i<=m;++i) e[i].s=e[i].a*cs+e[i].b*sn;
	sort(e+1,e+m+1,cmp_s); double A=0,B=0;
	for (int i=1;i<=n;++i) fa[i]=i;
	for (int i=1,cnt=1;i<=m;++i){
		if (find(e[i].u)!=find(e[i].v)){
			fa[find(e[i].u)]=find(e[i].v);
			A+=e[i].a; B+=e[i].b;
			if (++cnt==n){ans=max(ans,A*A+B*B); return;}
		}
	}
}
void work(){
	static double f[maxm*maxm*2]; int M=0; ans=-1;
	for (int i=1;i<=m;++i) for (int j=i+1;j<=m;++j){
		double x1=e[i].a,y1=e[i].b,x2=e[j].a,y2=e[j].b;
		if (y1>y2) swap(x1,x2),swap(y1,y2);
		if (y1==y2){f[++M]=M_PI/2,f[++M]=-M_PI/2; continue;}
		f[++M]=atan((x1-x2)/(y2-y1)); f[M+1]=f[M]+M_PI; ++M;
	}
	f[++M]=-M_PI/2; f[++M]=M_PI*5/2;
	sort(f+1,f+M+1);
	M=unique(f+1,f+M+1)-f-1;
	for (int i=1;i<=M;++i) gao((f[i]+f[i-1])/2);
	if (ans<0) puts("-1");else printf("%.6f\n",sqrt(ans));
}
int main(){
	freopen("mst.in","r",stdin);
	freopen("mst.out","w",stdout);
	init();
	work();
	return 0;
}

