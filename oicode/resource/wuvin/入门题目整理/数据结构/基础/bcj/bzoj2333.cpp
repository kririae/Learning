/*#include<cstdio>
#include<iostream>
#define N 300005
using namespace std;
//貌似可以bcj？启发合并不压缩路径最方便
//0-全局
//由于有减法貌似并不能维护
struct node{
	int add,maxn,val,bcj,size;
}a[N];
int ff(int x){
	while(a[x].bcj!=x){x=a[x].bcj;}
	return x;
}
int getval(int x){
	int ret=a[x].val;
	while(a[x].bcj!=x){
		ret+=a[x].add;
		x=a[x].bcj;
	}
	ret+=a[x].add;ret+=a[0].add;
	return ret;
}
int n,m;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].val);a[i].maxn=a[i].val;a[i].size=1;
		a[0].maxn=max(a[0].maxn,a[i].maxn);a[i].bcj=i;
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		char s[4];int x,v;
		scanf("%s",s);
		if(s[0]=='A'){
			if(s[1]=='1'){
				scanf("%d%d",&x,&v);
				a[x].val+=v;
				int t=ff(x),t2=getval(x);
				a[t].maxn=max(a[t].maxn,t2);
				a[0].maxn=max(a[0].maxn,t2);
			}else if(s[1]=='2'){
				scanf("%d%d",&x,&v);
				x=ff(x);a[x].add+=v;
				a[x].maxn+=v;
				a[0].maxn=max(a[0].maxn,a[x].maxn);
			}else{
				scanf("%d",&v);
				a[0].add+=v;a[0].maxn+=v;
			}
		}else if(s[0]=='F'){
			if(s[1]=='1'){
				scanf("%d",&x);
				printf("%d\n",getval(x));
			}else if(s[1]=='2'){
				scanf("%d",&x);
				x=ff(x);printf("%d\n",a[x].maxn+a[0].add);
			}else{
				printf("%d\n",a[0].maxn);
			}
		}else{
			scanf("%d%d",&x,&v);
			x=ff(x);v=ff(v);
			if(a[x].size>a[v].size) swap(x,v);
			a[x].bcj=v;a[x].add-=a[v].add;
			a[v].maxn=max(a[v].maxn,a[x].maxn);
			a[v].size+=a[x].size;
		}
	}
	return 0;
} 不过虽然错了，但我还是神奇的过了样例*/
//所以采用DFS序投影到序列上
//然后线段树维护
//如果非要在线，也许可以用splay维护DFS序序列
//不过splay维护，全局最值会被坑死
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#define N 300005
using namespace std;
struct node {
	vector<int> x;
	int fa, val, size;
	int st, en; //DFS
} a[N];
struct oper {
	int kind, x, v;
} b[N];
int n, m, root, cnt;
//---------------------
int bcj[N];
int ff(int x)
{
	return bcj[x] == x ? x : bcj[x] = ff(bcj[x]);
}
inline void merge(int x, int y)
{
	if(a[x].size > a[y].size) swap(x, y);
	x = ff(x);
	y = ff(y);
	if(x == y) return;
	bcj[x] = y;
	a[x].fa = y;
	a[y].x.push_back(x);
}
//---------------------
int v[N], vcnt;
void DFS(int u)
{
	a[u].st = vcnt;
	v[vcnt] = u;
	vcnt++;
	for(int i = 0, len = a[u].x.size(); i < len; i++) {
		DFS(a[u].x[i]);
	}
	a[u].en = vcnt;
}
//----------------------
struct sett {
	int fr, to;
} c[N];
inline void merges(int x, int y)
{
	if(a[x].size > a[y].size) swap(x, y);
	x = ff(x);
	y = ff(y);
	if(x == y) return;
	bcj[x] = y;
	c[y].to = c[x].to;
}
//----------xds------------
struct xds {
	int fr, to, son[2], max, add;
} d[N * 2];
const int L = 0, R = 1;
inline void update(int k)
{
	if(k == 0) return;
	d[k].max = max(d[d[k].son[L]].max, d[d[k].son[R]].max) + d[k].add;
}
void build(int &k, int fr, int to)
{
	k = ++cnt;
	d[k].fr = fr;
	d[k].to = to;
	if(fr == to) {
		d[k].add = d[k].max = a[v[fr]].val;
		return;
	}
	int mid = (fr + to) >> 1;
	build(d[k].son[L], fr, mid);
	build(d[k].son[R], mid + 1, to);
	update(k);
}
void add(int k, int fr, int to, int v)
{
	if(d[k].fr == fr && d[k].to == to) {
		d[k].max += v;
		d[k].add += v;
		return;
	} else {
		int mid = (d[k].fr + d[k].to) >> 1;
		if(to <= mid) add(d[k].son[L], fr, to, v);
		else if(fr > mid) add(d[k].son[R], fr, to, v);
		else add(d[k].son[L], fr, mid, v), add(d[k].son[R], mid + 1, to, v);
		update(k);
		return;
	}
}
int getmax(int k, int fr, int to)
{
	if(d[k].fr == fr && d[k].to == to) {
		return d[k].max;
	} else {
		int mid = (d[k].fr + d[k].to) >> 1;
		int ret = d[k].add;
		if(to <= mid) ret += getmax(d[k].son[L], fr, to);
		else if(fr > mid) ret += getmax(d[k].son[R], fr, to);
		else ret += max(getmax(d[k].son[L], fr, mid), getmax(d[k].son[R], mid + 1, to));
		return ret;
	}
}
//------------------------
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i].val);
		a[i].size = 1;
	}
	for(int i = 1; i <= n; i++) bcj[i] = i;
	scanf("%d", &m);
	for(int i = 1; i <= m; i++) {
		char s[4];
		int x, v;
		scanf("%s", s);
		if(s[0] == 'A') {
			if(s[1] == '1') {
				scanf("%d%d", &b[i].x, &b[i].v);
				b[i].kind = 1;
			} else if(s[1] == '2') {
				scanf("%d%d", &b[i].x, &b[i].v);
				b[i].kind = 2;
			} else {
				scanf("%d", &b[i].v);
				b[i].kind = 3;
			}
		} else if(s[0] == 'F') {
			if(s[1] == '1') {
				scanf("%d", &b[i].x);
				b[i].kind = 4;
			} else if(s[1] == '2') {
				scanf("%d", &b[i].x);
				b[i].kind = 5;
			} else {
				b[i].kind = 6;
			}
		} else {
			scanf("%d%d", &b[i].x, &b[i].v);
			b[i].kind = 7;
			merge(b[i].x, b[i].v);
		}
	}
	for(int i = 1; i <= n; i++) {
		if(bcj[i] == i) a[0].x.push_back(i);
	}
	DFS(0);
	for(int i = 1; i <= n; i++) bcj[i] = i;
	for(int i = 1; i <= n; i++) c[i].fr = c[i].to = a[i].st;
	build(root, 1, n);
	for(int i = 1; i <= m; i++) {
		int x = b[i].x;
		if(b[i].kind == 1) {
			add(root, c[x].fr, c[x].fr, b[i].v);
		} else if(b[i].kind == 2) {
			x = ff(x);
			add(root, c[x].fr, c[x].to, b[i].v);
		} else if(b[i].kind == 3) {
			add(root, 1, n, b[i].v);
		} else if(b[i].kind == 4) {
			printf("%d\n", getmax(root, c[x].fr, c[x].fr));
		} else if(b[i].kind == 5) {
			x = ff(x);
			printf("%d\n", getmax(root, c[x].fr, c[x].to));
		} else if(b[i].kind == 6) {
			printf("%d\n", getmax(root, 1, n));
		} else if(b[i].kind == 7) {
			merges(b[i].x, b[i].v);
		}
	}
	return 0;
}
