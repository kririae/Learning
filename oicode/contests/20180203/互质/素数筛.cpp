#include <bits/stdc++.h> 
using namespace std; 
const int maxn = 1e7 + 5; 
int n, m, val; 
bitset<maxn> last; 
vector<int> res; 
int main() { 
	// WA
	cin.tie(0); 
	ios::sync_with_stdio(false); 
	cin >> n >> m; 
	for (int i = 2; i <= n; ++i) { 
		// if(!last[i]) ; 
		for (int j = i << 1; j <= n; j += i) last[j] = true; 
	} 
	for (int i = 1; i <= m; ++i) { 
		cin >> val; 
		if(last[val]) { cout << "No" << endl; }
		else { cout << "Yes" << endl; } 
	}
	return 0; 
} 
