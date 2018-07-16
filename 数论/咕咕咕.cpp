求$a^{a^{b - 1}} \ mod \ p$，$p = 1000000007$。
由费马小定理可得，$a^{p - 1} \ mod \ p = 1\ \Rightarrow \ a^p \ mod \ p = a \ \Rightarrow \ a \cdot a^{p - 1} \ mod \ p = a$。
$a^{a^{b - 1}} \ mod \ 1000000007 \ \Rightarrow \ a^{a^{b - 1} \ mod \  (1000000007 - 1)} \ mod \ 1000000007$。
欧拉定理：
$a^{\phi(p)} \equiv 1 \ (mod \ p)$。所以说费马小定理是欧拉定理的特例~
欧拉函数求法
$\phi(x) = n \cdot \prod_{p | n}(1 - \frac{1}{p})$...
证明的话是一个容斥原理qwq略了~
先说求法吧...有二
```cpp
inline int phi(int n)
{
	int ans = n;
	for (int i = 2; i * i <= n; ++i)
	{
		if(n % i == 0)
		{
			ans = ans / i * (i - 1);
			
		}
	}
}
```
有一下推论
* 如果$p$是质数，$\phi(p) = p - 1$。
* ...咕咕咕~

逆元是啥呢~
$\frac{a}{b} \ mod \ p$没法直接计算好不爽啊~~~
于是就有了逆元（
逆元的写法是$inv(x)$。
则有$a \cdot inv(b) \ mod \ p = \frac{a}{b} \ mod \ p$。
多好啊qwq
我们来看看逆元怎么求吧~
可以写成这个形式
$a \cdot inv(b) \equiv \frac{a}{b} \ (mod \ p)$ 
也可以写成：
$ax \equiv 1 \ (mod \ p)$。
然后~$ax = bp + 1$，$ax - bp = 1$。
`exgcd(x, y, a, p)` -> 可以求出`x`。就是逆元qwq
别写炸了~
