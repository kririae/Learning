#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

namespace SSWY
{
const int maxn = 505;

int n, t, ans, f[1 << 8][1 << 8], g[2][1 << 8][1 << 8];
// f[S_1][S_2]表示两个人选择的质因子的集合是？
// G[S_1][S_2][0/1]表示 
long long P;
bitset<maxn> vis;
vector<int> p, s[maxn];

template<typename T>
inline void inc(T &a, T b)
{
	a = (long long)(a + b) % P;
}

inline void solve()
{
	register int s1, s2;
	cin >> n >> P;
	
	for (int i = 2; i <= sqrt(500); ++i)
	{
		if(!vis[i]) p.push_back(i);
		for (int j = (i << 1); j <= sqrt(500); j += i)
			vis[j] = 1;
	}	
	t = 1 << p.size();	

	f[0][0] = 1;
	
	for (int i = 1; i < n; ++i)
	{
		int val = i + 1, S = 0;
		for (int j = 0; j < p.size(); ++j)
			while(val % p[j] == 0) S |= (1 << j), val /= p[j];
		s[val].push_back(S);  
	}
	
	for (int i = 0; i < s[1].size(); ++i)
	{
		for (s1 = t - 1; s1 >= 0; --s1)
			for (s2 = t - 1; s2 >= 0; --s2)
				inc(f[s1 | s[1][i]][s2], f[s1][s2]),
				inc(f[s1][s2 | s[1][i]], f[s1][s2]);
	}

	for (int i = 2; i <= 500; ++i)
	{
		if(!s[i].size()) continue;
		memcpy(g[0], f, sizeof(f));
		memcpy(g[1], f, sizeof(f));
		
		for (int j = 0; j < s[i].size(); ++j)
		{
			int S = s[i][j];
			for (s1 = t - 1; s1 >= 0; --s1)
				for (s2 = t - 1; s2 >= 0; --s2)
				{
					// 如果选取当前的数，加入S1集合之后不冲突，那么可以加入S1集合，这个时候是小G选择 
					if((S & s2) == 0) inc(g[0][s1 | S][s2], g[0][s1][s2]);
					// 如果加入S2集合不冲突，那么这时候是小W选择 
					if((S & s1) == 0) inc(g[1][s1][s2 | S], g[1][s1][s2]);
				}
		} 
		
		for (s1 = 0; s1 < t; ++s1)
			for (s2 = 0; s2 < t; ++s2)
				f[s1][s2] = ((g[0][s1][s2] + g[1][s1][s2] - f[s1][s2]) % P + P) % P;
	}
	
	for (s1 = 0; s1 < t; ++s1)
		for (s2 = 0; s2 < t; ++s2)
			if((s1 & s2) == 0) 
				inc(ans, f[s1][s2]);
	
	cout << ans << endl;
}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);	
	SSWY::solve();
	return 0;
}