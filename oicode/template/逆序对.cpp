// ------------------------------------
const int maxn = 1e4 + 5;
int cnt = 0;
int a[maxn], b[maxn];

inline void merge(int l, int mid, int r) {
    int i = l, j = mid + 1; // 合并两个有序序列a[l..mid] a[mid + 1..r]
    for (int k = l; k <= r; ++k) { // 从左走都右
        if (j > r || i <= mid && a[i] < a[j]) b[k] = a[i++];
        else b[k] = a[j++], cnt += mid - i + 1;
    }
    for (int k = 1; k <= r; ++k) {
        a[k] = b[k];
    }
}
// 最后merge地总和就是逆序对的个数
// 完整代码如下
#pragma GCC optimize(2)
#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5;
int n;
int cnt = 0;
int a[maxn], tpr[maxn];
long long t = 0;

inline void merge_sort(int l, int r) {
    if (l == r) return;
    int mid = (l + r) >> 1;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    int i = l, j = mid + 1;
    for (int k = l; k <= r; ++k) {
        if (j > r || (i <= mid && a[i] <= a[j])) tpr[k] = a[i++];
        else tpr[k] = a[j++], cnt += mid - i + 1;
    }
    memcpy(a, tpr, sizeof(tpr));
    memset(b, 0, sizeof(tpr));
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false); // 不加读入优化了qwq没必要
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    merge_sort(1, n);
    cout << cnt << endl;
}
// ------------------------------------
// 树状数组实现逆序对
/*
 * 对于任意集合a，假如说用t[val]来表示数值a在a中出现的次数
 */
// luogu1393
#include <bits/stdc++.h>

using std::cout;
using std::cin;
using std::endl;
using std::pair;

namespace solve {
template<typename T>
auto min = [](T a, T b) { return a < b ? a : b; };

template<typename T>
auto max = [](T a, T b) { return a < b ? b : a; };

inline char read() {
    static const int IN_LEN = 1000000;
    static char buf[IN_LEN], *s, *t;
    s == t ? t = (s = buf) + fread(buf, 1, IN_LEN, stdin) : 0;
    return s == t ? -1 : *s++;
}

template<typename T>
inline void read(T &x) {
    static char c;
    static bool iosig;
    for (c = read(), iosig = false; !isdigit(c); c = read()) {
        if (c == -1) return;
        c == '-' ? iosig = true : 0;
    }
    for (x = 0; isdigit(c); c = read()) x = (x + (x << 2) << 1) + (c ^ '0');
    iosig ? x = -x : 0;
}

const int maxn = 40005;
const int inf = ~(1 << 31);
int n, m;
pair<int, int> a[maxn]; // val, posi
int cnt = 0; // 算了这个省选题就明天来...
int c[maxn], dct[maxn];
/*
 * 思路如下
 * 正常加入，但是既然要统计数据
 * 那么，有一个思路，每一位的和为i，然后统计前缀和就好了嘛qwq
 * 倒着走，然后输出
 * 祈祷一发明天不会考试
 * dct: 离散化数组
 * i:  1 2 3 4 5 -> v
 * v:  8 5 8 1 2 
 * 排序后
 * i:  4 5 2 1 3 
 * v:  1 2 5 8 8
 * dct:4 3 5 1 2 -> i
 * 离散化i
 */
auto lowbit = [](int t) -> int { return t & -t; };
auto insert = [](int t, int val) { for(int i = t; i <= n; i += lowbit(i)) c[i] += val; };
auto getsum = [](int t) -> long long { 
    long long res = 0; 
    for (int i = t; i >= 0; i -= lowbit(i)) 
        res += c[i]; 
    return res;
}
auto erase = [](int t)
inline void init() {
    read(n);
    read(m);
    for (int i = 1; i <= n; ++i) read(a[i].first), a[i].second = i;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) dct[a[i].second] = i;
}

inline void solve() {
    long long ans = 0;
    for (int i = 1; i <= n; ++i) insert(dct[i], 1), ans += i - getsum(dct[i]);
    cout << ans << endl;
}   
}

int main() {
    solve::solve();
    return 0;
}
