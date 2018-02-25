// string hash

/*
给字符串一个p进制，然后对于每种字符分配一个值。a = 1, b = 2 -> z = 26
s = "abc"
s => [1, 2, 3]
H(s) = 1 * P^2 + 2 * P + 3
其实就是从右向左走
*/

#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;

const unsigned long long p = 233;
inline unsigned long long hash(char s[])
{
	unsigned long long a = 0;
	unsigned long long temp = p;
	int length = strlen(s);
	for (int i = length - 1; i >= 0; --i) {
		a += ((s[i] - 'a' + 1) * temp);
	    temp *= temp;
	}
	a /= p;
	return a;
}

int main()
{
    cout << hash("abc") << endl;
}

// 递推代码：
for (int i = 1; i <= n; ++i)
{
	f[i] = f[i - 1]	* 233 + (s[i] - 'a' + 1);
	p[i] = p[i - 1] * 233;
}

inline unsigned long long hash_of_range(int l, int r)
{
	return f[r] - f[l - 1] * p[r - l + 1];
}