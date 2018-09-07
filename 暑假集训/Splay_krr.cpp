#include <bits/stdc++.h>
#define ll long long
#define ls son[k][0]
#define rs son[k][1]
using namespace std;

const int N = 100005;
int cnt, f[N], son[N][2], siz[N], key[N];
inline void pushup(int k) {
	siz[k] = siz[ls] + siz[rs];
}
inline int sid(int k) {
	return son[fa[k]][1] == k;
}
inline void Rotate(int k) {
	int s = sid(k), f = fa[x];
	if (son[f][0] = son[k][1]) fa[son[f][0]] = f;
	if (fa[x] = fa[f]) son[fa[k]][sid(f)] = k;
	else root = x;
	pushup(son[x][d ^ 1] = f);
	pushup(fa[f] = x);
}
inline void Splay(int x) {
	for (int f; f = fa[x]; Rotate(x)) 
		if (fa[f]) Rotate(sid(f) == sid(x) ? f : x);
}
inline void Insert(int &k, int fa, int x) {
	if (k) {
		++siz[k];
		Insert(x < key[k] ? ls : rs, k, x);
	} else {
		k = ++cnt;
		f[k] = fa;
		siz[k] = 1;
		key[k] = x;
		Splay(k);
	}
}
int main() {

}