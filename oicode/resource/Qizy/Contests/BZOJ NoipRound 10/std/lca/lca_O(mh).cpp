#include<bits/stdc++.h>
using namespace std;
const int maxn=100011,maxm=200011;
int now[maxn],pre[maxm],son[maxm],tot=0;
void add(int a,int b){pre[++tot]=now[a]; now[a]=tot; son[tot]=b;}
void cc(int a,int b){add(a,b); add(b,a);}
int n,m,v[maxn];
void init(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i) scanf("%d",v+i);
	for (int i=1,a,b;i<n;++i) scanf("%d%d",&a,&b),cc(a,b);
}
int fa[maxn];
void dfs(int x){
	for (int p=now[x];p;p=pre[p]) if (son[p]!=fa[x]) fa[son[p]]=x,dfs(son[p]);
}
int t[maxn]; bool B[maxn];
void modify(int x){if (B[x]) return; B[x]=1; for (;x;x=fa[x]) ++t[x];}
int Query(int x){
	int ans=-1;
	for (int last=0;x;last=x,x=fa[x])
		if (t[x]!=t[last]) ans=max(ans,v[x]);
	return ans;
}
void work(){
	dfs(1);
	for (int i=1;i<=m;++i){
		char op[10]; int x; scanf("%s%d",op,&x);
		if (op[0]=='M') modify(x);
		else printf("%d\n",Query(x));
	}
}
int main(){
	freopen("lca.in","r",stdin);
	freopen("lca.out","w",stdout);
	init();
	work();
	return 0;
}
