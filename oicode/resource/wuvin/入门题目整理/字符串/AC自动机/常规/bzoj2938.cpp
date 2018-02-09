#include<cstdio>
#include<queue>
#define N 30005
#define M 2
using namespace std;
int word[N];
int read(int p, int *b)
{
	char c = getchar();
	while(c == '\n' || c == '\r') c = getchar();
	while(c >= '0' && c <= '1') b[p++] = c - '0' + 1, c = getchar();
	return p;
}
//---------------------------
int root, n, cnt;
struct node {
	int val, p;
	int ne[M + 1];
} a[N];
void insert(int &k, int st, int en)
{
	if(k == 0) {
		k = ++cnt;
		a[k].p = st;
	}
	if(st == en) a[k].val = 1;
	else insert(a[k].ne[word[st + 1]], st + 1, en);
}
void pre()
{
	queue<int> p;
	for(int i = 0; i <= M; i++) {
		if(a[root].ne[i] == 0) a[root].ne[i] = 1;
		else a[a[root].ne[i]].ne[0] = root, p.push(a[root].ne[i]);
	}
	while(!p.empty()) {
		int u = p.front();
		p.pop();
		if(a[a[u].ne[0]].val == 1) a[u].val = 1;
		for(int i = 1; i <= M; i++) {
			if(a[u].ne[i] == 0) a[u].ne[i] = a[a[u].ne[0]].ne[i];
			else {
				a[a[u].ne[i]].ne[0] = a[a[u].ne[0]].ne[i];
				p.push(a[u].ne[i]);
			}
		}
	}
}
//----------------------------------
int vis[N];
bool DFS(int u)
{
	if(vis[u] == 1) return true;
	if(vis[u] == 2) return false;
	if(a[u].val == 1) return false;
	vis[u]++;
	for(int i = 1; i <= M; i++) {
		if(DFS(a[u].ne[i])) return true;
	}
	vis[u]++;
	return false;
}
int main()
{
	root = 1;
	cnt = 1;
	scanf("%d", &n);
	int p = 1;
	for(int i = 1; i <= n; i++) {
		int t = read(p, word);
		insert(root, p - 1, t - 1);
		p = t;
	}
	pre();
	if(DFS(root)) puts("TAK");
	else puts("NIE");
	return 0;
}
