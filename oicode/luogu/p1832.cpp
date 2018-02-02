#include <bits/stdc++.h>
using namespace std;
bool is(long long t)
{
	for (int i = floor(sqrt(t)); i >= 2; --i) if(t % i == 0) return false;
	return true;
}
vector<int> prim;
long long lst[1005];
int main() {
	int n;
	cin >> n;
	for (int i = 2; i <= n; ++i) {
		if(is(i)) prim.push_back(i);
	}
	lst[0] = 1;
	for (long long i = 0; i < prim.size(); ++i)
	{
		for (long long j = prim[i]; j <= n; ++j)
		{
			lst[j] += lst[j - prim[i]];
		}
	}
	cout << lst[n] << endl;
}
