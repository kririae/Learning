/*
 * 题目解析
 * 之前学长说过了，状态的压缩是要忽略具体情况的
 * 这里这样设计状态
 * f[i][j] 选了i个数，此时的逆序对的个数时j，满足条件的最多排列个数是
 * 那么，转移的时候就要考虑“逆序对这个信息”，我们发现我们并没有把它放在方程中
 * 啊啊啊上面的全部划掉qwq
 * 这样来看，我们现在转移到了i, 是一个长度为j的串，此时满足条件的排列最多为 f[i][j]个
 * TODO!!!
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = (100 * 99 / 2);
int n, k;
int f[105][maxn];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k;

}