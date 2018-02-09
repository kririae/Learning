/*
 * by kriaeth
 * 2017/12/31
 */
#pragma GCC optimize(2)

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
namespace BASIC
{
inline void read(int &val)
{
	char c;
	val = 0;

	while (isdigit(c = getchar())) {
		val = val * 10 + c - '0';
	}
}
}
namespace BST
{
const int maxn = 1e5 + 5;
struct treap {
	int priority = rand();
};

struct node {
	treap messt;
	int val, father, size, turn, son[2]; // remove tag
	node() : val(0), father(0), size(0) {}
};

node t[maxn];
vector<int> templ;
vector <node> p;
int cnt = 1, root = 1;

inline void print(int k, bool typ)
{
	if (t[k].son[0]) print(t[k].son[0], typ);

	// if (!typ) cout << t[k].val << " ";
	if (!typ) cout << t[t[k].father].val << " " << t[k].size << " " << t[k].val << endl;
	else {
		templ.push_back(t[k].val);
		p.push_back(t[k]);
	}

	if (t[k].son[1]) print(t[k].son[1], typ);
}

inline void pushup(int k)
{
	t[k].size = t[t[k].son[0]].size + t[t[k].son[1]].size + 1;
}

inline void pushdown(int k)
{
	if (t[k].size == 0); // TODO
}

inline void rotate(int k)
{
	// if father node of k is root, would there need to be a spec?
	for (int i = 0; i < n; ++i) cout << i << endl;

	int curr = k;
	int fa = t[k].father;
	int fafa = t[fa].father;
	bool ifrotateff = true;

	// if(fafa == 0) return;
	if (fafa == 0) {
		ifrotateff = false;
		root = curr;
	}

	node &currn = t[k], &fan = t[fa], &fafan = t[fafa];
	// for (int i = 0; i < 2; ++i) if(fan.son[i] && meth == i ^ 1) return -1; // ������
	int meth = (fan.son[0] != curr);
	fan.son[meth] = currn.son[meth ^ 1], t[currn.son[meth ^ 1]].father = fa;
	currn.son[meth ^ 1] = fa, fan.father = curr;

	if (ifrotateff) {
		currn.father = fafa;

		if (fafan.son[meth] == fa) fafan.son[meth] = curr;

		if (fafan.son[meth ^ 1] == fa) fafan.son[meth ^ 1] = curr;
	}

	pushup(fa);
	pushup(curr);

	if (ifrotateff) pushup(fafa);
}

inline void insert(int k, int val)
{
	// root -> k = 0
	if (cnt == 1) {
		t[cnt++].val = val;
		t[cnt].size = 1;
		t[cnt].father = 0;
		t[cnt].turn = 0;
		pushup(k);
		return;
	}

	node &curr = t[k];
	int proc = val > curr.val;

	if (curr.son[proc] == 0) {
		t[cnt].val = val, curr.son[proc] = cnt, t[cnt].father = k, t[cnt].size = 1, t[cnt].turn = 0;
		++cnt;
	} else insert(curr.son[proc], val);

	if (t[k].messt.priority > t[t[k].father].messt.priority) {
		rotate(k);
	}

	pushup(k);
}

inline void subreb(int &k, int l, int r)
{
	if (l > r) return;

	int mid = (l + r) >> 1;
	k = ++cnt;
	t[k].val = templ[mid];
	subreb(t[k].son[0], l, mid - 1);
	subreb(t[k].son[1], mid + 1, r);
	t[t[k].son[0]].father = t[t[k].son[1]].father = k; // �Լ����ӵĸ������Լ�(����)
	pushup(k);
}

inline void rebuild(int k)
{
	int currcnt = cnt;
	templ.clear();
	print(k, true); // init the lst k
	subreb(k, 0, templ.size() - 1);
	root = currcnt + 1;
}

inline int find(int k, int val)
{
	if (t[k].val == val) return k;

	if (val <= t[k].val && t[k].son[0]) return find(t[k].son[0], val);
	else if (t[k].son[1]) return find(t[k].son[1], val);
}

inline int getkth(int k, int val)
{
	// by LittleRewriter
	if (val > cnt) return 0;

	if (t[t[k].son[0]].size + 1 == val) return t[k].val;
	else if (t[k].son[0] && val <= t[t[k].son[0]].size)
		return getkth(t[k].son[0], val);
	else if (t[k].son[1] && val >= t[t[k].son[0]].size + 2)
		return getkth(t[k].son[1], val - t[t[k].son[0]].size - 1);
}

inline int subgetrank(int k, int val, int cnt)
{
	// by LittleRewriter
	if (t[k].val == val) return cnt + t[t[k].son[0]].size + 1;
	else if (t[k].son[0] && t[k].val > val) return subgetrank(t[k].son[0], val, cnt);
	else if (t[k].son[1] && t[k].val < val) return subgetrank(t[k].son[1], val, cnt + t[t[k].son[0]].size + 1);
}

// ��Ϊ���е�ԭ�� ����ֱ�ӵ��� ���Լ���һ���Ӻ���
inline int getrank(int k, int val)
{
	if (!find(k, val)) return 0;

	return subgetrank(k, val, 0);
}

inline int prenxtnode(int val, int meth)
{
	// by LR
	// 1 -> next
	// 0 -> pre
	// waiting for modifying
	int idx = find(root, val);

	if (idx == 0) return -1;

	if (t[idx].son[meth]) {
		idx = t[idx].son[meth];

		while (t[idx].son[meth ^ 1]) idx = t[idx].son[meth ^ 1];
	}

	while (t[idx].father != 0) {
		if (t[t[idx].father].son[meth ^ 1] == idx) return t[t[idx].father].val;

		idx = t[idx].father;
	}

	return -1;
}

inline void splay(int s, int e)
{
	// ��index s �� e
	int fa, fafa;

	while (s != e) {

	}
}
}
namespace DEBUG
{
using namespace BST;
const int cntm = 1e5;

inline void printOut()
{
	int cnt = 0;
	print(root, true);
	queue <BST::node> q;
	q.push(t[root]);
	cout << "root: " << t[root].val << endl;

	while (!q.empty()) {
		if (cnt > cntm) break;

		++cnt;
		node curr = q.front();
		q.pop();
		cout << curr.val << "'s son: ";

		for (int j = 0; j <= 1; ++j)
			for (int i = 0; i < p.size(); ++i) {
				if (p[i].val == t[curr.son[j]].val) {
					q.push(p[i]);
					cout << p[i].val << " ";
				}
			}

		cout << endl;
	}

	p.clear();
}
}

/*
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    srand(time(NULL));
    using namespace BST;
    using namespace BASIC;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int opt, x;
        cin >> opt;
        if(opt == 1) cin >> x, insert(root, x);
        if(opt == 2) cout << "delete function" << endl;
        if(opt == 3) cin >> x, cout << getrank(root, x) << endl;
        if(opt == 4) cin >> x, cout << getkth(root, x) << endl;
        if(opt == 5) cin >> x, cout << prenxtnode(x, 0) << endl; // waiting
        if(opt == 6) cin >> x, cout << prenxtnode(x, 1) << endl; // waiting
    }
    return 0;
}
*/
int main()
{
	srand(time(NULL));
	using namespace DEBUG;
	using namespace BST;
	int n;
	cin >> n;

	for (int k, i = 0; i < n; ++i) {
		cin >> k;
		insert(root, k);
	}

	// printOut();
	// print(root, false);
	// cout << prenxtnode(4, 1) << endl;
	// cout << prenxtnode(4, 0) << endl;

}
/*
6
2 8 9 6 4 1
*/
/*
9
1 6 7 4 3 8 9 2 5
*/
/*
9
1 2 3 4 5 6 7 8 9
*/

