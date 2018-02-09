#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 5+9;
const int M = 20+9;

int n,m,sta[M],scc_num[N],lowlink[N],num[N],tot;
int to[M],nxt[M],head[N],scc_cnt,vout;
stack<int> stk;
 
inline int read(){
	char c=getchar(); int ret=0,f=1;
	while (c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while (c<='9'&&c>='0') {ret=ret*10+c-'0';c=getchar();}
	return ret*f;
}

inline void Add_Edge(int u, int v) {
	static int T = 0;
	to[++T] = v; nxt[T] = head[u]; head[u] = T;
}

void DFS(int w) {
	lowlink[w] = num[w] = ++tot; stk.push(w);
	for (int i=head[w];i;i=nxt[i]) if (sta[i]) {
		if (!num[to[i]]) {
			DFS(to[i]);
			lowlink[w] = min(lowlink[w], lowlink[to[i]]);
		} else if (!scc_num[to[i]]) {
			lowlink[w] = min(lowlink[w], num[to[i]]);
		}
	}
	if (lowlink[w] == num[w]) {
		scc_cnt++;
		while (true) {
			int wn = stk.top(); stk.pop();
			scc_num[wn] = scc_cnt;
			if (w == wn) break;
		}
	} 
}

inline bool judge() {
	scc_cnt = tot = 0;
	memset(scc_num,0,sizeof(scc_num));
	memset(lowlink,0,sizeof(lowlink));
	memset(num,0,sizeof(num));
	for (int i=1;i<=n;i++) if (!num[i]) {
		DFS(i);
	} 
	return scc_cnt == n; 
}

void search(int t) {
	if (t == m + 1) {
		if (judge()) vout++;
	} else {
		sta[t] = 1; search(t+1);
		sta[t] = 0; search(t+1); 
	}
}

int main(){
	freopen("obelisk.in","r",stdin);
	freopen("obelisk.out","w",stdout);
	n = read(); m = read();
	for (int i=1,a,b;i<=m;i++) {
		a = read(); b = read();
		Add_Edge(a,b);
	}
	search(1);
	printf("%d\n",vout);
	return 0;
}

