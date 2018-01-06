/*
poj 3714
*/
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cmath>
#define N 100005
#define D 2//维度 
#define LL long long
#define SIZE 2
#define EPS 2
using namespace std;
int n;
const int L = 0, R = 1;
//KD-Tree
struct point {
	LL x[D];
} p[N];
inline LL getdis(point &a, point &b) {
	LL ret = 0;

	for(int i = 0; i < D; i++) {
		ret += (a.x[i] - b.x[i]) * (a.x[i] - b.x[i]);
	}

	return ret;
}
int k[N], m[N], left[N], right[N], mid[N], son[N][D], leave[N]; //k-维度  m-划分值  leave叶节点标志
int cnt = 0;
int box[N];//box-用于装点的
inline LL sqr(LL a) {
	return a * a;
}
void build(int &z, int l, int r) { //像快排一样写
	z = ++cnt; //当前结点编号
	left[z] = l;
	right[z] = r;
	son[z][L] = son[z][R] = 0;
	leave[z] = 0;
	mid[z] = 0;
	k[z] = 0;
	m[z] = 0;

	if(l + 1 >= r) {
		leave[z] = 1;
		return;//叶节点
	}

	LL fx[D + 1], pj[D + 1];

	//计算方差
	for(int i = 0; i < D; i++) {
		fx[i] = pj[i] = 0;
	}

	for(int j = 0; j < D; j++)
		for(int i = l; i <= r; i++) {
			pj[j] += p[box[i]].x[j];
			fx[j] += sqr(p[box[i]].x[j]);
		}

	for(int i = 0; i < D; i++) {
		pj[i] /= n;
		fx[i] -= sqr(pj[i]) * n; //有点误差无所谓
	}

	k[z] = 0;

	for(int i = 1; i < D; i++) {
		if(fx[i] > fx[k[z]]) {
			k[z] = i;
		}
	}

	m[z] = pj[k[z]];

	//好的算完了方差最大的一个维度 k[z]
	//为了减少一个logn,我们采用平均数划分，不采用中位数，当方差过小以及个数较小时，不再往下分
	if(fx[k[z]] < EPS && (r - l + 1 < SIZE)) {
		leave[z] = 1;
		return;//叶节点
	}

	int l1 = l, r1 = r, t = k[z];

	while(l1 < r1) {
		while(p[box[l1]].x[t] < pj[t] && (l1 < r1)) {
			l1++;
		}

		while(p[box[r1]].x[t] >= pj[t] && (l1 < r1)) {
			r1--;
		}

		if(l1 < r1)
			swap(box[l1], box[r1]);
	}

	if(p[box[l1]].x[t] <= pj[t])
		mid[z] = l1;
	else mid[z] = l1 - 1;

	build(son[z][L], l, mid[z]);
	build(son[z][R], mid[z] + 1, r);
}
struct pa {
	LL dis, name;
	inline bool operator <(const pa &b)const {
		return dis > b.dis;
	}
};
LL find(point &a, int z, priority_queue<pa> &pq) {
	LL ret = 1e12 + 1;

	if(leave[z]) {
		for(int i = left[z]; i <= right[z]; i++) {
			LL t = getdis(a, p[box[i]]);

			if(t < ret) ret = t;
		}
	} else {
		if(a.x[k[z]] < m[z]) {
			pq.push((pa) {
				sqr(m[z] - a.x[k[z]]), son[z][R]
			});
			ret = find(a, son[z][L], pq);
		} else {
			pq.push((pa) {
				sqr(m[z] - a.x[k[z]]), son[z][L]
			});
			ret = find(a, son[z][R], pq);
		}
	}

	return ret;
}
int root;
LL search(point &p) {
	LL ret = 1e12 + 1;
	priority_queue<pa> pq;
	ret = find(p, root, pq);

	while(!pq.empty()) {
		pa t = pq.top();
		pq.pop();

		if(t.dis >= ret) break;

		LL re = find(p, t.name, pq);

		if(re < ret) ret = re;
	}

	return ret;
}
inline bool cmp1(const point &a, const point &b) {
	if(a.x[0] == b.x[0]) return a.x[1] < b.x[1];

	return a.x[0] < b.x[0];
}
inline bool equ(const point &a, const point &b) {
	if(a.x[0] == b.x[0]) {
		if(a.x[1] == b.x[1])
			return true;
	}

	return false;
}
void build_tree() {
	sort(p + 1, p + n + 1, cmp1); //去除重复点，加速KD-tree
	cnt = 0;
	int p2 = 2;
	box[1] = 1;

	for(int i = 2; i <= n; i++) {
		if(!equ(p[i], p[i - 1])) {
			box[p2++] = i;
		}
	}

	build(root, 1, p2 - 1);
}
//万恶的KD-Tree
int t;
int main() {
	scanf("%d", &t);

	while(t--) {
		scanf("%d", &n);

		for(int i = 1; i <= n; i++) {
			scanf("%lld%lld", &p[i].x[0], &p[i].x[1]);
		}

		build_tree();
		point tem;
		LL ans = 1e12 + 1;

		for(int i = 1; i <= n; i++) {
			scanf("%lld%lld", &tem.x[0], &tem.x[1]);
			ans = min(ans, search(tem));
		}

		printf("%.3f\n", (double)sqrt((long double)ans));
	}

	return 0;
}
