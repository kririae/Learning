#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
const int L = 0, R = 1;

struct Message { //节点维护的信息
	long long sum, len, add; //区间和 区间长度 区间lazy的加法
	Message() { //初始化函数
		sum = 0;
		add = 0;
		len = 0;
	}
	Message(long long xsum, long long xadd, long long xlen) { //初始化函数
		sum = xsum;
		add = xadd;
		len = xlen;
	}
	Message operator +(const Message &b) { //定义 a+b
		Message p(sum + b.sum, 0, len + b.len); //p.sum = sum+b.sum p.add=0 p.len=len+b.len
		return p;
	}
	void modify(Message fa) { //父亲的信息为fa ， 父亲pushdown下传
		sum += len * fa.add;
		add += fa.add;
	}
};

struct SegmentTree {
	int l, r; //当前管理区间 [l,r]
	int son[2];//左儿子为 son[0] 右儿子为 son[1]
	Message x;
} node[N * 2];

void pushdown(int k) { //下传标记
	if( node[k].x.add != 0 ) {
		node[ node[k].son[L] ].x.modify( node[k].x );
		node[ node[k].son[R] ].x.modify( node[k].x );
		node[k].x.add = 0;
	}
}

void update(int k) { //更新节点k
	node[k].x = node[node[k].son[L]].x + node[node[k].son[R]].x;
}


int root, ini[N], cnt; //cnt 当前已经有了多少个节点
//假设数组初始时为ini

void buildTree(int &k, int l, int r) { //初始化一个管理[l,r]的节点 ， 下标为k
	k = ++cnt;
	node[k].l = l;
	node[k].r = r;
	node[k].x.len = (r - l + 1); //初始化[l,r] //k = cnt+1; cnt++;

	if(l == r) { //没有儿子了
		node[k].x.sum = ini[l];
	} else { //我是爸爸
		int mid = ( node[k].l + node[k].r ) / 2; //儿子的左右分界
		buildTree(node[k].son[L], l, mid); //调用完后 左右儿子下表就可以被储存
		buildTree(node[k].son[R], mid + 1, r);
		update(k);
	}
}

Message work(int k, int ql, int qr, Message y) { //修改 [ql,qr] 顺带查询[ql,qr]
	if( node[k].l == ql && node[k].r == qr ) {
		node[k].x.modify(y);
		return node[k].x;
	} else {
		Message p;
		pushdown(k);
		int mid = (node[k].l + node[k].r) / 2;

		if(qr <= mid) p = work(node[k].son[L], ql, qr, y);
		else if(mid < ql) p = work(node[k].son[R], ql, qr, y);
		else p = work(node[k].son[L], ql, mid, y) + work(node[k].son[R], mid + 1, qr, y);

		update(k);
		return p;
	}
}

int n, m;
int main() {
	scanf("%d", &n);

	for(int i = 1; i <= n; i++) scanf("%d", &ini[i]);

	buildTree(root, 1, n);

	Message y, ans;
	int l, r, val;
	//区间[l,r] += val
	y.add = val;
	work(root, l, r, y);
	//查询区间[l,r]
	y.add = y.len = y.sum = 0;
	ans = work(root, l, r, y);
	cout << ans.sum << endl;
	//

	//

	return 0;
}
