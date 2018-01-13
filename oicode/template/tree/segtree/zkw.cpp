#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
using ll = long long;
inline ll read()
{
	char c;
	ll k;

	while(!isspace(c = getchar()) && isdigit(c))
		k = k * 10 + c - '0';

	return k;
}
struct Message {
	ll sum;
	int min;
	int max;
	int sub;
	/*
	inline void modifyMax(int i) {
		node[i].max = max(node[i << 1].max, node[i << 1 | 1].max);
	}
	inline void modifyMin(int i) {
		node[i].min = min(node[i << 1].min, node[i << 1 | 1].min);
	}
	inline void modifySum(int i) {
		node[i].sum = node[i << 1].sum + node[i << 1 | 1].sum;
	}
	inline void modifySub(int i) {
		node[i << 1].sub -= node[i].sub;
		node[i << 1 | 1].sub -= node[i].sub;
	}*/
};
// Message node[maxn];
int node[maxn];
int M;
/*
inline void pushup(int k) {
	node[k].modifySum(k);
	node[k].modifyMin(k);
	node[k].modifyMax(k);
}
*/
inline void buildTree(int n)
{
	for (M = 1; M < n; M <<= 1);

	for (int i = M; i < M + n; ++i)
		node[i] = read();

	for (int i = M - 1; i >= 0; --i) {
		node[i] = min(node[i << 1], node[i << 1 | 1]), node[i << 1] -= node[i], node[i << 1 | 1] -= node[i];
	}
}
inline void modifyPoint(int k, int val)
{
	node[M + k] = val;

	for (int i = M + k; i >= 0; i >>= 1) {
		node[i] = min(node[i << 1], node[i << 1 | 1]), node[i << 1] -= node[i], node[i << 1 | 1] -= node[i];
	}
}
inline ll sumOnepoint(int k)
{
	ll res = 0;

	for (int i = k; i >= 0; i >>= 1) res += node[i];

	return res;
}
inline ll sumRange(int ql, int qr)
{
	ql += M - 1, qr += M + 1;
	ll res = 0;

	for (; ql ^ qr ^ 1; ql >>= 1, qr >>= 1) {
		if(~ql & 1) res += node[ql ^ 1];

		if(qr & 1) res += node[qr ^ 1];
	}

	return
}
int main()
{
	return 0;
}