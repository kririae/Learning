#include<bits/stdc++.h>
using namespace std;
const int maxn=100011,maxm=200011;
int tot=0,now[maxn],pre[maxm],son[maxm],v[maxn];
void add(int a,int b){pre[++tot]=now[a]; now[a]=tot; son[tot]=b;}
void cc(int a,int b){add(a,b); add(b,a);}
int n,m;
void init(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i) scanf("%d",v+i);
	for (int i=1,a,b;i<n;++i) scanf("%d%d",&a,&b),cc(a,b);
}
int fa[maxn],dep[maxn];
void dfs(int x){
	for (int p=now[x];p;p=pre[p]) if (son[p]!=fa[x])
		fa[son[p]]=x,dep[son[p]]=dep[x]+1,dfs(son[p]);
}
int lca(int a,int b){
	while (dep[a]!=dep[b])
		if (dep[a]>dep[b]) a=fa[a];else b=fa[b];
	while (a!=b) a=fa[a],b=fa[b]; return a;
}
void work(){
	dep[1]=1; fa[1]=0; dfs(1);
	static vector<int> p; p.clear();
	for (int i=1;i<=m;++i){
		char op[10]; int x; scanf("%s%d",op,&x);
		if (op[0]=='M'){
			p.push_back(x);
			for (unsigned int i=0;i+1<p.size();++i)
				if (p[i]==x){p.pop_back(); break;}
		}else{
			int res=-1;
			for (unsigned int i=0;i<p.size();++i)
				res=max(res,v[lca(x,p[i])]);
			printf("%d\n",res);
		}
	}
}
int main(){
	freopen("lca.in","r",stdin);
	freopen("lca.out","w",stdout);
	init();
	work();
	return 0;
}

