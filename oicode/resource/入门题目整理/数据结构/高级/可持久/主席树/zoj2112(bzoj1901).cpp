/*正解树状数组套主席树
偏方主席树状数组配Treap
时间复杂度nlognlogt
空间(n+m)logn
*//*
其实应该这么想：对于bittree而言，他应当认为每一个节点都是这样一个数组
值              0 0 0 0 1 1 1 1 2 2
下标（即vis）    0 1 2 3 4 5 6 7 8 9
每次的加减都是对于k以及k之后的所有数的区间加减。
so,这就是交给Treap的了*/
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define N 10005
#define M 300005
#define low(x) (x&(-x))
using namespace std;
int n, m, cnt;
const int L = 0, R = 1;
//---Treap---
int son[M][2], pri[M]; //size[M],
int data[M], vision[M], tag[M]; //要维护的 vision 大小排序
inline void addmark(const int &k, const int &c) {
	if(k == 0)return;

	tag[k] += c;
}
inline void pushdown(const int &k) {
	if(k == 0 || tag[k] == 0) return;

	data[k] += tag[k];
	addmark(son[k][L], tag[k]);
	addmark(son[k][R], tag[k]);
	tag[k] = 0;
}
inline void rotate(int &k, int s) {
	int t = son[k][s];
	son[k][s] = son[t][s ^ 1];
	son[t][s ^ 1] = k;
	k = t;
}
void add(int &k, const int &c, const int &vis, int &minv) { //minv-请出示化为0
	if(k == 0) {
		k = ++cnt;
		son[k][L] = son[k][R] = 0;
		pri[k] = rand();
		data[k] = c + minv;
		vision[k] = vis;
		tag[k] = 0;
	} else {
		pushdown(k);

		if(vis <= vision[k]) data[k] += c, addmark(son[k][R], c);

		if(vis != vision[k]) {
			int s = vis < vision[k] ? L : R;

			if(s == R) minv = data[k];

			add(son[k][s], c, vis, minv);

			if(pri[son[k][s]] > pri[k]) rotate(k, s);
		}
	}
}
void get(int k, int vis, int &ret) { //返回小于等于vis的第一个node的data
	if(k == 0) return;

	pushdown(k);

	if(vis >= vision[k]) ret = data[k];

	if(vis != vision[k]) {
		int s = vis < vision[k] ? L : R;
		get(son[k][s], vis, ret);
	}

	ret += tag[k];
}
//---bit----
int rootbit[N + N];
inline void bitadd(int x, int vis, int f) { //f==1
	for(int i = x, z = 0; i < N + N; i += low(i)) {
		z = 0;
		add(rootbit[i], f, vis, z);
	}
}
inline int kth(int start, int end, int k) { //区间[start,end]的k大
	int at = 0;
	start--;

	for(int i = 14; i >= 0; i--) {
		at += 1 << i;

		if(at > N + N) {
			at -= 1 << i;
			continue;
		}

		int t1 = 0, t2 = 0;
		get(rootbit[at], start, t1);
		get(rootbit[at], end, t2);

		if(t2 - t1 >= k) at -= 1 << i;
		else k -= t2 - t1;
	}

	return at + 1;
}
//--main----
struct lsh {
	int *a;
	int name;
	bool operator <(const lsh &b)const {
		return (*a) < *(b.a);
	}
} p[N + N];
int array[N], pcnt;
int opera[N], a1[N], a2[N], a3[N];
int name2val[N + N];
void init() {
	scanf("%d%d", &n, &m);
	char c[3];

	for(int i = 1; i <= n; i++) {
		scanf("%d", &array[i]);
		p[++pcnt].a = &array[i];
	}

	for(int i = 1; i <= m; i++) {
		scanf("%s", c);

		if(c[0] == 'Q') {
			scanf("%d%d%d", &a1[i], &a2[i], &a3[i]);
			opera[i] = 1;
		} else {
			scanf("%d%d", &a1[i], &a2[i]);
			opera[i] = 2;
			p[++pcnt].a = &a2[i];
		}
	}
}
void pre() {
	sort(p + 1, p + pcnt + 1);
	p[1].name = 1;

	for(int i = 2, cnt2 = 2; i <= pcnt; i++) {
		if(*(p[i].a) == *(p[i - 1].a)) p[i].name = p[i - 1].name;
		else p[i].name = cnt2++;
	}

	for(int i = 1; i <= pcnt; i++) {
		name2val[p[i].name] = *(p[i].a);
		*(p[i].a) = p[i].name;
	}
}
void solve() {
	for(int i = 1; i <= n; i++) {
		bitadd(array[i], i, 1);
	}

	for(int i = 1; i <= m; i++) {
		if(opera[i] == 1) {
			printf("%d\n", name2val[kth(a1[i], a2[i], a3[i])]);
		} else {
			bitadd(array[a1[i]], a1[i], -1);
			array[a1[i]] = a2[i];
			bitadd(a2[i], a1[i], 1);
		}
	}
}
int main() {
	init();
	pre();
	solve();
	return 0;
}
