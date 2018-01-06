#include<cstdio>
#include<cmath>
#include<algorithm>
#define N 1000005
#define INF 0x7fffffff
using namespace std;
//-----------------kd----
int KD;
const int M = 2;
const double alpha = 0.75;
struct point {
	int key[2];
	bool operator <(const point &b)const {
		return key[KD] < b.key[KD];
	}
};
int LIM;
inline int getdis(const point &p1, const point &p2) {
	return abs(p1.key[0] - p2.key[0]) + abs(p1.key[1] - p2.key[1]);
}
struct KD_node {
	point me;
	int mm[2], mx[2];
	int size;
	int son[2];
} kd[N];
inline int judge(int k, const point &p) { //好愉快写成了bool
	if(k == 0) return INF;

	return max(0, kd[k].mm[0] - p.key[0]) + max(0, p.key[0] - kd[k].mx[0]) +
	       max(0, kd[k].mm[1] - p.key[1]) + max(0, p.key[1] - kd[k].mx[1]);
}
int kd_cnt;
const int L = 0, R = 1;
inline void update(int k) {
	kd[k].size = kd[kd[k].son[L]].size + kd[kd[k].son[R]].size + 1;
	kd[k].mm[0] = kd[k].mx[0] = kd[k].me.key[0];

	if(kd[k].son[L]) {
		kd[k].mm[0] = min(kd[k].mm[0], kd[kd[k].son[L]].mm[0]);
		kd[k].mx[0] = max(kd[k].mx[0], kd[kd[k].son[L]].mx[0]);
	}

	if(kd[k].son[R]) {
		kd[k].mm[0] = min(kd[k].mm[0], kd[kd[k].son[R]].mm[0]);
		kd[k].mx[0] = max(kd[k].mx[0], kd[kd[k].son[R]].mx[0]);
	}

	kd[k].mm[1] = kd[k].mx[1] = kd[k].me.key[1];

	if(kd[k].son[L]) {
		kd[k].mm[1] = min(kd[k].mm[1], kd[kd[k].son[L]].mm[1]);
		kd[k].mx[1] = max(kd[k].mx[1], kd[kd[k].son[L]].mx[1]);
	}

	if(kd[k].son[R]) {
		kd[k].mm[1] = min(kd[k].mm[1], kd[kd[k].son[R]].mm[1]);
		kd[k].mx[1] = max(kd[k].mx[1], kd[kd[k].son[R]].mx[1]);
	}
}
point buf[N];
int cnt;
int name_buf[N];
int name_top;
void build(int &k, int fr, int to, int p) {
	KD = p;
	int mid = (fr + to) >> 1;
	nth_element(buf + fr, buf + mid, buf + to + 1);
	k = name_buf[name_top--];
	kd[k].me = buf[mid];
	kd[k].son[0] = kd[k].son[1] = 0;

	if(fr != mid) build(kd[k].son[L], fr, mid - 1, p ^ 1);

	if(mid != to) build(kd[k].son[R], mid + 1, to, p ^ 1);

	update(k);
}
void pickup(int k) {
	buf[++cnt] = kd[k].me;
	name_buf[++name_top] = k;

	if(kd[k].son[L] != 0) pickup(kd[k].son[L]);

	if(kd[k].son[R] != 0) pickup(kd[k].son[R]);
}
int build_flag, ss, huah;
int *kk;
void insert(int &k, const point &p, int hua) {
	if(k == 0) {
		k = ++kd_cnt;
		kd[k].me = p;
		kd[k].son[L] = kd[k].son[R] = 0;
		update(k);
		return;
	}

	kd[k].size++;
	int s = p.key[hua] < kd[k].me.key[hua] ? L : R;
	insert(kd[k].son[s], p, hua ^ 1); //update(k);

	if(kd[k].size * alpha < kd[kd[k].son[s]].size) build_flag = k, kk = &k, huah = hua;

	update(k);
}
void get_near(int k, const point &p) {
	int t = getdis(p, kd[k].me);
	LIM = min(LIM, t);
	int d[2];
	d[L] = judge(kd[k].son[L], p);
	d[R] = judge(kd[k].son[R], p);
	int s = d[L] < d[R] ? L : R;

	if(kd[k].son[s] != 0 && d[s] < LIM) get_near(kd[k].son[s], p);

	if(kd[k].son[s ^ 1] != 0 && d[s ^ 1] < LIM) get_near(kd[k].son[s ^ 1], p);
}
//-----------------------
int n, m;
int main() {
	scanf("%d%d", &n, &m);

	for(int i = 1; i <= n; i++) {
		scanf("%d%d", &buf[i].key[0], &buf[i].key[1]);
		name_buf[++name_top] = i;
	}

	kd_cnt = n;
	cnt = n;
	int root = 0;
	build(root, 1, cnt, 0);

	for(int i = 1; i <= m; i++) {
		int ins;
		point c;
		scanf("%d%d%d", &ins, &c.key[0], &c.key[1]);

		if(ins == 1) {
			build_flag = 0;
			insert(root, c, 0);

			if(build_flag != 0) {
				cnt = 0;
				name_top = 0;
				pickup(*kk);
				build(*kk, 1, cnt, huah);
			}
		} else {
			LIM = 0x7fffffff;
			get_near(root, c);
			printf("%d\n", LIM);
		}
	}

	return 0;
}
