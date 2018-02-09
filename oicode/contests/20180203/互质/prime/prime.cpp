#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int a[101], len, test, n, f[2055], g[2055], v[2055][2], c[101];
bool b[101];
vector<int> r[1001];
 
int main() {
	// freopen("prime19.in", "r", stdin);
	// freopen("prime19.out", "w", stdout);
	memset(b, false, sizeof(b));
	len = 0;
	for (int i = 2; i <= 33; i++) {
		if (!b[i]) c[++len] = i;
		for (int j = i + i; j <= 33; j += i)
			b[j] = true;
	}
	test = 1;
	int w = 1 << len;
	for (; test--; ) {
		scanf("%d", &n);
		for (int i = 1; i <= 1000; i++) r[i].clear();
		memset(f, 0, sizeof(f));
		for (int i = 1; i <= n; i++) {
			int x;
			scanf("%d", &x);
			int mask = 0;
			for (int j = 1; j <= len; j++)
				if (!(x % c[j])) {
					for (; !(x % c[j]); x /= c[j]);
					mask |= 1 << (j - 1);
				}
			if (x > 33) r[x].push_back(mask);
			else for (int i = 0; i < w; i++)
					if (!(i & mask)) {
						f[i + mask] = max(f[i + mask], f[i] + 1);
					}
		}
		 
		for (int i = 1; i <= 1000; i++) {
			int len = r[i].size();
			if (!len) continue;
			for (int j = 0; j < w; j++) g[j] = f[j]; 
			for (int k = 0; k < w; k++)
				for (int j = 0; j < len; j++) 
					if (!(k & r[i][j])) g[k | r[i][j]] = max(g[k | r[i][j]], f[k] + 1);
			memcpy(f, g, sizeof(f));
		}
		printf("%d\n", f[w - 1]);
	}
}
	
