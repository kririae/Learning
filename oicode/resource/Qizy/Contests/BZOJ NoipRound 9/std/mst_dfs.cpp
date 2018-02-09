#include<bits/stdc++.h>
using namespace std;
const int maxn=20,maxm=210;
const double inf=1e9;
struct edge{
	int u,v; double a,b,dis;
}e[maxm];
int n,m; double ans;

void init(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d%lf%lf",&e[i].u,&e[i].v,&e[i].a,&e[i].b);
		e[i].dis=sqrt(e[i].a*e[i].a+e[i].b*e[i].b);
	}
}

struct union_find_set{
	int fa[maxn];
	void clear(){ memset(fa,0,sizeof(fa)); }
	int find(int x){ return !fa[x]?x:fa[x]=find(fa[x]); }
	bool merge(int u,int v){
		int fx=find(u),fy=find(v);
		if(fx==fy) return false;
		fa[fx]=fy; return true;
	}
}ufs,tmp;
double eval(int dep,int rest){
	tmp=ufs; double ans=0;
	for(int i=dep;i<=m;++i){
		if(m-i+1<rest) return -inf;
		if(!rest) break;
		if(tmp.merge(e[i].u,e[i].v))
			--rest,ans+=e[i].dis;
	}
	if(rest>0) return -inf; return ans;
}
void dfs(int dep,int rest,double sa,double sb){
	double now=sqrt(sa*sa+sb*sb);
	if(m-dep+1<rest) return;
	if(now+eval(dep,rest)<=ans) return;
	if(!rest){ ans=now; return; }
	if(rest>0){
		int fx=ufs.find(e[dep].u),fy=ufs.find(e[dep].v);
		if(fx!=fy){
			union_find_set bak=ufs;
			ufs.fa[fx]=fy;
			dfs(dep+1,rest-1,sa+e[dep].a,sb+e[dep].b);
			ufs=bak;
		}
	}
	dfs(dep+1,rest,sa,sb);
}

bool cmp_dis(const edge &A,const edge &B){ return A.dis>B.dis; }
void solve(){
	sort(e+1,e+m+1,cmp_dis);
	ufs.clear(),ans=-1;
	dfs(1,n-1,0,0);
	if(ans<0) puts("-1"); else printf("%.6f\n",ans);	
}

int main(){
	freopen("mst.in","r",stdin);
	freopen("mst.out","w",stdout);
	init();
	solve();
	return 0;
}
