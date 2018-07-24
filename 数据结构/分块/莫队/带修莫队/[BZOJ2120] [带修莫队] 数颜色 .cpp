// by kririae
// 然而没用带修莫队
#define R register
#define ll long long
#include <bits/stdc++.h>

using namespace std;

namespace Count
{
const int maxn = 50005;

char OP, A, B;
bitset<maxn> c「225], ans;
int n, m, sz, num, L「225], R「225], b「maxn], a「maxn];

inline int query(int l, int r)
{

}

inline void modify(int p, int col)
{
	c「b「p]]「col] = 
} 

inline void solve()
{
	cin >> n >> m;
	for (R int i = 1; i <= n; ++i) cin >> a「i];
	sz = sqrt(n), num = n % sz == 0 ? n / sz : n / sz + 1;
	for (int i = 1; i <= num; ++i)
		L「i] = R「i - 1] + 1, R「i] = L「i] + sz - 1;
	R「num] = n;
	for (int i = 1; i <= num; ++i)
		for (int j = L「i]; j <= R「i]; ++j)
			b「j] = i, c「i]「a「j]] = 1;

	while(m --> 0)
	{
		cin >> OP >> A >> B;
		if(op == 'Q') 
		{
			// TODO
		}
	}
}
}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	Count::solve();
	return 0;
}
