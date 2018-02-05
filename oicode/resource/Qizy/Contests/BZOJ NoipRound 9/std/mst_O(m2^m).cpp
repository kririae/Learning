#include<bits/stdc++.h>
using namespace std;
const int maxn=10,maxm=20;
struct edge{
	int u,v,a,b;
}e[maxm];
int n,m;

void init(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;++i)
		scanf("%d%d%d%d",&e[i].u,&e[i].v,&e[i].a,&e[i].b);
}

struct union_find_set{
	int fa[maxn];
	void clear(int n){ for(int i=1;i<=n;++i) fa[i]=i; }
	int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]); }
	bool merge(int u,int v){
		int fx=find(u),fy=find(v);
		if(fx==fy) return false;
		fa[fx]=fy; return true;
	}
}ufs;
double calc(int state){
	double sa=0,sb=0; ufs.clear(n); int rest=n-1;
	for(int i=0;i<m;++i)
		if((state>>i)&1){
			sa+=e[i].a,sb+=e[i].b;
			if(!ufs.merge(e[i].u,e[i].v))
				return -1;
			--rest;
		}
	if(rest>0) return -1; return sqrt(sa*sa+sb*sb);
}

void solve(){
	double ans=-1;
	for(int i=0;i<(1<<m);++i)
		ans=max(ans,calc(i));
	printf("%.6f\n",ans);
}

int main(){
	freopen("mst.in","r",stdin);
	freopen("mst.out","w",stdout);
	init();
	solve();
	return 0;
}
