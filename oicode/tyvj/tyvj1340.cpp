// status TLE
#define ll long long 
#include <bits/stdc++.h>
using namespace std;

namespace kririae
{
const int maxn = 45;
ll w, n, mid, res;
vector<ll> a, b, c, d;

inline void solve()
{
    cin >> w >> n;
    mid = n / 2;
    ll tmp;
    for (int i = 1; i <= mid; ++i)
    {
    	cin >> tmp;
    	a.push_back(tmp);
    }
    
    for (int i = mid + 1; i <= n; ++i)
    {
    	cin >> tmp;
    	b.push_back(tmp);
    }
    
    c.push_back(0);
    for (int i = 0; i < 1 << (a.size()); ++i) // 枚举子集 
    {
    	ll summ = 0;
    	for (int j = 0; j < a.size(); ++j)
    		if(i & (1 << j)) summ += a[j];
    	c.push_back(summ);
    }
    
    d.push_back(0);
	for (int i = 0; i < 1 << (b.size()); ++i) // 枚举子集 
    {
    	ll summ = 0;
    	for (int j = 0; j < b.size(); ++j)
    		if(i & (1 << j)) summ += b[j];
    	d.push_back(summ);
    }
    
    sort(c.begin(), c.end());
    
	for (int i = 1; i <= d.size(); ++i)
	{
		int l = 1, r = c.size() - 1;
		while(l < r)
		{
			int m = (l + r) / 2 + 1;
			if(d[i] + c[m] > w) r = m - 1;
			else l = m;
		}
		if(d[i] + c[l] <= w) res = max(res, d[i] + c[l]);
	}
	cout << res << endl;
}
}

int main()
{
    kririae::solve();
    return 0;
}