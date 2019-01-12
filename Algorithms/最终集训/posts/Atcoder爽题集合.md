title: 「学习笔记」Atcoder爽题集合
author: kririae
date: 2018-06-23 07:29:49
tags:
---
# Atcoder爽题集合

口胡和完整代码参见[代码仓库](https://github.com/kririae/OI/tree/master/Atcoder)

## AtcoderGC019B
对于字符串$S$，每次可以选取$1 \leq i \leq j \leq n$的一个串使其倒过来，每次只能进行一次操作，求最终能够获得的字符串个数
```cpp
scanf("%s", s + 1);
ll len = strlen(s + 1), ans = 1ll * len * (len + 1) / 2;
for (R int i = 1; i <= len; ++i) ++cnt[s[i] - 'a'];
for (R int i = 0; i <= 'z' - 'a'; ++i)
	ans -= (1ll * cnt[i] * (cnt[i] - 1) / 2);
printf("%lld", ans - len + 1);
```

## AtcoderGC024B
对于$[1 .. n]$的排列$A$, 每次可以选择一个数放到开头, 最后使得数列有序, 求最少操作次数. 简单dp
```cpp
scanf("%d", &n);
for (R int i = 1; i <= n; ++i) scanf("%d", &a[i]);
for (R int i = 1; i <= n; ++i)
  f[a[i]] = f[a[i] - 1] + 1, ans = max(ans, f[a[i]]);
printf("%d", n - ans);
```

## AtcoderGC022C
对于数列$A$, $B$, 每一次可以选择$A$中任意多个数, 然后选择一个数$k$, 使得每个选择的数$a_i$ 变成$a_i \; mod \; k$.然后代价是$2^k$, 最后使得$A$和$B$相同, 求代价最小值. 贪心 + 状压dp
```cpp
scanf("%d", &n);
for (int j = 0; j <= 50; ++j)
{
  f[j] = 0, f[j] |= (1ll << j);
  for (int k = 1; k <= j; ++k)
    if(((1ll << 51) - 1) & (1ll << k)) f[j] |= f[j % k];
}
for (R int i = 1; i <= n; ++i) scanf("%d", &a[i]);
for (R int i = 1; i <= n; ++i) scanf("%d", &b[i]);
int flag = 1;
for (R int j = 1; j <= n; ++j)
  if((f[a[j]] & (1ll << b[j])) == 0) flag = 0;
if(flag == 0) return printf("%lld\n", -1ll), void();
for (int i = 50; i; --i)
{
  for (int j = 0; j <= 50; ++j)
  {
    f[j] = 0, f[j] |= (1ll << j);
    for (int k = 1; k <= j; ++k)
      if((ans + (1ll << i) - 1) & (1ll << k)) f[j] |= f[j % k];
  }
  int flag = 1;
  for (R int j = 1; j <= n; ++j)
    if((f[a[j]] & (1ll << b[j])) == 0) flag = 0;
  if(!flag) ans += (1ll << i);
}
printf("%lld\n", ans);
```

## AtcoderGC024C
对于初始为0的数列$A$, 每次可以选择一个$a_i$变成$a_{i - 1} + 1$.最后使得$A$变成$B$, 求最少操作次数.  蜜汁性质
```cpp
scanf("%d", &n);
for (R int i = 1; i <= n; ++i) scanf("%d", &a[i]);
for (R int i = 1; i <= n; ++i)
  if(a[i] >= i) return puts("-1"), 0;
for (R int i = 2; i <= n; ++i)
{
  if(a[i] - a[i - 1] > 1) return puts("-1"), 0;
  if(a[i] == a[i - 1] + 1) ++ans;
  else ans += a[i];
}
printf("%d\n", ans);
```

## AtcoderGC020C
对于数列$A$的所有子集之和, 进行排序, 然后求出排序后的中位数
这道题值得提一提 **补集思想很重要**
```cpp
scanf("%d", &n);
f[0] = 1;
for (R int i = 1; i <= n; ++i) scanf("%d", &val), f |= (f << val), sum += val;
if(n == 1) return printf("%d", sum), 0;
for (R int i = (sum >> 1); i; --i) if(f[i]) return printf("%d", sum - i), 0;
```