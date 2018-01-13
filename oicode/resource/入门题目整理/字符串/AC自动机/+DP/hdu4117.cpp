#include<cstdio>
#include<iostream>
#include<vector>
#define N 20005
#define M 270005
using namespace std;
struct words {
	int st, en, dp; //[]
} w[N];
struct group {
	int st, en, root; //??¡Á¨¦¦Ì?¡Á?¡¤???¦Ì??e¨º?¦Ì?o¨ª?D¦Ì?
} fenz[16]; //2^k ¡¤?¡Á¨¦ ????????¡¤?¡Á¨¦¦Ì?root
int word[M + 30000];
int n, ans;
const int lim = (1 << 18) - 1;
//--------AC-----------
struct AC {
	int val;
	int picked;
	int ne[27];
} a[M];
int cnt;
//------?¨²??¡¤???--------
int free_wkl[M];
int free_top;
void push(const int &k)
{
	free_wkl[++free_top] = k;
}
int pop()
{
	if(free_top == 0) return ++cnt;
	int t = free_wkl[free_top];
	//if(a[t].picked==1){
	a[t].val = a[t].picked = 0;
	for(int i = 0; i <= 26; i++) a[t].ne[i] = 0;
	//}
	return free_wkl[free_top--];
}
//---------read---------
inline int read(int p, int *b)
{
	char c = getchar();
	while(c < 'a' || c > 'z') c = getchar();
	while(c >= 'a' && c <= 'z') b[++p] = c - 'a' + 1, c = getchar();
	return p;
}
//--------AC------------
void insert(int &k, int st, int en, int val)
{
	if(k == 0) {
		k = pop();
	}
	if(st == en) a[k].val = max(a[k].val, val);
	else insert(a[k].ne[word[st + 1]], st + 1, en, val);
}
//--------------------------
int q[lim + 2];
int l, r;
inline bool q_empty()
{
	return l == r;
}
inline void q_push(const int &x)
{
	r &= lim;
	q[r++] = x;
}
inline int q_pop()
{
	l &= lim;
	return q[l++];
}
//--------------------------
inline void pre_fail(int root)
{
	//queue<int> q;
	l = r = 0;
	for(int i = 0; i <= 26; i++) {
		if(a[root].ne[i] == 0) a[root].ne[i] = root;
		else a[a[root].ne[i]].ne[0] = root, q_push(a[root].ne[i]);
	}
	while(!q_empty()) {
		//int u=q.front();q.pop();
		int u = q_pop();
		a[u].val = max(a[u].val, a[a[u].ne[0]].val);
		for(int i = 1; i <= 26; i++) {
			if(a[u].ne[i] == 0) a[u].ne[i] = a[a[u].ne[0]].ne[i];
			else a[a[u].ne[i]].ne[0] = a[a[u].ne[0]].ne[i], q_push(a[u].ne[i]);
		}
	}
}
inline int check(int root, int st, int en)
{
	int ret = 0;
	for(int p2 = st, p = root; p2 <= en; p2++) {
		p = a[p].ne[word[p2]];
		ret = max(ret, a[p].val);
	}
	return ret;
}
void pickup(int u) //destroy
{
	a[u].picked = 1;
	push(u);
	for(int i = 1; i <= 26; i++) {
		if(a[a[u].ne[i]].picked != 1) pickup(a[u].ne[i]);
	}
}
//-------¡¤?¡Á¨¦-----------
inline int query(int x) //??x¦Ì??¨´¨®D¡Á¨®????DD?£¤?? ??¨®D?¨°¡¤¦Ì??0
{
	int ret = 0;
	for(int i = 0; i < 15; i++) {
		if(fenz[i].root != 0) {
			ret = max(ret, check(fenz[i].root, w[x].st, w[x].en));
		}
	}
	return ret;
}
inline void insert_(int x) //2?¨¨?¡Á?¡¤???x
{
	int p = 0;
	while(fenz[p].root != 0) p++;
	if(p != 0) {
		fenz[p].st = fenz[p - 1].st;
		fenz[p].en = x;
	} else fenz[p].st = fenz[p].en = x;
	for(int i = 0; i < p; i++) {
		pickup(fenz[i].root);
		fenz[i].st = fenz[i].en = fenz[i].root = 0;
	}
	/*if(free_top<=w[x].en-w[x].st+3){
		for(int i=w[x].st-1;i<=w[x].en;i++)//¨¦¨º??????
	    	push(++cnt);
	}*/
	fenz[p].root = pop();
	for(int i = fenz[p].st; i <= fenz[p].en; i++) {
		insert(fenz[p].root, w[i].st - 1, w[i].en, w[i].dp);
	}
	pre_fail(fenz[p].root);
}
//--------clear----------
inline void clear()
{
	ans = 0; //cnt=0;
	for(int i = 0; i <= 15; i++) {
		if(fenz[i].root != 0) pickup(fenz[i].root);
		fenz[i].st = fenz[i].en = fenz[i].root = 0;
	}
	//free_top=0;
}
//--------init-----------
inline void init()
{
	scanf("%d", &n);
	int p = 0;
	for(int i = 1; i <= n; i++) {
		int t = read(p, word);
		w[i].st = p + 1;
		w[i].en = t;
		scanf("%d", &w[i].dp);
		if(w[i].dp < 0) {
			i--;
			n--;
			continue;
		}
		p = t;
	}
}
//-----------------------
int main()
{
	int T;
	scanf("%d", &T);
	for(int tt = 1; tt <= T; tt++) {
		init();
		for(int i = 1; i <= n; i++) {
			w[i].dp = max(w[i].dp, query(i) + w[i].dp);
			ans = max(w[i].dp, ans);
			insert_(i);
		}
		printf("Case #%d: %d\n", tt, ans);
		clear();
	}
	return 0;
}
