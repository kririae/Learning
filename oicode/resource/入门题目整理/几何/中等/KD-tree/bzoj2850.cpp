/*
KD-tree
*/
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#define M 2
#define N 50005
#define db int
#define eps 1e-5
#define INF 0x3f3f3f3f
#define LL long long
using namespace std;
//----------------------
int A, B, C;
bool check(int x, int y) {
	return A * x + B * y < C;
}
//--kd-tree-------------
//好像很好写
const int L = 0, R = 1;
struct node {
	db mm[M], mx[M];
	db key[M];
	LL val, sum;
	int fr, to, p;
	int son[2];
} a[N];
int sor[N];
int canshu;
inline bool cmpk(const int &a1, const int &b1) {
	return a[a1].key[canshu] < a[b1].key[canshu];
}
inline void update(int k) {
	a[k].sum = a[a[k].son[L]].sum + a[a[k].son[R]].sum + a[k].val;

	for(int i = 0; i < M; i++) {
		a[k].mm[i] = a[k].key[i];
		a[k].mx[i] = a[k].key[i];

		for(int s = 0; s < 2; s++) {
			if(a[k].son[s] != 0) {
				a[k].mm[i] = min(a[k].mm[i], a[a[k].son[s]].mm[i]);
				a[k].mx[i] = max(a[k].mx[i], a[a[k].son[s]].mx[i]);
			}
		}
	}
}
inline int pd(int &mmx, int &mxx, int &mmy, int &mxy) { //如果懒得写可以直接交替划分
	return (mxx - mmx) < (mxy - mmy) ? 1 : 0;
}
int build(int fr, int to, int mmx, int mxx, int mmy, int mxy) {
	int mid = (fr + to) >> 1;
	canshu = pd(mmx, mxx, mmy, mxy);
	nth_element(sor + fr, sor + mid, sor + to + 1, cmpk);
	a[sor[mid]].p = canshu;
	int k = sor[mid];

	if(canshu == 0) {
		if(fr != mid) a[k].son[L] = build(fr, mid - 1, mmx, a[k].key[0], mmy, mxy);

		if(mid != to) a[k].son[R] = build(mid + 1, to, a[k].key[0], mxx, mmy, mxy);
	} else if(canshu == 1) {
		if(fr != mid) a[k].son[L] = build(fr, mid - 1, mmx, mxx, mmy, a[k].key[1]);

		if(mid != to) a[k].son[R] = build(mid + 1, to, mmx, mxx, a[k].key[1], mxy);
	}

	update(k);
	return k;
}
inline int judge(int k) {
	int bl = check(a[k].mm[0], a[k].mm[1]);
	int ret = bl;
	bl = check(a[k].mx[0], a[k].mm[1]);

	if(bl ^ ret) return -1;

	bl = check(a[k].mm[0], a[k].mx[1]);

	if(bl ^ ret) return -1;

	bl = check(a[k].mx[0], a[k].mx[1]);

	if(bl ^ ret) return -1;

	return ret;
}
LL get_left(int k) {
	if(k == 0) return 0;

	int t = judge(k);

	if(t == 1) return a[k].sum;
	else if(t == 0) return 0;

	int ret = 0;

	if(check(a[k].key[0], a[k].key[1])) ret += a[k].val;

	return ret + get_left(a[k].son[L]) + get_left(a[k].son[R]);
}
//---------------------
int n, m;
int main() {
	scanf("%d%d", &n, &m);
	int mmx, mxx, mmy, mxy;
	mmx = mmy = INF;
	mxx = mxy = -INF;

	for(int i = 1; i <= n; i++) {
		int aa, bb, cc;
		scanf("%d%d%d", &aa, &bb, &cc);
		a[i].key[0] = aa;
		a[i].key[1] = bb;
		a[i].val = cc;
		mmx = min(mmx, aa);
		mxx = max(mxx, aa);
		mmy = min(mmy, bb);
		mxy = max(mxy, bb);
	}

	for(int i = 1; i <= n; i++) sor[i] = i;

	int root = build(1, n, mmx, mxx, mmy, mxy);
	a[0].p = -1;

	for(int i = 1; i <= m; i++) {
		scanf("%d%d%d", &A, &B, &C);
		printf("%lld\n", get_left(root));
	}

	return 0;
}
