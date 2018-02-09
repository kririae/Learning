#include<bits/stdc++.h>
using namespace std;
const int maxn=100011,maxm=200011;
int now[maxn],pre[maxm],son[maxm],tot=1;
void add(int a,int b){pre[++tot]=now[a]; now[a]=tot; son[tot]=b;}
void cc(int a,int b){add(a,b); add(b,a);}
int n,m,v[maxn];
void init(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i) scanf("%d",v+i);
	for (int i=1,a,b;i<n;++i) scanf("%d%d",&a,&b),cc(a,b);
}
int B[maxn]; int ans[maxn],f[maxn];
void prepare(int x,int fa){
	for (int p=now[x];p;p=pre[p]) if (son[p]!=fa)
		prepare(son[p],x),B[x]+=B[son[p]];
}
void getans(int x,int fa){
	for (int p=now[x];p;p=pre[p]) if (son[p]!=fa){
		if (B[x]!=B[son[p]]) ans[son[p]]=max(ans[x],v[x]);
		else ans[son[p]]=ans[x];
		getans(son[p],x);
	}
	if (B[x]) ans[x]=max(ans[x],v[x]);
}
void work(){
	char op[10]; int x; 
	for (int i=1;i<=m;++i){
		scanf("%s",op);
		if (op[0]!='M') break;
		scanf("%d",&x); B[x]=1;
	}
	prepare(1,0); ans[1]=-1; getans(1,0);
	while (scanf("%d",&x)!=EOF)
		printf("%d\n",max(f[x],ans[x])),scanf("%s",op);
}
int main(){
	freopen("lca.in","r",stdin);
	freopen("lca.out","w",stdout);
	init();
	work();
	return 0;
}
