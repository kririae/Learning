#include<cstdio>
#include<algorithm>
#include<vector>
#define Z ->son[L]->times
using namespace std;
/*Z
struct TT{
...//装内容
}
namespace T2{
	//函数
}
*/
//BZOJ 2588
//这个线段树有点复杂
//每个节点到根建seg，利用主席树的方式压缩空间和时间
//支持1~n区间的线段树直接减1~n-k的线段树来求n-k+1~n的线段树
//真是神奇的方法
const int L = 0;
const int R = 1;
struct tree {
	int from, to, mid; //建在值上的线段树 打点计数器
	int times;//所有元素出现次数总和
	tree* son[2];
	tree(int from_, int to_)
	{
		from = from_;
		to = to_;
		times = 0;
		son[0] = son[1] = NULL;
		if(from_ == to_) {
			mid = from;
			return;
		} else {
			mid = (from + to) / 2;
			son[L] = new tree(from, mid);
			son[R] = new tree(mid + 1, to);
			return;
		}
	}
	tree(tree* fa)
	{
		from = fa->from;
		to = fa->to;
		son[0] = fa->son[0];
		son[1] = fa->son[1];
		times = fa->times;
		mid = fa->mid;
	}
	tree* add(int key)
	{
		tree* ret = new tree(this);
		ret->times++;
		if(from == to) {
			return ret;
		} else {
			if(key > mid) {
				ret->son[R] = ret->son[R]->add(key);
			} else {
				ret->son[L] = ret->son[L]->add(key);
			}
		}
		return ret;
	}
};

struct node { //真的普通树
	tree* t;
	int x;//离散化后的大小
	int deep;
	int ancestor[20];//2^k级祖先
	vector<int> sons;
} mytree[100005];

int a[100005];
int b[100005];//离散化后 第i大的值是a[b[i]]
int n, m;
//基础空树为mytree[0]
bool cmp(int a1, int b1)
{
	return a[a1] < a[b1];
}
void lisanhua()
{
	for(int i = 1; i <= n; i++) {
		b[i] = i;
	}
	sort(b + 1, b + n + 1, cmp);
}
void build_nulltree()
{
	mytree[0].t = new tree(1, n);
}
void DFS(int u, int father, int deep)
{
	mytree[u].ancestor[0] = father;
	mytree[u].deep = deep;
	int p = 1;
	while((1 << p) <= deep) {
		mytree[u].ancestor[p] = mytree[mytree[u].ancestor[p - 1]].ancestor[p - 1];
		p++;
	}
	mytree[u].t = mytree[mytree[u].ancestor[0]].t->add(mytree[u].x);
	for(int i = 0, len = mytree[u].sons.size(); i < len; i++) {
		if(mytree[u].sons[i] != mytree[u].ancestor[0]) {
			DFS(mytree[u].sons[i], u, deep + 1);
		}
	}
	return;
}
void build_real_tree()
{
	for(int i = 1; i <= n; i++) {
		mytree[b[i]].x = i;
	}
	for(int f, t, i = 1; i < n; i++) {
		scanf("%d%d", &f, &t);
		mytree[f].sons.push_back(t);
		mytree[t].sons.push_back(f);
	}
	DFS(1, 0, 0);
}
int lca(int u, int v)
{
	if(mytree[u].deep < mytree[v].deep) swap(u, v);
	int p = mytree[u].deep - mytree[v].deep;
	int k = 0;
	while(p != 0) {
		if(p & 1)
			u = mytree[u].ancestor[k];
		k++;
		p >>= 1;
	}
	if(u == v) return u;
	for(int i = 18; i >= 0; i--) {
		if(mytree[u].ancestor[i] != mytree[v].ancestor[i]) {
			u = mytree[u].ancestor[i];
			v = mytree[v].ancestor[i];
		}
	}
	return mytree[u].ancestor[0];
}
int xdsquery(tree* anc, tree* anc2, tree* u, tree* v, int k) //查询u+v-anc-anc2
{
	if(u->from == u->to) return u->from;
	int zuo = u Z + v Z - anc Z - anc2 Z;
	if(k <= zuo) {
		return xdsquery(anc->son[L], anc2->son[L], u->son[L], v->son[L], k);
	} else {
		return xdsquery(anc->son[R], anc2->son[R], u->son[R], v->son[R], k - zuo);
	}
}
int query(int u, int v, int k)
{
	int mid = lca(u, v);
	tree* anc = mytree[mid].t;
	tree* ut = mytree[u].t;
	tree* vt = mytree[v].t;
	int ret = xdsquery(anc, mytree[mytree[mid].ancestor[0]].t, ut, vt, k);
	return a[b[ret]];
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	lisanhua();
	build_nulltree();
	build_real_tree();
	int lastans = 0;
	for(int u, v, t, i = 1; i <= m; i++) {
		scanf("%d%d%d", &u, &v, &t);
		u ^= lastans; //在线
		lastans = query(u, v, t);
		printf("%d", lastans);
		if(i != m) printf("\n");
	}
	return 0;
}
