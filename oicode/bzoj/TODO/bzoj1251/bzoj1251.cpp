// by hzwer
#include<iostream>
#include<cstdio>
#define inf 0x7fffffff
using namespace std;
// 读入操作
inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();

	while(ch < '0' || ch > '9') {
		if(ch == '-')f = -1;

		ch = getchar();
	}

	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}

	return x * f;
}
// n, m 大小 旋转(开始的输入是吧...
int n, m, sz, rt;
// father节点 子孙的位置 id?
int fa[50005], c[50005][2], id[50005];
// lazytag 值 最大值 大小
int tag[50005], v[50005], mx[50005], size[50005];
// 是否翻转（左右翻转
bool rev[50005];
// 上传标记
inline void pushup(int k)
{
	// 获取左右子树的index
	int l = c[k][0], r = c[k][1];
	// 更新当前的最大值吧
	mx[k] = max(mx[l], mx[r]);
	mx[k] = max(mx[k], v[k]);
	// 当前的大小等于左儿子的大小 + 右儿子的大小
	size[k] = size[l] + size[r] + 1;
}
// 下传标记
void pushdown(int k)
{
	// 还是获取左右子树的index 然后找到当前的tag
	int l = c[k][0], r = c[k][1], t = tag[k];

	// 如果当前的tag不等于0(有tag) 那就下传标记
	if(t) {
		// 惯例的下传标记
		tag[k] = 0;

		if(l) {
			tag[l] += t;
			mx[l] += t;
			v[l] += t;
		}

		if(r) {
			tag[r] += t;
			mx[r] += t;
			v[r] += t;
		}
	}

	// 翻转标记 如果翻转了 那就下传翻转标记???(应该是翻转左右子树)
	if(rev[k]) {
		rev[k] = 0;
		rev[l] ^= 1;
		rev[r] ^= 1;
		// 对就是翻转左右子树
		swap(c[k][0], c[k][1]);
	}
}
void rotate(int x, int &k)
{
	// 获取当前点的前面两个点的inx
	int y = fa[x], z = fa[y], l, r;

	// 如果当前点是一个左儿子 那就l = 1, r = 0;
	if(c[y][0] == x)l = 0;
	else l = 1;

	r = l ^ 1;

	// k啥玩意儿啊qwq
	if(y == k)k = x;
	else {
		// 如果父节点是爷爷节点的左节点 那就把当前节点放在爷爷节点的左节点
		if(c[z][0] == y)
			c[z][0] = x;
		else
			// 如果是右节点 那就把当前节点放在爷爷节点的右边
			c[z][1] = x;
	}

	// 重新更新 x的父亲重置为z y的父亲重置为x... 然后把x的做节点置y
	fa[x] = z;
	fa[y] = x;
	fa[c[x][r]] = y;
	// 反正就是乱呼呼的变换啦
	// 右旋变换的顺序:
	// x的左子树放在y的右子树 x认y作父亲 y作x的左子树
	// 左旋的变换的顺序:
	// y认x作父亲 x的左子树放在y的右子树
	c[y][l] = c[x][r];
	c[x][r] = y;
	// 上传（不如说是总结）标记
	pushup(y);
	pushup(x);
}
// splay辣! 将节点x旋转到k的位置
void splay(int x, int &k)
{
	// 当x不等于k的时候
	while(x != k) {
		// 还是那样 获取当前节点的祖宗两代
		int y = fa[x], z = fa[y];

		// 如果父亲节点不等于k 那就继续旋转
		if(y != k) {
			// 如果x是父亲节点的左节点且y是z的左节点 那就继续旋转一下x
			if(c[y][0] == x ^ c[z][0] == y)
				rotate(x, k);
			// 如果是弯的 那就先旋转y
			else rotate(y, k);
		}

		// 反正最后还要再旋转一次
		rotate(x, k);
	}
}
// 如果没错的话...这段的意思应该是获取rank的数字, k应该是根节点 返回节点index
int find(int k, int rank)
{
	// 如果tag和rev有值 那就下传
	if(tag[k] || rev[k])pushdown(k);

	// 依旧获取当前节点的左节点和右节点
	int l = c[k][0], r = c[k][1];

	// 如果左边的大小等于rank 那就直接返回当前的节点
	if(size[l] + 1 == rank)return k;
	// 如果左节点的大小大于rank 那就向左节点寻找
	else if(size[l] >= rank)return find(l, rank);
	// 如果左节点的大小小于rank 那就向右节点寻找...
	// 至于rank - size[l] - 1; 大概意思应该是
	// 把右节点当成一棵子树 因为右边的值是大于左边的 那就rank - ....(毕竟是寻找rank为rank的)
	// 因为是寻找rank为rank的 右边左边大小关系相反 所以有了这句话（没有完全理解到
	else return find(r, rank - size[l] - 1);
}
// 更新区间 区间加
inline void update(int l, int r, int val)
{
	int x = find(rt, l), y = find(rt, r + 2);
	splay(x, rt);
	splay(y, c[x][1]);
	int z = c[y][0];
	tag[z] += val;
	v[z] += val;
	mx[z] += val;
}
inline void rever(int l, int r)
{
	int x = find(rt, l), y = find(rt, r + 2);
	splay(x, rt);
	splay(y, c[x][1]);
	int z = c[y][0];
	rev[z] ^= 1;
}
inline void query(int l, int r)
{
	int x = find(rt, l), y = find(rt, r + 2);
	splay(x, rt);
	splay(y, c[x][1]);
	int z = c[y][0];
	printf("%d\n", mx[z]);
}
inline void build(int l, int r, int f)
{
	if(l > r)return;

	int now = id[l], last = id[f];

	if(l == r) {
		fa[now] = last;
		size[now] = 1;

		if(l < f)c[last][0] = now;
		else c[last][1] = now;

		return;
	}

	int mid = (l + r) >> 1;
	now = id[mid];
	build(l, mid - 1, mid);
	build(mid + 1, r, mid);
	fa[now] = last;
	pushup(now);

	if(mid < f)c[last][0] = now;
	else c[last][1] = now;
}
int main()
{
	mx[0] = -inf;
	n = read();
	m = read();

	for(int i = 1; i <= n + 2; i++)
		id[i] = ++sz;

	build(1, n + 2, 0);
	rt = (n + 3) >> 1;

	for(int i = 1; i <= m; i++) {
		int f = read(), l, r, val;

		switch(f) {
		case 1:
			l = read();
			r = read();
			val = read();
			update(l, r, val);
			break;

		case 2:
			l = read();
			r = read();
			rever(l, r);
			break;

		case 3:
			l = read();
			r = read();
			query(l, r);
			break;
		}
	}

	return 0;
}