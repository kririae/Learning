#include <iostream>
#include <deque>
#include <cstdio>
using namespace std;

/*
关于单调队列
由于我实在太菜了，就从滑动窗口开始吧
首先啊，单调队列和单调栈貌似差距不是一点半点，用处也完全不同
但是，她俩有一共同特点，及时排除不必要的状态。
首先，我们考虑滑动窗口重复计算的过程。
既然是计算$k$个数之内的最大值和最小值。
我们已经计算到$[l, r]$，再计算$[l + 1, r + 1]$的时候，是不是重复计算了很多？
我们考虑哪些状态可以被排除的。
考虑一个队列，这个队列里放着可能影响最大值和最小值的数。
考虑向队列末加入一个数，那么，这个队列中所有距离和这个数超过$k$的数就需要被排除了。假如说我们加入的是10，而队列中有个6。我们知道，$6$一定是在$10$之前被加入的，而，对于长度不变的为$k$的区间，“10的存活的机会一定比6的高”。对于后面某一次加入某个数，一旦这个区间覆盖了$10$，这个区间的最大值一定不会是$6$。而对于某个区间的端点是$6$，这个后面的区间也一定覆盖了$10$。换句话说，$6$至死都不会被再用了。是不是好惨。维护最小值同理。
 */
const int N = 1e6 + 5;
deque<int> d1, d2;
int n, k, a[N], ans1[N], ans2[N];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1, x; i <= n; ++i) {
    scanf("%d", &x);
    a[i] = x;
    while (d1.size() >= 1 && i - d1.front() + 1 > k) d1.pop_front();
    while (d1.size() >= 1 && a[d1.back()] <= a[i]) d1.pop_back();
    d1.push_back(i);
    while (d2.size() >= 1 && i - d2.front() + 1 > k) d2.pop_front();
    while (d2.size() >= 1 && a[d2.back()] >= a[i]) d2.pop_back();
    d2.push_back(i);
    ans1[i] = a[d1.front()];
    ans2[i] = a[d2.front()];
  }
  for (int i = k; i <= n; ++i)
    printf("%d ", ans2[i]);
  puts("");
  for (int i = k; i <= n; ++i)
    printf("%d ", ans1[i]);
}