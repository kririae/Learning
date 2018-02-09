#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 1300000;
const int M = 200000*2+300000+9;

int n,m,head[N],nxt[M],to[M],dis[N];
deque<int> que;

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

inline void BFS() {
	memset(dis,-1,sizeof(dis));
	dis[1] = 0; que.push_back(1);
	
	while (!que.empty()) {
		int w = que.front(); que.pop_front();
		for (int i=head[w];i;i=nxt[i]) 
			if (w <= n) {
				if (!~dis[to[i]] || dis[to[i]] > dis[w] + 1) dis[to[i]] = dis[w] + 1, que.push_back(to[i]);
			} else {
				if (!~dis[to[i]] || dis[to[i]] > dis[w]) dis[to[i]] = dis[w], que.push_front(to[i]);
			}
		if (w > n) for (int i=0;i<=20;i++) if ((w-n)&(1<<i)) {
			int v = ((w-n)^(1<<i)) + n; if (v <= n) continue;
			if (!~dis[v] || dis[v] > dis[w]) dis[v] = dis[w], que.push_front(v);
		} 
	}
}

int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n = read(); m = read();
	for (int i=1,tmp;i<=n;i++) tmp = read(), Add_Edge(i,n+tmp), Add_Edge(n+tmp,i);
	for (int i=1,u,v;i<=m;i++) u = read(), v = read(), Add_Edge(u,v);
	BFS(); for (int i=1;i<=n;i++) printf("%d\n",dis[i]);
	return 0;
}

