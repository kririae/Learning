int a[maxn];
inline void subset(int n) {
	for (int i = 0; i < (1 << n); ++i) 
		for (int j = 0; j < n; ++j) if(!i & (1 << j)) cout << a[j] << " ";
}
