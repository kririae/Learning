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

// hash_ver KMP
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
const unsigned int progress = 2333;
const unsigned int mod = 19260817;

char s[maxn], t[maxn];
unsigned int f[maxn], p[maxn];

inline void prework(char c[])
{
	int length = strlen(c + 1);
	p[0] = 1;
	for (int i = 1; i <= length; ++i)
	{	
		f[i] = (unsigned long long)(f[i - 1] * progress + (c[i] - 'a' + 1));
		p[i] = (unsigned long long)(p[i - 1] * progress);
	}
}

inline unsigned int hashw_of_range(int l, int r)
{
	return (f[r] - (unsigned long long)(f[l - 1] * p[r - l + 1]));
}

int main()
{
	scanf("%s", s + 1);
	scanf("%s", t + 1);
	
	int lent = strlen(t + 1);
	int lens = strlen(s + 1);
	
	prework(t);
	unsigned int ht = f[lent];
	
	memset(f, 0, sizeof(f));
	memset(p, 0, sizeof(s));
	
	prework(s);
	
	for (int i = 1; i <= lens; ++i)
	{
		if(hashw_of_range(i, i + lent - 1) == ht) {
			cout << i << endl;
		}
	}
	return 0;
}

// --------------------------------------------------------

// 下面的是有问题的算法，但是我觉得没有什么差别...

// hash_ver KMP
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
const unsigned int progress = 2333;
const unsigned int mod = 19260817;

char s[maxn], t[maxn];
unsigned int f[maxn], p[maxn];

inline void prework(char c[])
{
	int length = strlen(c + 1);
	p[0] = 1;
	for (int i = 1; i <= length; ++i)
	{	
		f[i] = (unsigned long long)(f[i - 1] * progress + (c[i] - 'a' + 1)) % mod;
		p[i] = (unsigned long long)(p[i - 1] * progress) % mod;
	}
}

inline unsigned int hashw_of_range(int l, int r)
{
	return (f[r] - (unsigned long long)(f[l - 1] * p[r - l + 1])) % mod;
}

int main()
{
	scanf("%s", s + 1);
	scanf("%s", t + 1);
	
	int lent = strlen(t + 1);
	int lens = strlen(s + 1);
	
	prework(t);
	unsigned int ht = f[lent];
	
	memset(f, 0, sizeof(f));
	memset(p, 0, sizeof(s));
	
	prework(s);
	
	for (int i = 1; i <= lens; ++i)
	{
		if(hashw_of_range(i, i + lent - 1) == ht) {
			cout << i << endl;
		}
	}
	return 0;
}