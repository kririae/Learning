#include<bits/stdc++.h>
using namespace std;

#define MAXN 1005

int T,A[MAXN][MAXN];
int n;

int dfn[MAXN],low[MAXN],tim,ins[MAXN],scc,stk[MAXN],top;

void tarjan(int v) {
	dfn[v]=++tim;low[v]=tim;
	stk[++top]=v;ins[v]=1;
	for(int i=1;i<=n;i++) {
		if(!A[v][i]) continue;
		if(!dfn[i]) {
			tarjan(i);low[v]=min(low[v],low[i]);
		}
		else if(ins[i]) low[v]=min(low[v],dfn[i]);
	}
	if(dfn[v]==low[v]) {
		while(ins[v]) ins[stk[top--]]=0;
		scc++;
	}
}

void Init() {
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	scc=tim=0;
}

int main() {
	
	freopen("life.in","r",stdin);
	freopen("life.out","w",stdout);
	
	scanf("%d",&T);
	while(T--) {
		Init();
		scanf("%d",&n);
		for(int i=1;i<=n;i++) 
			for(int j=1;j<=n;j++) 
				scanf("%d",&A[i][j]);
		for(int i=1;i<=n;i++)
			if(!dfn[i]) tarjan(i);
		if(scc==1) puts("YES");
		else puts("NO");
	}
	return 0;
}
