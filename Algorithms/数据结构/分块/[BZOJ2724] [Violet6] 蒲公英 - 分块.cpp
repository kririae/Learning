// by kririae
#define ll long long
#include <bits/stdc++.h>

using namespace std;

namespace Violet6
{
inline char gc() 
{ 
	static char buf[1 << 18], *fs, *ft;
	return (fs == ft && (ft = (fs = buf) + fread(buf, 1, 1 << 18, stdin)), fs == ft) ? EOF : *fs++;
}
inline int read() 
{ 
	register int k = 0, f = 1;
	register char c = gc();
	for(; !isdigit(c); c = gc()) if(c == '-') f = -1;
	for(; isdigit(c); c = gc()) k = k * 10 + c - '0';
	return k * f;
}

const int maxn = 50005;

struct Val
{
	int val, id;
	bool operator < (const Val &a) const
	{ return val == a.val ? id < a.id : val < a.val; }
};

int n, m, all, siz, num, A[maxn], C[maxn];
int L[maxn], R[maxn], belong[maxn];
Val B[maxn];
vector<int> cnt[maxn];

inline int query(int l, int r, int val)
{
	int pos = lower_bound(c + 1, c + 1 + all, val) - c;
	int ql = lower_bound(cnt[pos].begin(), cnt[pos].end(), l) - cnt[pos].begin();
	int qr = upper_bound(cnt[pos].begin(), cnt[pos].end(), r) - cnt[pos].begin() - 1;
	return qr - ql + 1;
}

inline void solve()
{
	read(n);//, read(m);
	siz = sqrt(n);
	num = n % siz ? n / siz + 1 : n / siz;
	for (int i = 1; i <= n; ++i)
		read(A[i]), B[i].val = A[i], B[i].id = i;
	sort(B + 1, B + 1 + n);
	for (int i = 1; i <= n; ++i)
	{
		if(B[i].val != B[i - 1].val) C[++all] = B[i].val;
		cnt[all].push_back(B[i].id);
	}
	for (int i = 1; i <= all; ++i)
		sort(cnt[i].begin(), cnt[i].end());
	for (int i = 1; i <= num; ++i)
		L[i] = R[i - 1] + 1, R[i] = L[i] + siz - 1;
	R[num] = n;
	for (int i = 1; i <= num; ++i)
		for (int j = L[i]; j <= R[i]; ++j)
			belong[j] = i;
			

}
}

int main()
{
	Violet6::solve();
	return 0;
}