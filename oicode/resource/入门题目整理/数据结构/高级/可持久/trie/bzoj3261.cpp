#include<cstdio>
#include<iostream>
#define N 600005
#define M 20000005
using namespace std;
int n, m, cnt, rootbuf, root[N], cnt2, xall; //∑√Œ root[-1]≤ªª·À¿∞…
const int L = 0, R = 1;
struct node {
	int son[2], size, deepth;
} a[M];
void insert(int &k, int x, int p) { //p=31..0
	int t = ++cnt;
	a[t].size = a[k].size + 1;
	a[t].son[L] = a[k].son[L];
	a[t].son[R] = a[k].son[R];
	k = t;

	if(p == 0) return;

	insert(a[t].son[(x & (1 << (p - 1))) >> (p - 1)], x, p - 1);
}
int ans;
void ask(int k1, int k2, int x, int p) {
	if(p == 0) return;

	int s = ((x & (1 << (p - 1))) >> (p - 1)) ^ 1;

	if(a[a[k2].son[s]].size - a[a[k1].son[s]].size != 0) {
		ans ^= (1 << (p - 1));
		ask(a[k1].son[s], a[k2].son[s], x, p - 1);
	} else {
		ask(a[k1].son[s ^ 1], a[k2].son[s ^ 1], x, p - 1);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	root[0] = 0;
	insert(root[0], 0, 31);

	for(int i = 1, t; i <= n; i++) {
		scanf("%d", &t);
		root[i] = root[i - 1];
		xall ^= t;
		insert(root[i], xall, 31);
	}

	cnt2 = n;

	for(int i = 1; i <= m; i++) {
		char s[5];
		int l, r, t;
		scanf("%s", s);

		if(s[0] == 'A') {
			scanf("%d", &t);
			++cnt2;
			root[cnt2] = root[cnt2 - 1];
			xall ^= t;
			insert(root[cnt2], xall, 31);
		} else {
			scanf("%d%d%d", &l, &r, &t);
			ans = 0;
			ask(root[l - 2], root[r - 1], t ^ xall, 31);
			printf("%d\n", ans);
		}
	}

	return 0;
}
