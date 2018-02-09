最简单的, 01背包
for i in all items
	for all_v -> 1
		f[i][v] = max(f[i - 1][v - c_i] + w_i, f[i][v])
完全背包问题
for i in all items
	for 1 -> all_v
		f[i][v] = max(f[i - 1][v - c_i] + w_i, f[i][v])
用换推倒顺序来优化，而不换状态
01背包还有一种状态表示方式
f[i][v][0/1]
f[i][v][0] -> f[i + 1][v + c_i][1] + w_i
f[i][v][0] -> f[i][v][0]
f[i][v][1] -> f[i][v][1];

多重背包问题的方程
$$
F[i][v] = \mathrm{max}\lgroup f[i - 1][v - K_i\ times C_i] + W_i \times K_i, F[i][v] | K_i \in (1, M_i)\rgroup
$$

第二种蛇皮解法,时间复杂度$$ O(V\sum M_i) $$
之前证明过，任意一个数转化为二进制是这样的
$$ \sum_{k=0}^n c_i\times2^i $$
说明白点，就是$$ 1,2,2^2...2^{k - 1},M_i-2^k+1 $$
也就是将一个物品划分为了多个物品