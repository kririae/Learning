// copy from bzoj
#include<cstdio>
#include<algorithm>
#include<cmath>
/*BZOJ2716 离线操作 对拍成功*/
using namespace std;
const int maxn = 5e5 + 100;
const int inf = 0x3f3f3f3f;
int opt[maxn * 2][3];
int id[maxn * 2];
int n, m;
namespace KD_tree
{
struct node {
	int ch[2], mn[2], mx[2], x, y, fa, id;
	bool d, exist;
	node()
	{
		mn[0] = mn[1] = inf;
		exist = 0;
	}
	node(int rx, int ry)
	{
		x = rx, y = ry;
		exist = 0;
	}
	void init()
	{
		mx[0] = mn[0] = x;
		mx[1] = mn[1] = y;
	}
} tree[maxn * 4];
int cnt, D, root;

bool operator <(const node &a, const node &b)
{
	return !D ? a.y < b.y : a.x < b.x;
}

void push_up(int rt)
{
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++) {
			tree[rt].mn[j] = min(tree[rt].mn[j], tree[tree[rt].ch[i]].mn[j]);
			tree[rt].mx[j] = max(tree[rt].mx[j], tree[tree[rt].ch[i]].mx[j]);
		}
}

void build(int &rt, int l, int r, int d, int fa)
{
	if(l == r) {
		rt = r;
		tree[rt].d = d;
		tree[rt].fa = fa;
		tree[rt].d = d;
		return;
	}

	int mid = (l + r) / 2;
	rt = mid;
	D = d;      /*这里的细节问题一定要注意啊，要不然直接WA+TLE双喜临门*/
	nth_element(tree + l, tree + mid, tree + r + 1);
	tree[rt].d = d;
	tree[rt].fa = fa;

	if(l < mid) build(tree[rt].ch[0], l, mid - 1, d ^ 1, rt);

	if(r > mid) build(tree[rt].ch[1], mid + 1, r, d ^ 1, rt);

	push_up(rt);
}

int dis(int x, int y, node rect)
{
	int tmp = 0;
	tmp += max(0, rect.mn[0] - x), tmp += max(0, x - rect.mx[0]);
	tmp += max(0, rect.mn[1] - y), tmp += max(0, y - rect.mx[1]);
	return tmp;
}

int mh(int x, int y, int _x, int _y)
{
	return abs(x - _x) + abs(y - _y);
}

void query(int x, int y, int rt, int &ans)
{
	int d, dl = inf, dr = inf;

	if(tree[rt].exist) {
		d = mh(x, y, tree[rt].x, tree[rt].y);
		ans = min(d, ans);
	}

	if(tree[rt].ch[0]) dl = dis(x, y, tree[tree[rt].ch[0]]);

	if(tree[rt].ch[1]) dr = dis(x, y, tree[tree[rt].ch[1]]);

	if(dl < dr) {
		if(dl < ans) query(x, y, tree[rt].ch[0], ans);

		if(dr < ans) query(x, y, tree[rt].ch[1], ans);
	} else {
		if(dr < ans) query(x, y, tree[rt].ch[1], ans);

		if(dl < ans) query(x, y, tree[rt].ch[0], ans);
	}
}

void insert(int now)
{
	/* 注意,当前节点一旦插入，需要初始化，并且用该节点信息重新更新整条链 */
	now = id[now];
	tree[now].init();
	tree[now].exist = 1;

	while(tree[now].fa) {
		push_up(now);
		now = tree[now].fa;
	}
}
}

int main()
{
	using namespace KD_tree;
	scanf("%d%d", &n, &m);

	for(int i = 1; i <= n; i++) {
		scanf("%d%d", &tree[i].x, &tree[i].y);
		tree[i].exist = 1;
		tree[i].init();
	}

	cnt = n;

	for(int i = 1; i <= m; i++) {
		scanf("%d%d%d", &opt[i][0], &opt[i][1], &opt[i][2]);

		if(opt[i][0] == 1)  /*未插入的节点仍然需要传递下层信息，只是不传递本身信息*/
			tree[++cnt].x = opt[i][1], tree[cnt].y = opt[i][2], tree[cnt].id = i;
	}

	build(root, 1, cnt, 1, 0);

	for(int i = 1; i <= cnt; i++)
		if(tree[i].id) id[tree[i].id] = i;

	for(int i = 1; i <= m; i++) {
		int x = opt[i][1], y = opt[i][2], ans = inf;

		if(opt[i][0] == 2) {
			query(x, y, root, ans);
			printf("%d\n", ans);
		}

		if(opt[i][0] == 1)
			insert(i);
	}

	return 0;
}
