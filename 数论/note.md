# 数论   

> krr数论全笔记   

[TOC]

## 基础知识   
- 整除   
- 素数判定   
- 线性筛   
- 互质   
- 约数   
- 调和级数   
- 余数   
  
### 唯一分解定理   
每个数，都可以唯一被分解成$p_1^{c_1}p_2^{c_2}...p_n^{c_n}$的形式，其中$p_i$是素数。   

### 互质   
$a$, $b$互质，即没有公共的质因子。即在唯一分解后，所有的$p_i$不相同。   

### 整除   
通常有两种写法...这份笔记中，所有的都依照后面一种。   
若$a \; mod \; b = 0$，则$a$能被$b$整除，或$b$能整除$a$，写作$a | b$   
若$b = ka$，记为$b$被$a$整除，$a$整除于$b$。写作$a | b$。   
绕一绕的话...$n = km$，读作$m$整除$n$，$n$被$m$整除，$m | n$，$|$的前后顺序依照$x$整除$y$的形式...绕一绕...过一会儿就绕好了~总之记住，小的放前面，大的放后面。   

### 素数判定   
若一个数$N$是合数，一定存在$T \leq \sqrt{n}$，且$T$能整除$N$。   
反证法，假设命题不成立，那么一定存在$T > \sqrt{n}$且$T | N$。那么一定存在$\frac{N}{T} \leq \sqrt{n}$且$\frac{N}{T} | N$。则命题成立~   
代码为试除法   
```cpp   
inline bool prime(ll val)   
{   
  for (int i = 2; i <= sqrt(val); ++i)   
    if(val % i == 0) return false;   
  return true;   
}   
```

### 线性筛   
普通筛法略过了，我们讲讲线性筛。   
线性筛$O(n)$的原理是，使每个数只被自己最小的质因子筛一次。   
都知道$a \in N$，$b$是质数，那么$a \cdot b$一定不是质数。   
我们令每个合数只被自己最小的质因子$p$筛出来，那么每个合数只会被筛一次。   
我们对于每一个数$a$，用$a$去乘上$\leq a$的所有质数。   
接下来给出，到每个数的时候，它一定被筛过的证明。   
这里是我万年理解不到的...别的教程也不提这个...so郁闷   
请把这一段认真看完...我尽量保证了语言没问题。   
我们的筛法是，标记某个小于其本身质数 $\times$ 某个小于其本身的合数。那么，假设，在进行那个“小于其本身的素数”的处理的时候，我们枚举了所有小于其本身的合数，而那时的$break$规则是$prm[j] * val > n$，这个数一定是$\leq n$的，所以其一定被筛过。这种反向思考很赞，但是别人为啥都不提这一点呢。但是啊，普通筛的时候，这么看吧！假如说当前的数可以被分解成$p_1^{c_1}...$，那么它会被所有的$p$筛一次，而某个数的素因子的个数是$\log{n}$级别的，那么复杂度$n\log{n}$。线性筛保证每个数一定只会被其最小的质因子筛过一次，根据上面的描述，已经足够了，所以线性筛的复杂度是$O(n)$。   
代码如下   
```cpp   
inline void prime()   
{   
  for (int i = 2; i <= n; ++i)   
  {   
    if(!vis[i]) prm[++cnt] = i;   
    for (int j = 1; j <= cnt; ++j)   
    {   
      if(i * prm[j] > n) break;   
      vis[i * prm[j]] = 1;   
      if(i % prm[j] == 0) break;   
    }   
  }   
}   
```
代码的顺序和刚才思维的顺序略有不同，而这正好是线性筛的妙处啊！   

尝试一下，并不好实现的思维题   

#### 「ep1」 质因数分解$N!$。   

这样看~   
利用线性筛的思路，我们每个合数只被其最小质因子筛一次。   
我们知道一个数的质因数分解形式后，用这个数乘上一个质数，能够知道计算结果的质因数分解形式。我们对结果的形式累乘，就是答案~不优化的话，时间复杂度和空间复杂度都是$O(n\log{n})$，实现也会很复杂。仅练习思维。   

#### 「ep2」 求$[L, R]$的质数个数。$L, R \leq 2^{31}, R - L \leq 10^{6}$。   

可以筛$R - L$的，那么我们先把$[2, \sqrt{R}]$之间的数筛出来，这里的数一定可以组合出$[L, R]$的所有数。然后对于所有质数，我们进行$[L, R]$的标记。$vis[i \times p] = 1, i \in [\frac{L}{p}, \frac{R}{p}]$。   

### 调和级数   
并不能给出详细的解答，总之记住公式，$\sum_{i = 1}^{n}{\frac{n}{i}} = n\ln{(n+1)} + nr$。$r$为欧拉常数，约等于$0.5772156649$，所以遇到形如$\sum_{i = 1}^{n}{\frac{n}{i}}$的算式，在时间复杂度中通常记作$n\log{n}$，或$n\ln{n}$。我习惯前者。调和级数通常用作时间复杂度的证明。   

### 约数   
下面介绍一点约数常用定理。   
定义$N$。   
约数的定义为$d | N$，d为约数。   
可以简单发现，$p_i$是$N$的约数，也就是说，$p_1^{c_1}p_2^{c_2}...p_n^{c_n}$的子集都是其一个约数。   
假设$N$进行唯一分解后的数是$p_1^{c_1}p_2^{c_2}...p_n^{c_n}$。   
$N$的正约数的个数 $=\prod_{i = 1}^{m}{(c_i + 1)}$。乘法原理   
$N$的正约数和为$\prod_{i = 1}^{m}{(\sum_{j = 0}^{c_i}{(p_i)}^j)}$。手玩~   
$N$的正整数约数集合是试除法，这里不再赘述...   
还有一个求法。   
对于数字$d$，$d$一定是$d \cdot k$的约数。这样筛下来，复杂度是$O(\sum_{i = 1}^{n}{\frac{n}{i}})$。利用调和级数，$O(n\log{n})$。比$O(n\sqrt{n})$要好得多。   

### 余数   
$a \; mod \; b = c$，称$c$是$a$除以$b$的余数。余数的定义式如下   $a \; mod \; b = a - \lfloor \frac{a}{b} \rfloor \cdot b$
看一个例题：$BZOJ1257$。   

#### 「ep3」求$\sum_{i = 1}^{n}{k \; mod \; i}$。   

转化题目，求$\sum_{i = 1}^{n}{(k - \lfloor \frac{k}{i} \rfloor \cdot i)} \Rightarrow k \times n -\sum_{i = 1}^{n}{(\lfloor \frac{k}{i} \rfloor \cdot i)}$。由于复杂度的问题，我们从$\frac{k}{i}$入手，因为会有一段区间，使得其不变。我们设$\lfloor\frac{k}{i}\rfloor = x$。这段区间的值是$\frac{(i_{first} + i_{end}) \times (end - first + 1)}{2} \times x$。所以问题来了，我们需要快速获取什么区间内，$\lfloor\frac{k}{i}\rfloor$不变。   
结论如下，我也不知道怎么推的。$i \in [x, \lfloor \frac{k}{\lfloor \frac{k}{x} \rfloor} \rfloor]$时，$\lfloor\frac{k}{i}\rfloor$不变。$x$是上一个的右端点 + 1，即这次的左端点，这是数论分块的经典写法。具体请见代码，lyd的代码如下：   

```cpp   
#define ll long long   
#define R register   
#include <bits/stdc++.h>   
   
using namespace std;   
   
ll n, k, ans;   
int main()   
{   
  scanf("%lld%lld", &n, &k);   
  ans = n * k;   
  for (int l = 1, r; l <= n; l = r + 1)   
  {   
    r = k / l ? min(k / (k / l), n) : n;   
    ans -= (k / l) * (l + r) * (r - l + 1) / 2;   
  }   
  printf("%lld", ans);   
}   
```
#### 「ep4」求$\sum_{i = 1}^{n}{\sum_{d | i}{d^2}} \; mod \; p$，$n \leq 10^{12}, p \leq 10^9$

首先，$\sum{i ^ 2} = \frac{n(n + 1)(2n + 1)}{6}$，是公式，至于怎么用，下面通过这道题来解释。   

首先注意到，枚举$i$是不现实的。$10^{12}$不可能。我们转换思维，枚举$d$。  

对于$d \leq n$，$d$的倍数的个数为$\lfloor \frac{n}{d} \rfloor$，每次的贡献是$\lfloor \frac{n}{d} \rfloor \cdot d^2$,对整体进行数论分块，对于$\sum_{i \in [L, R]}{i^2} = \frac{R(R + 1)(2R + 1)}{6} - \frac{(L - 1)(L)(2L - 1)}{6}$，我们对于$\lfloor \frac{n}{d} \rfloor$相同的整体进行计算，然后套数论分块模板~   

```cpp
// by kririae
#define ll long long
#include <bits/stdc++.h>

using namespace std;

ll n, mod, ans;

inline ll fast_pow(ll a, ll p)
{
  ll ans = 1; a %= mod;
  for (; p; p >>= 1)
  {
    if(p & 1) ans = (a * ans) % mod;
    a = (a * a) % mod;
  }
  return ans;
}

inline ll inv(ll a, ll p)
{
  return fast_pow(a, p - 2);
}

inline ll calc(ll val)
{
  static ll _inv = inv(6, mod); val %= mod;
  return (((((val * (val + 1)) % mod) * ((val << 1) + 1)) % mod) * _inv) % mod;
}

int main()
{
  scanf("%lld%lld", &n, &mod);
  for (ll l = 1, r; l <= n; l = r + 1)
  {
    r = (n / l) ? min(n / (n / l), n) : n;
    ans = (ans + (n / l) * ((calc(r) - calc(l - 1) + mod) % mod)) % mod;
  }
  printf("%lld", ans);
}
```

复杂度是$O(\sqrt{n})$。

简单总结下这道题过程中出现的问题...

- `calc(r) - calc(l - 1)`出现了负数。
- 逆元求太多次，忘了加`static`。
- 注意`mod`的问题。

> 逆元的问题我会在后面提到。

### 最大公约数和最小公倍数

定义：若存在$d$，$d | a$且$d | b$，$d$中最大的一个就是$gcd(a, b)$，$(a, b)$的最大公约数。若存在$m | a$且$m | b$。$m$取值最小的一个被称作$lcm(a, b)$，$(a, b)$的最小公倍数。

特别的，给出另一种$gcd$的理解方式。将$a, b$进行质因数分解，这俩重叠的部分就是$gcd(a, b)$。下面的证明将会用到。

最大公约数性质如下，$gcd(a, b) = gcd(b, a)$，$gcd(a, 0) = a$，$gcd(a, 1) = 1$, $gcd(ak, bk) = k \cdot gcd(a, b)$，$gcd(a + kb, b) = gcd(a, b)$，若$gcd(a, b) = 1$, $gcd(ab, k) = gcd(a, k) \cdot gcd(b, k)$。

给出最后一条的证明，这里会用到$gcd$的另一种理解方式~。证明：$k = \prod{k_i^{f_i}}$,$a = \prod a_i^{q_i}$,$b = \prod b_i^{s_i}$  ,则根据定义：$gcd(a, k) = \prod a_i^{min(q_i, f_i)}$  ，$gcd(b, k) = \prod b_i^{min(s_i, f_i)}$  ，又$a$, $b$互质，所以不存在$a_i = b_i$,则$ab = \prod a_i^{q_i} \cdot \prod b_i^{s_i}$，得出$从而$$gcd(ab, k) = \prod a_i^{min(q_i, f_i)} \cdot \prod b_i^{min(s_i, f_i)}  =gcd(a, k) \cdot gcd(b, k)$。$Q.E.D$

倒数第二条的证明我将在更相减损术处提到。

有定理，$gcd(a, b) \times lcm(a, b) = a \cdot b$。令$d = gcd(a, b)$，$x = \frac{a}{d}, y = \frac{b}{d}$。则$gcd(x, y) = 1, lcm(x, y) = x \cdot y$。则$lcm(x, y) \cdot d = \frac{a \cdot b}{d}$。