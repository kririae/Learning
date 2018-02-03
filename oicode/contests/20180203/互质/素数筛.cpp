#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
int n;
bitset<maxn> last;
vector<int> res;
int main() {
	n = 33;
	for (int i = 2; i <= n; ++i) {
		if(!last[i]) res.push_back(i);
		for (int j = i << 1; j <= n; j += i) last[j] = true;
	}
	for (int i = 0; i < res.size(); ++i) cout << res[i] << " ";
	return 0;
}
