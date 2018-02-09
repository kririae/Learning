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
void gao(double K){
	for (int i=1;i<=m;++i) e[i].s=K*e[i].a;
	sort(e+1,e+m+1,cmp_s); double A=0;
	for (int i=1;i<=n;++i) fa[i]=i;
	for (int i=1,cnt=1;i<=m;++i){
		if (find(e[i].u)!=find(e[i].v)){
			fa[find(e[i].u)]=find(e[i].v);
			A+=e[i].a;
			if (++cnt==n){ans=max(ans,A*A); return;}
		}
	}
}
void work(){
	gao(+1),gao(-1);
	if (ans<0) puts("-1");else printf("%.6f\n",sqrt(ans));
}
int main(){
	freopen("mst.in","r",stdin);
	freopen("mst.out","w",stdout);
	init();
	work();
	return 0;
}

