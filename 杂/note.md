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
- 最大公约数和最小公倍数
- 欧拉函数
  
### 唯一分解定理   
每个数，都可以唯一被分解成$p_1^{c_1}p_2^{c_2}...p_n^{c_n}$的形式，其中$p_i$是素数。   

### 互质   
$a$, $b$互质，即没有公共的质因子。即在唯一分解后，所有的$p_i$不相同。   

### 整除   
通常有两种写法...这份笔记中，所有的都依照后面一种。   

- 若$a \; mod \; b = 0$，则$a$能被$b$整除，或$b$能整除$a$，写作$a | b$
- 若$b = ka$，记为$b$被$a$整除，$a$整除于$b$。写作$a | b$。

绕一绕的话...$n = km$，读作$m$整除$n$，$n$被$m$整除，$m | n$，$|$的前后顺序依照$x$整除$y$的形式...绕一绕...过一会儿就绕好了~总之记住，小的放前面，大的放后面。   

整除的性质是一切证明的关键，这里给出：

- $a | b, a | c$，则有$a | (b \pm c)$。

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

都知道$a \in N$，$b$是质数，那么$a \cdot b$一定不是质数。我们令每个合数只被自己最小的质因子$p$筛出来，那么每个合数只会被筛一次.我们对于每一个数$a$，用$a$去乘上$\leq a$的所有质数。接下来给出，到每个数的时候，它一定被筛过的证明。   

这里是我万年理解不到的...别的教程也不提这个...so郁闷,请把这一段认真看完...我尽量保证了语言没问题。   

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

- $N$的正约数的个数 $=\prod_{i = 1}^{m}{(c_i + 1)}$。乘法原理   
- $N$的正约数和为$\prod_{i = 1}^{m}{(\sum_{j = 0}^{c_i}{(p_i)}^j)}$。手玩~   
- $N$的正整数约数集合是试除法，这里不再赘述...   
还有一个求法。   
- 对于数字$d$，$d$一定是$d \cdot k$的约数。这样筛下来，复杂度是$O(\sum_{i = 1}^{n}{\frac{n}{i}})$。利用调和级数，$O(n\log{n})$。比$O(n\sqrt{n})$要好得多。   

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

定义：若存在$d$，$d | a$且$d | b$，$d$中最大的一个就是$gcd(a, b)$，$(a, b)$的最大公约数。若存在$a | m$且$b | m$。$m$取值最小的一个被称作$lcm(a, b)$，$(a, b)$的最小公倍数。

特别的，给出另一种$gcd$的理解方式。将$a, b$进行质因数分解，这俩重叠的部分就是$gcd(a, b)$。下面的证明将会用到。这种理解方式会被用到大量的证明中去。

最大公约数性质如下，$gcd(a, b) = gcd(b, a)$，$gcd(a, 0) = a$，$gcd(a, 1) = 1$, $gcd(ak, bk) = k \cdot gcd(a, b)$，$gcd(a + kb, b) = gcd(a, b)$，若$gcd(a, b) = 1$, $gcd(ab, k) = gcd(a, k) \cdot gcd(b, k)$。

给出最后一条的证明，这里会用到$gcd$的另一种理解方式~。

证明：$k = \prod{k_i^{f_i}}$,$a = \prod a_i^{q_i}$,$b = \prod b_i^{s_i}$  ,则根据定义：$gcd(a, k) = \prod a_i^{min(q_i, f_i)}$  ，$gcd(b, k) = \prod b_i^{min(s_i, f_i)}$  ，又$a$, $b$互质，所以不存在$a_i = b_i$,则$ab = \prod a_i^{q_i} \cdot \prod b_i^{s_i}$，得出$从而$$gcd(ab, k) = \prod a_i^{min(q_i, f_i)} \cdot \prod b_i^{min(s_i, f_i)}  =gcd(a, k) \cdot gcd(b, k)$。$Q.E.D$

倒数第二条的证明我将在更相减损术处提到。

有定理，$gcd(a, b) \times lcm(a, b) = a \cdot b$。令$d = gcd(a, b)$，$x = \frac{a}{d}, y = \frac{b}{d}$。则$gcd(x, y) = 1, lcm(x, y) = x \cdot y$。则$lcm(x, y) \cdot d = \frac{a \cdot b}{d}$。

更相损减术，定理如下，$gcd(a, b) = gcd(b, a - b) = gcd(a, a - b)$。欧几里得算法，$gcd(a, b) = gcd(b, a \; mod \; b)$。由于更相损减术是欧几里得算法的特例，这里给出欧几里得算法的证明。若$a < b$，易得$gcd(a, b) = gcd(b, a)$。若$a \geq b$，不妨设$gcd(b, a \; mod \; b) = gcd(a - nb, b)$，$n$为任意整数。设$a = nb + k$，根据定义，有$k = a \; mod \; b$。对于公约数$d$，有$d | a$，$d | nb$。则$d | (a - nb)$。$d | k$，所以$d | b, d | a \; mod \; b$.，公约数集合相同，所以最大公约数相同。备注一句，因为$d$对于所有公约数都成立，所以说公约数集合成立，这是证明中的常见手段。

代码如下：

```cpp
int gcd(int a, int b)
{
  return b ? gcd(b, a % b) : a;
}
```

#### 「ep5」给出$a_0, b_0, a_1, b_1$，求满足$gcd(x, a_0) = a_1, lcm(x, b_0) = b_1$的$x$的个数，$a, b \leq 10^9 $

朴素算法如下，我们知道，$x | b_1, b0 | b1$，$a_1 | x, a0 | a_1$,某个数的约数个数大约$2 \sqrt{n}$，我们枚举$b_1$的约数$x$，然后$check$是否满足$gcd(x, a_0) = a_1, lcm(x, b_0) = b_1$。具体来说，我们用搜索算法组合出$b_1$所有的约数，然后判断条件是否满足，可过，代码懒得给了qwq颓颓颓

机智的算法先咕咕咕着...

###  欧拉函数

之前提到过，对于$gcd(a, b) = 1$的情况，我们称$a, b$互质，互质的另一种解释方法是：$a = \prod{a_i^{q_i}}$，$b = \prod{b_i^{e_i}}$，所有的$a_i != b_i$。也就是$\{a\} \cap \{b\} = \emptyset$。对于三个及更多，互质称作“两两互质”，即所有的数没有公共质因子。

欧拉函数，定义为$[1, n]$中和$n$互质的数的个数，记作$\varphi(n)$。

$\varphi(n)$有以下公式：
$$
\varphi(n) = n \cdot \prod_{(prime\;p) | n}{(1 - \frac{1}{p})}
$$
证明：

设$p$为$n$的质因子，则$p | n$，而$kp \leq n$的所有$kp$都不与$n$互质。而$kp$有$\lfloor \frac{n}{p} \rfloor$个，而$q$为$n$质因子，$kq$有$\lfloor \frac{n}{q} \rfloor$个，而$pq$的倍数又被重复计算，所以$n$中含有$\lfloor \frac{n}{pq}\rfloor$个重复计算的，需要剔除。$[1, n]$中不含$p, q$为质因子的数的个数是$n - \frac{n}{p} - \frac{n}{q} + \frac{n}{pq} = n(1 - \frac{1}{p})(1 - \frac{1}{q})$。同理可得。代码如下：注意精度问题，需要特殊处理。

```cpp
inline int phi(int n)
{
  int ans = n;
  for (int i = 2; i <= sqrt(n); ++i)
    if(n % i == 0)
    {
      ans = (ans - ans / i);
      while(n % i == 0) n /= i;
    }
  if(n > 1) ans = ans - ans / n;
  return ans;
}
```

$\varphi$函数的性质有： 

- $[1, n]$的数中和$n$互质的数的和是$\frac{n \cdot \varphi(n)}{2}$。就是$gcd(a, n) = 1$，$a$的和。由九章算术，$gcd(n, a) = gcd(n, n - a)$。所以我们要求出$(n, n - a)$的平均数，手玩可得，平均数为$\frac{n}{2}$。
- 若$a, b$互质，则$\varphi(ab) = \varphi(a) \cdot \varphi(b)$。这是积性函数的性质，积性函数我将会在后面进行讨论。设$a = \prod{a_i^{c_i}}$,$b = \prod{b_i^{d_i}}$。则$\varphi(a) = a \cdot  \prod_{i \in \{a_i\}}{(1 - \frac{1}{i})}$，$\varphi(b) = b \cdot  \prod_{i \in \{b_i\}}{(1 - \frac{1}{i})}$。又$\{a_i\} \cap \{b_i\} = \emptyset$，则$\varphi(a) \cdot \varphi(b) = ab \cdot \prod_{i \in \{a_i\}}{(1 - \frac{1}{i})} \cdot \prod_{i \in \{b_i\}}{(1 - \frac{1}{i})}$，且$\varphi(ab) = ab \cdot \prod_{i \in (\{a_i\} \cup \{b_i\})}{(1 - \frac{1}{i})}$，得证。写公式好累。通过这个性质，可以$O(n)$预处理$\varphi$值。这个先不忙。
- $n$为质数时，$\varphi(n) = n - 1$。这个没必要解释吧QwQ
- $\sum_{d | n}{\varphi(d)} = n$。这条的证明已经折磨了我一个小时了...可以用狄利克雷卷积来证明。有一个初等证明，但还是不简单。对逻辑要求极高。
证明：
首先，对于分母为$b$，分子为$a$，$a < b$的既约分数，假如说固定$b$的取值，那么$a$的取值有$\varphi(b)$种。关于这道题，我们考虑所有的$\frac{i}{n}, i \in [1, n]$，将其约分，对于约分后的分数$\frac{a}{b}$，一定有$gcd(a, b) = 1, b | n, a | i$且$a < b$。假定一个$d | n$，那么在之前的分数集合中，以$d$为分母的既约分数个数就有$\varphi(d)$个。而$|$分数集合$| = n$，所以$\sum_{d | n}{\varphi(d) = n}$
$Q.E.D.$
举个例子来演示一下吧
对于$6$，我们构造出了$\frac{1}{6}, \frac{1}{3}, \frac{1}{2}, \frac{2}{3},\frac{5}{6}, \frac{1}{1}$。这其中，以$1 | 6$为分母的有$\varphi(1)$个，也就是$\frac{1}{1}$。以$2 | 6$为分母的有$\varphi(2)$个，也就是$\frac{1}{2}$。以此类推，我们可以发现，分母$d$的取值只有$d | n$，而$\varphi(i)$的和正是前面分数集合的大小。
真是妙极了
- $n = \prod{p_i^{c_i}}$，则$f(n) = \prod{f(p_i^{c_i})}$。首先，易得，$gcd(p_i^{c_i}, p_j^{c_j}) = 1$，满足积性函数，则易证。
- 若$p | n$，则有$\varphi(p \cdot n) = \varphi(n) \cdot p$
- 反之，$\varphi(p \cdot n) = \varphi(n) \cdot (p - 1)$。
因为$p$是质数，且$p \nmid n$(?)，所以$gcd(p, n) = 1$。有$\varphi(p) = p - 1$，由积性函数性质可证明。对于$p | n$，带入定义式，$\varphi(n) = n \cdot \prod_{(prime\;p) | n}{(1 - \frac{1}{p})}$，因为$p | n$，所以直接在前面的$n \cdot p$，得证。（好方法啊

#### 欧拉函数拓展

##### $O(n)$递推

证明参见刚才的最后俩条

```cpp
inline void phi(int n)
{
	for (int i = 2; i <= n; ++i)
	{
		if(!vis[i]) prm[++cnt] = i;
		for (int j = 1; j <= cnt; ++j)
		{
			if(i * prm[j] > n) break;
			vis[i * prm[j]] = 1;
			if(i % prm[j] == 0)
			{
				phi[i * prm[j]] = phi[i] * prm[j];
				break;
			} else phi[i * prm[j]] = phi[i] * (prm[j] - 1);
		}
	}
}
```

##### 狄利克雷卷积和莫比乌斯反演初步  

$Dirichlet$定义如下：$qwq(n) = \sum_{d | n}{f(n)g(\frac{n}{d})}$ 。简化记为$qwq(n) = f(n) * g(n)$。我只会这点（逃

### 同余

同余的定义如下，$a \; mod \; m = b \; mod \; m$，则称$a, b$同余，写作$a \equiv b \; (mod \; m)$ ，`a \equiv v \ (mod \ m)`.

对于$i \in [0, m - 1], \{a + km\}$，$i \; mod \; m = a$。这是$\; mod \; m$下的**同余类**。模数$x$的同余类有$x - 1$个，构成**完全剩余系**。

$[1, m]$中$gcd(i, m)$，$i$组成的集合叫做简化剩余系$S$。设$a \in S, b \in S$，由欧几里得算法可得$gcd(a \cdot b, m) = 1 \Rightarrow gcd(a \cdot b \; mod \; m, m) = 1$。则$a \cdot b \ mod \ m \in S$。

### 欧拉定理

欧拉定理的定义如下：如果$gcd(a, n) = 1$，则$a^{\varphi(n)} \equiv 1 \ (mod \ n)$。我并不会证明。欧拉定理可以推导出费马小定理。费马小定理如下：若$p$是质数，则$a^p \equiv a \ (mod \ p)$。我也不会证。

欧拉定理有重要推论，$a^b \equiv a^{b \ mod \ \varphi(n)} \ (mod \ n)$。若$a, n$互质。

#### 关于欧拉定理的本质

这里又要提到一个别人不常提到的东西了。这样测试：$a^{i} \ mod \ p$。循环节的长度一定是$\varphi(p)$。但不一定是最小的。$5^i \ mod \ 13$的循环节是$5 \ 12 \ 8 \ 1$，长度为$4$，$\varphi(13) = 12$。$4 |12$。然后，之后会在拓欧降幂处提到。

#### 「ep6」求$a^{b^{b^{b...}}} \ mod \ (10^{9} + 7)$，$b$有$n$个。$a, b \leq 10^{16}$。

首先需要知道，后面挂着的那一坨该怎么处理。我们看$b^b$的本质是什么？$b^b = \underbrace{b \times b \times \cdot\cdot\cdot \times b}_{b}$。转化为$a^{a^{b - 1}} \ mod \ (10^9 + 7)$。根据费马小定理$a^{p - 1} \equiv 1 \ (mod \ p)$。所以$a^{a^{b - 1}} \equiv a^{(a^{b - 1}) \ mod \ (p - 1)} \ (mod \ p)$。不懂这一步的话可以考虑$1$哪去了。然后用快速幂解决。

### 拓(扩)展欧几里得算法

拓欧的定理如下$ax + by = gcd(a, b)$。而我们就是要解这个不定方程。

问题来了，如何解?根据欧几里得算法，有$ax + by = bx' + (a \ mod \ b)y' = gcd(a, b) = gcd(b, a \ mod \ b)$。而根据之前提到过的模数的定义，$a \ mod \ b = a - \lfloor \frac{a}{b} \rfloor \cdot b$，得出$ax + by = bx' + (a - \lfloor \frac{a}{b} \rfloor \cdot b)y'$。化简得到$ax + by = ay' -  b \cdot (x' - \lfloor \frac{a}{b} \rfloor \cdot y')$。我们令$x = y', y = x' - \lfloor \frac{a}{b} \rfloor \cdot y'$。当$b = 0$时，$x = 1, y = 0$。因为$ax = gcd(a, 0) = 1$。

代码如下

```cpp
inline void exgcd(int &x, int &y, int a, int b)
{
  if(b == 0) return x = 1, y = 0, void();
  else return exgcd(y, x, b, a % b), y -= (a / b) * x;
}
```

注意，由$bezout$定理可得，$exgcd$必定有整数解。简单解释一下代码，由于写成递归形式，某一层和上一层的$x, y$是反过来的。就有$y -= (a / b)*x$，对应原本的算式是$y = x' - \lfloor \frac{a}{b} \rfloor \cdot y'$。

#### 「ep7」BZOJ1407 Savage

推完公式后...出了各种各样的问题...干脆面向题解。

公式如下：$c_i + xp_i \equiv (c_j + xp_j) \pmod{M}$.如果存在解，那么可以有两个同一时刻在同一位置。转换为$x(p_i - p_j) - km = c_i - c_j$。首先判定有无整数解，如果有的话，$x \leq min(l[i], l[j])$。因为在死亡之后碰面不做数~

代码如下

```cpp
// by kririae
#include <bits/stdc++.h>

using namespace std;

inline void exgcd(int &x, int &y, int a, int b)
{
  if(b) exgcd(y, x, b, a % b), y -= (a / b) * x;
  else x = 1, y = 0;
}

inline int gcd(int a, int b)
{
  return b ? gcd(b, a % b) : a;
}

int n, c[20], p[20], l[20];

inline bool judge(int M)
{
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j)
    {
      int a = p[i] - p[j], b = c[j] - c[i];
      a = (a % M + M) % M;
      int g = gcd(a, M);
      if(b % g == 0)
      {
        // 有解
        int x = 0, y = 0;
        exgcd(x, y, a, M);
        x = ((x * (b / g)) % (M / g) + (M / g)) % (M / g);
        if(x <= min(l[i], l[j])) return false;
      }
    }
  return true;
}

int main()
{
  scanf("%d", &n);
  int mx = 0;
  for (int i = 1; i <= n; ++i) scanf("%d%d%d", &c[i], &p[i], &l[i]), mx = max(mx, c[i]);
  for (int M = mx; M <= 1e6; ++M)
    if(judge(M)) return printf("%d", M), 0;
}
```

###  乘法逆元

多数时候用于处理除法带$mod$的情况，$\frac{a}{b} \equiv a \cdot \mathrm{inv}(b) \pmod{m}$。$\mathrm{inv}(b)$就是$b$的逆元。逆元存在的前提是：...先不说这个，我们用丢番图方程的整数解来证明。上式可以化为$a \equiv ab \cdot \mathrm{inv}(b) \pmod{m}$。再次化简得到$b \cdot \mathrm{inv}(b) \equiv 1 \pmod{m}$。$b \cdot \mathrm{inv}(b) - km = 1$。此方程当且仅当$gcd(b, m) = 1$时有解，进而推导$b$在$mod \ p$意义下的乘法逆元当且仅当$gcd(b, m) = 1$时存在。第一种方法，对于逆元存在的时候，可以求$exgcd$。从而得出逆元。

还有一种解法，当$p$为质数时，利用费马小定理：$b^p \equiv b \pmod{m}$。$b \cdot b^{p - 2} \equiv \pmod{m}$。所以$b^{p - 2}$是$b$在模$p$意义下的乘法逆元。代码分别是`exgcd(x, y, a, p), return (x % p + p) % p`。`return fpow(a, p - 2, p)`。

但是，还有一种球法！$inv[1] = 1, inv[i] = (p - \lfloor\frac{p}{i}\rfloor) \cdot inv[p \ mod \ i] \ mod \ p$。

写成代码是这样

```cpp
for (int i = 2; i <= n; ++i)
    inv[i] = (p - p / i) * inv[p % i] % p;
```

前两种复杂度是$O(log{n})$,最后一种是$O(n)$，不常用。

### 线性同余方程

给定$ax \equiv b \pmod{m}$。可以得到$ax + my = b$，有解当且仅当$gcd(a, m) | b$。方程的所有解是$\ mod \ \frac{m}{gcd(a, m)}$和$x$同余的整数。

#### 中国单身狗定理

有物不知其数，三三数之剩二，五五数之剩三，七七数之剩二。问物几何？

中国单身狗定理要求以下方程组的解
$$
\begin{equation}
\left\{
  \begin{array}{lr}
    x \equiv a_1 \pmod{m_1} \\
    x \equiv a_2 \pmod{m_2} \\
    \cdots \\
    x \equiv a_n \pmod{m_n}
    \end{array}
  \right.
\end{equation}
$$
其中，$gcd(m_1, m_2, \cdots, m_n) = 1$。我被这玩意儿折腾半个月了，这里重新来认真搞一搞。

令$M = \prod{m_i}$，$M_i = \frac{M}{m_i}$。令$t_i$是$M_it_i \equiv 1 \pmod{m_i}$的一个解，（也就是$M_i$关于模$m_i$意义下的一个逆元。则$x$的唯一一组解是$x = (\sum_{i = 1}^{n}{a_it_iM_i}) \ mod \ M$。

证明：
因为$gcd(m_i, m_j) = 1$，所以$gcd(m_i, M_i) = 1$。所以，存在$t_i$，是$M_i$在$\ mod \ m_i$意义下的乘法逆元。即$t_iM_i \equiv 1 \pmod{m_i}$，可以得到$a_it_iM_i \equiv a_i \pmod{m_i}$，又$m_j | M_i$，所以$a_it_iM_i \equiv 0 \pmod{m_j}$。构造$x = \sum{a_it_iM_i}$，所以满足$x = a_it_iM_i  + 0 \equiv a_i \pmod{m_i}$。$Q.E.D.$

#### $EXCRT$ 中国EX单身狗定理（大雾

相比$CRT$，$EXCRT$有个区别，$m_i, m_j$不一定互质。重新看方程：
$$
\begin{equation}
\left\{
  \begin{array}{lr}
    x \equiv a_1 \pmod{m_1} \\
    x \equiv a_2 \pmod{m_2} \\
    \cdots \\
    x \equiv a_n \pmod{m_n}
    \end{array}
  \right.
\end{equation}
$$

既然无法一次合并，那就考虑两两合并。

我们考虑前俩方程：$x \equiv a_1 \pmod{m_1}, x \equiv a_2 \pmod{m_2}$。转换成以下形式，$x = a_1 + k_1m_1, x = a_2 + k_2m_2$，减一下变成$k_1m_1 - k_2m_2  = a_2 - a_1$，根据某打起来太麻烦的定理，这里存在整数解的前提是$gcd(m_1, m_2) | a_2 - a_2$。然后解啊！用扩欧解出特解$k_1, k_2$。令$g = gcd(m_1, m_2), k_1', k_2'$为俩特解，则$k_1 = \frac{m_2}{g}t + k_1', k_2 = \frac{m_1}{g}t + k_2'$，带回原式：令$x_0 = a_1 + m_1k_1'$，$x \equiv x_0 \pmod{lcm(m_1, m_2)}$。

代码如下

```cpp
// by kririae
// 题解ver
#define ll long long
#include <bits/stdc++.h>

using namespace std;

inline void exgcd(ll &x, ll &y, ll &g, ll a, ll b)
{
  if(b) exgcd(y, x, g, b, a % b), y -= (a / b) * x;
  else x = 1, y = 0, g = a;
}

inline ll EXCRT(ll *_a, ll *_m, ll n)
{
  ll a = _a[1], m = _m[1], g, x, y, mod;
  for (int i = 2; i <= n; ++i)
  {
    exgcd(x, y, g, m, _m[i]);
    if((_a[i] - a) % g) return -1;
    x *= (_a[i] - a) / g, mod = _m[i] / g, x = (x % mod + mod) % mod;
    a = m * x + a, m = m / g * _m[i], a %= m;
  }
  return (a % m + m) % m;
}

const int maxn = 1e5 + 5;
ll n, m[maxn], a[maxn];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> m[i] >> a[i];
  cout << EXCRT(a, m, n) << endl;
}
```


### 数论函数补充

以下公式都基于唯一分解定理。假设我们已经分解了$n$。
除了莫比乌斯函数，之前的都提到过:

- $\varphi(n)$，欧拉函数，$[1, n]$中和$n$互质的数的个数。
- $\sigma(n)$，$n$的正约数之和$\prod_{i = 1}^{m}{\sum_{j = 0}^{c_i}{p_i^{j}}}$。
- $\mathrm{d}(n)$，$n$的正约数个数。$\prod{c_i + 1}$。

这几个的计算原理都很简单，就不给予证明了~。
然后，如题，补充的是莫比乌斯函数和莫比乌斯反演，我们直接进入下一个版块。

### 莫比乌斯反演
咕咕咕，之后会完成的.jpg

### 数学期望


#  一些题目备选

概率：BZOJ2318，BZOJ4720，BZOJ2720，BZOJ3720，收集邮票

各种：NOI2010能量采集