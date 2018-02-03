// by Qizy

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
// len是33以内的质数的长度
int a[205], len, test, n, f[2055], g[2055], v[2055][2], c[101];
// test无意义，测试用的
// f是
// b是素数表的表
bool b[101];
vector<int> r[1001];
 
int main() {
	// freopen("prime19.in", "r", stdin);
	// freopen("prime19.out", "w", stdout);
	memset(b, false, sizeof(b));
	len = 0;
	// 素数筛，利用所有某个数的倍数全都不是素数来筛选全部素数qwq 
	for (int i = 2; i <= 33; i++) {
		if (!b[i]) c[++len] = i;
		for (int j = i + i; j <= 33; j += i)
			b[j] = true;
	}
	test = 1;
	int w = 1 << len;
	for (; test--; ) {
		scanf("%d", &n);
		for (int i = 1; i <= 1000; i++) r[i].clear(); // 清空原来的状态... 
		memset(f, 0, sizeof(f));
		for (int i = 1; i <= n; i++) {
			int x;
			scanf("%d", &x);
			// 读取一个新的数，背包问题模板 
			int mask = 0;
			for (int j = 1; j <= len; j++) 
				if (!(x % c[j])) {
					for (; !(x % c[j]); x /= c[j]);
					mask |= 1 << (j - 1);
				}
			// mask是压缩所有的状态，表示"某一个数的质因数是哪些"，用二进制在c中的对应表示 
			if (x > 33) r[x].push_back(mask);
			// 如果这个数大于33，那就直接放到对应的位置去
			// w和枚举子集的1 << n基本是一样的qwq 
			// 如果小于等于33， i & mask??? 
			// 既然mask是表示当前数字的质因数状态，i就是表示全部存在的质因数状态
			else for (int i = 0; i < w; i++)
					if (!(i & mask)) { // 懂了，因为如果有任意一个质因数重合的话，那就不满足题中条件了
						f[i | mask] = max(f[i | mask], f[i] + 1);
					}
		}
		 
		for (int i = 1; i <= 1000; i++) {
			int len = r[i].size();
			if (!len) continue;
			for (int j = 0; j < w; j++) g[j] = f[j]; // 复制一份f
			for (int k = 0; k < w; k++) /// 对比f大的进行转移
				for (int j = 0; j < len; j++) 
					if (!(k & r[i][j])) g[k | r[i][j]] = max(g[k | r[i][j]], f[k] + 1); // 和前面的意义相同
			memcpy(f, g, sizeof(f));
		}
		int vout = 0;
		for (int i = 0; i < k; ++i) {
			vout = max(vout, f[i]);
		}
		printf("%d\n", vout);
	}
}
	
