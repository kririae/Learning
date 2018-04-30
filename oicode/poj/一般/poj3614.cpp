#include <bits/stdc++.h>

using namespace std;

namespace poj3614
{
const int maxn = 2500 + 5;

struct Cow
{
	int minSPF, maxSPF;
	bool operator < (const Cow &a) const 
	{ return minSPF > a.minSPF; }
};

struct Node
{
	int SPF, cover;
	bool operator < (const Node &a) const 
	{ return SPF < a.SPF; }
};

int n, m, cnt;
Cow a[maxn];
Node b[maxn];

inline void solve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i].minSPF >> a[i].maxSPF;

	for (int i = 1; i <= m; ++i)
		cin >> b[i].SPF >> b[i].cover;
		
    sort(b + 1, b + 1 + m);
    sort(a + 1, a + 1 + n);
    
	for (int i = 1; i <= n; ++i)
	{
		for (int j = m; j >= 1; --j)
		{
		    if(b[j].cover > 0 && b[j].SPF >= a[i].minSPF && b[j].SPF <= a[i].maxSPF)
		    {
		        --b[j].cover;
		        ++cnt;
		        break;
		    }
		}
	}

	cout << cnt << endl;
}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	poj3614::solve();
	return 0;
}