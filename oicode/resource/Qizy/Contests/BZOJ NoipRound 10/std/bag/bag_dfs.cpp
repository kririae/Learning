#include<bits/stdc++.h>
using namespace std;
const int maxn=10,maxv=111;
int n,m,v[maxn],V0,C;
void init(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i){
		scanf("%d",v+i);
		if (v[i]>100) i--,n--;
	}
	sort(v+1,v+n+1); n=unique(v+1,v+n+1)-v-1;
	reverse(v+1,v+n+1); scanf("%d%d",&V0,&C);
}
bool F[111];
int Limit;
void dfs(int x,int C,int s){
	F[s]=1; if (x>n) return;
	if (v[x]>=V0)
		for (int i=0;i<=C && s<=Limit;++i,s+=v[x]) dfs(x+1,C-i,s);
	else for (;s<=Limit;s+=v[x]) dfs(x+1,0,s);
}
void work(){
	Limit=100; memset(F,0,sizeof(F));
	if (n>=2 && v[n-1]<V0) Limit=min(Limit,v[n-1]*v[n]-v[n]-v[n-1]);
	dfs(1,C,0);
	while (m--){
		int x; scanf("%d",&x);
		puts((x>Limit || F[x])?"Yes":"No");
	}
}
int main(){
	freopen("bag.in","r",stdin);
	freopen("bag.out","w",stdout);
	init();
	work();
	return 0;
}
