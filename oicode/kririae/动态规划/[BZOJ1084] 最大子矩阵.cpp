#include <bits/stdc++.h>

using namespace std;

namespace SCOI2005
{
/*
小黄鸭debug mode on
首先从题目上的数据范围来看，应该是一个三维状态
按照矩阵题的套路来看，三维状态一定是$f[i][j][k]$表示
选择到了坐标$(i, j)$，选择了$k$个矩形，值的最大值。
我的习惯是顺推，那么转移有三个：
向下拓长一行，向右拓宽一行；
这两者又分别有两个决策，重新开一个新的矩形和利用当前的矩形
 */
inline void solve()
{

}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	SCOI2005::solve();
	return 0;
}