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
int cnt,fa[maxn],dfn[maxn],sz[maxn];
void dfs(int x){
	dfn[x]=++cnt; sz[x]=1;
	for (int p=now[x];p;p=pre[p])
		if (son[p]!=fa[x]) fa[son[p]]=x,dfs(son[p]),sz[x]+=sz[son[p]];
}
struct Tseg{
	int mx[maxn<<2];
	void clear(){memset(mx,-1,sizeof(mx));}
	void modify(int p,int l,int r,int a,int b,int v){
		if (v<mx[p] || a>b) return;
		if (l==a && r==b){mx[p]=max(mx[p],v); return;}
		int mid=(l+r)>>1;
		if (b<=mid) modify(p<<1,l,mid,a,b,v);
		else if (a>mid) modify(p<<1|1,mid+1,r,a,b,v);
		else modify(p<<1,l,mid,a,mid,v),modify(p<<1|1,mid+1,r,mid+1,b,v);
	}
	int Query(int p,int l,int r,int x){
		if (l==r) return mx[p];
		int mid=(l+r)>>1;
		if (x<=mid) return max(mx[p],Query(p<<1,l,mid,x));
		return max(mx[p],Query(p<<1|1,mid+1,r,x));
	}
	void modify(int x,int y,int v){
//		cout<<"Modify "<<x<<' '<<y<<' '<<v<<endl;
		if (!y) modify(1,1,n,dfn[x],dfn[x]+sz[x]-1,v);
		else modify(1,1,n,dfn[x],dfn[y]-1,v),modify(1,1,n,dfn[y]+sz[y],dfn[x]+sz[x]-1,v);
	}
	int Query(int x){return Query(1,1,n,dfn[x]);}
}t;
bool B[maxn];
void modify(int x){
	for (int last=0;x;last=x,x=fa[x]){
		t.modify(x,last,v[x]);
		if (B[x]) return; B[x]=1;
	}
}
void work(){
	cnt=0; dfs(1); memset(B,0,sizeof(B)); t.clear();
	for (int i=1;i<=m;++i){
		char op[10]; int x; scanf("%s%d",op,&x);
		if (op[0]=='M') modify(x);
		else printf("%d\n",t.Query(x));
	}
}
int main(){
	freopen("lca.in","r",stdin);
	freopen("lca.out","w",stdout);
	init();
	work();
	return 0;
}
