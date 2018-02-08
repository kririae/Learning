#include <bits/stdc++.h>
using namespace std;

template<typename T>
inline void read(T &val) {
	val = 0; int f = 1;
	char ch = getchar();
	while(!isdigit(ch)) {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(isdigit(ch)) {
		val = val * 10 + ch - '0';
		ch = getchar();
	}
	val *= f;
}

const int maxn = 1000005;
const int mod = 1000000007;
int n, m;
int a[maxn], b[maxn], c[maxn];
int p, q, x;

inline long long bf(int p, int q, int x) 
{
	if(c[p] < q) return (a[p] * x) + b[p];
	else return (a[p] * bf(c[p], q, x) + b[p]) % mod;
}
/*
...100多点足够了...
可能有种思路，并查集不压缩维护序列
设置c[p]为并查集father[p]
先把询问排序一次
离散化一发 
走过的路程直接保存一发，然后复用！ 
x怎么处理啊......................
可以使用函数式编程的思想。。在走过的每一个点建立一个函数
并且建立可以跳到下一个点的位置... (脑洞太大了 
*/ 
int main() {
	freopen("function.in", "r", stdin);
	freopen("function.out", "w", stdout);
	read(n); read(m);
	for (int i = 1; i <= n; ++i) {
		read(a[i]); read(b[i]); read(c[i]);
	}
	int ans = 0;
	for (int i = 1; i <= m; ++i) {
		read(p); read(q); read(x);
		int res = bf(p, q, x);
		ans = ans ^ res % mod;
	}
	cout << ans << endl;
}
