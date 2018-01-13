#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int L = 0, R = 1;

int n, m;
// 维护是最麻烦的...
// 这种写法会简单很多
struct Message { // 节点维护的信息
	long long sum, add, len; // 区间和 区间长度 区间lazy的加法
	/*
	// 写清楚那一个变量优先
	ans = ans * mul + add;
	*/
	Message()   // 初始化函数
	{
		sum = 0, add = 0, len = 0;
	}
	Message(long long xsum, long long xadd, longl long xlen)
	{
		sum = xsum, add = xadd, len = xlen;
	}
	Message operator + (const Message (&b))   // 合并两部分的信息
	{
		Message p(sum + b.sum, 0, len + b.len); // p.sum = sum + b.sum p.add = 0 p.len = len + b.len
		return p;
	}
	void modify(Message fa)   // 父亲的信息为fa, 父亲pushdown下传
	{
		sum += len * fa.add;
		add += fa.add;
	}
};
/*
struct SegmentTree {
	int l, r; // 管理当前区间 [l, r]
	long long sum; // 当前区间和
	long long add;
	// 记录左右儿子
	// SegmentTree *son[2];
	// SegmentTree* lson, *rson;
	int son[2]; // 一个下标为0 一个下标为1
	// int lson, rson;
} node[N*2];
*/

Message p = (Message)
{
	5, 6
};

struct SegmentTree {
	int l, r; // 管理当前区间 [l, r]
	int son[2]; // 一个下标为0 一个下标为1
	Message x;
} node[N * 2];
int root, ini[N], cnt; // cnt记录下标分配
// 假设数组初始化为ini

inline void pushdown(int k)   // TODO 下传标记
{
	// 把节点k上的数值下传
	if(node[k].x.add != 0) {
		node[ node[k].son[L] ].x.modify( node[k].x );
		node[ node[k].son[R] ].x.modify( node[k].x );
		node[k].x.add = 0;
	}
}

inline void update(int k)   // 更新节点k
{
	node[k].x = node[ node[k].son[L] ].x + node[ node[l].son[R] ].x;
}
inline void buildTree(int &k, int l, int r)   // 初始化一个管理l, r的节点 下表为k
{
	// 这个k的引用很妙 在修改下一个的时候会顺便修改上一个节点的儿子们
	k = ++cnt; // k = cnt + 1; cnt++
	node[k].l = l, node[k].r = r; // 别写掉了 初始化l, r
	node[k].x.len = (r - l + 1);

	if(l == r) { // 没有儿子了233333
		node[k].x.sum = ini[l];
	} else { // 我是爸爸
		int mid = (l + r) / 2; // 当前区间中点
		buildTree(node[k].son[L], l, mid); // 递归建造左子树
		buildTree(node[k].son[R], mid + 1, r); // 递归建造右子树
		node[k].sum = node[ node[k].son[L] ].sum + node[ node[k].son[R] ].sum; // 在修改下一层的k的时候就顺便修改了这一层的l, r了 妙啊妙啊
		// k是当前参数的k 而不会传到下一层去...(我sabi了
		// 计算当前节点的和
	}
}
/*
inline void buildTree(int &k, int l, int r) { // 初始化一个管理l, r的节点 下表为k
	// 这个k的引用很妙 在修改下一个的时候会顺便修改上一个节点的儿子们
	k = ++cnt; // k = cnt + 1; cnt++
	node[k].l = l, node[k].r = r; // 别写掉了 初始化l, r
	if(l == r) { // 没有儿子了233333
		node[k].sum = ini[l];
	}
	else { // 我是爸爸
		int mid = (l + r) / 2; // 当前区间中点
		buildTree(node[k].son[L], l, mid); // 递归建造左子树
		buildTree(node[k].son[R], mid + 1, r); // 递归建造右子树
		node[k].sum = node[ node[k].son[L] ].sum + node[ node[k].son[R] ].sum; // 在修改下一层的k的时候就顺便修改了这一层的l, r了 妙啊妙啊
		// k是当前参数的k 而不会传到下一层去...(我sabi了
		// 计算当前节点的和
	}
}
*/
/*
inline void modify(int k, int ql, int qr, int val) {
	pushdown(k);
	if(node[k].l == ql && node[k].r == qr) {
		node[k].add += val;
	}
	else {
		int mid = (node[k].l + node[k].r) / 2；
		if(qr <= mid) modify(node[k].son[L], ql, qr, val);
		else if(mid < ql) modify(node[k].son[R], ql, qr, val);
		else modify(node[k].son[L], ql, mid, val), modify(node[k].son[R], mid + 1, qr, val);
	}
}

inline long long query(int k, int posi, int val) {
	pushdown(k);
	if(node[k].l == node[k].r) {
		return node[k].add + ini[node[k].l];
	}
	else {
		int mid = (node[k].l + node[k].r) / 2;
		if(pos <= mid) return query(node[k].son[L], pos, val);
		else return query(node[k].son[R], pos, val);
	}
}
*/
/*
inline void modify(int k, int pos, int val) { // 修改 把ini[pos] 修改为val
	if(node[k].l == node[k].r) {
		node[k].sum = val;
		ini[pos] = val;
	}
	else {
		int mid = (node[k].l + node[k].r) / 2; // 儿子的左右分界
		if(pos <= mid) modify(node[k].son[L], pos, val); // 看是修改左儿子还是右儿子
		else modify(node[k].son[R], pos, val);

		node[k].sum = node[ node[k].son[L] ].sum + node[ node[k].son[R] ].sum; // 再次修改
	}
}
*/
/*
inline long long query(int k, int ql, int qr) { // 查询[ql, qr] 的区间和
	if(node[k].l == ql && node[k].r == qr) {
		return node[k].sum;
	}
	else {
		int mid = (node[k].l + node[k].r) / 2;
		if(qr <= mid) return query(node[k].son[L], ql, qr);
		else if(ql > mid) return query(node[k].son[R], ql, qr);
		else return query(node[k].son[L], ql, mid) + query(node[k].son[R], mid + 1, qr);
	}
}
*/

inline Message modify(int k, int ql, int qr, Message y)   // 修改 [ql, qr] 顺带查询ql, qr
{
	if(node[k].l == ql && node[k].r == qr) {
		node[k].x.modify(y); // 修改操作的简单写法..(累死了
		return node[k].x;
	} else {
		Message p;
		pushdown(k);
		int mid = (node[k].l + node[k].r) / 2;

		if(qr <= mid) p = modify(node[k].son[L], ql, qr, y);
		else if(mid < ql) p = modify(node[k].son[R], ql, qr, y);
		else p =  modify(node[k].son[L], ql, mid, y) + modify(node[k].son[R], mid + q, qr, y);

		update(k);
		return p;
	}
}

/*
6
4
5
6
2
1
3
4
1 3 5
2 1 4
1 1 9
2 2 6
*/

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> ini[i];
	}

	buildTree(root, 1, n);
	Message y, ans;
	int l, r, val;
	y.add = val;
	modify(root, l, r, y);
	// 查询区间[l, r]
	y.add = y.len = y.sum = 0;
	ans = modify(root, l, r, y);
	cout << ans.sum << endl;
	/*
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		if(a == 1) {
			modify(root, b, c);
		}
		if(a == 2) {
			cout << query(root, b, c) << endl;
		}
	}*/
	return 0;
}