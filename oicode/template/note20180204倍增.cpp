快速RMQ问题
需要O(n), O(1)
BIT的区间加法
ST表

用并查集来做 时间复杂度O(n\alpha(n))
一个数列对应一个数组
到这个右端点的最大值
Q1假如说询问某一个区间 [2, 4]
先拿自己更新一次答案 然后再把father更新到2, 3, 4的答案
第一次询问的复杂度是O(n)
Q2那一段已经存储过了 [1, 4] 直接把father放在最右边
所以复杂度是O(1)
这是一个很精彩的信息复用的方法
极其精彩...

二进制分组来提取信息
int father[maxn];
for (int i = 0; i <= maxn; ++i) father[i] = i;
int minn[maxn];
int c[maxn];
// 路径压缩过程中求最小值
inline int find(int val) {
	if(val != father[val]) {
		father[val] = find(father[val]);
		// 这是真的不好实现啊qwq...
		minn[father[val]] = minn(minn[c[val]], minn[father[val]]);
	}
	else return father[val];
}
inline void unionn(int a, int b) {
	father[find(a)] = find(b); // union a, b
}
inline int query(int l, int r) {
	for (int i = l; i <= r; i = (i == find(i) ? i + 1 : find(i))) {

	}
}