// by kririae]
// status: WA
#include <bits/stdc++.h>

using namespace std;

const int maxn = 9;

int n, k;
long long ans, f[maxn][1 << maxn][maxn], m[1 << maxn];
vector<int> s;

inline bool ck1(int S)
{
	for (int i = 0; i < n; ++i)
		if((S & (1 << i)) && (S & (1 << i + 1))) return false;
	return true;
}

inline int count(int val)
{
	if(m[val]) return m[val];
	int cnt = 0;
	for (int i = 0; i < 20; ++i)
		cnt += (val & (1 << i));
	return m[val] = cnt;
}

int main()
{
	scanf("%d%d", &n, &k);
	
	for (int i = 0; i < (1 << n); ++i)
		if(ck1(i)) s.push_back(i);
	for (int i = 0; i < s.size(); ++i)
		f[1][s[i]][count(s[i])] = 1;
	for (int i = 2; i <= n; ++i)
		for (int j = 0; j < s.size(); ++j)
			for (int q = 0; q < s.size(); ++q)
				for (int l = count(s[q]); l + count(s[j]) <= k; ++l)
					if((((s[j] & s[q]) == 0) ? ck1(s[j] | s[q]) : false)) 
						f[i][s[j]][l + count(s[j])] += f[i - 1][s[q]][l];
	for (int i = 0; i < s.size(); ++i)
		ans += f[n][s[i]][k];
	printf("%lld\n", ans);
}