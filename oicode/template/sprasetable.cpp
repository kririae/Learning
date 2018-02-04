int a[maxn];
int f[maxn][20];
inline void st_init() {
	for (int i = 1; i <= n; ++i) f[i][0] = a[i];
	int t = log(n) / log(2) + 1;
	for (int j = 1; j < t; ++j) 
		for (int i = 1; i <= (n - (1 << j) +1); ++i) 
			f[i][j] = max(f[i][j - 1], f[i + (1 << (j - i))][j - 1]);
}

int n;
int logm = log(n) / log(2) + 1;
const int maxn = 1e5;
int a[maxn];
int f[maxn][logm];
inline void st_init() {
	for (int i = 1; i <= n; ++i) f[i][0] = a[i];
	for (int j = 1; j < logm; ++j) {
		for (int i = 1; i <= ())
	}
}