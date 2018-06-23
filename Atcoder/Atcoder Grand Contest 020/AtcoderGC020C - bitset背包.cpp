#define R register
#include <bits/stdc++.h>
 
using namespace std;
 
const int maxn = 2e6 + 5;
 
int n, val, sum;
bitset<maxn> f;
 
int main()
{
	scanf("%d", &n);
	f[0] = 1;
	for (R int i = 1; i <= n; ++i) scanf("%d", &val), f |= (f << val), sum += val;
	if(n == 1) return printf("%d", sum), 0;
	for (R int i = (sum >> 1); i; --i) if(f[i]) return printf("%d", sum - i), 0;
}