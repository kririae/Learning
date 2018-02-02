#include <bits/stdc++.h>
using namespace std;
/*
* a^b mod \quad p; 
* a, b, p\in(1, 1^9)
*/

/*
$$ a^b = a^{c_{k-1}*2^{k-1}}*a^{c_{k-2}*2^{k-2}}* ...a^{c_0*2^0} $$
*/ 

inline int power(int a, int b, int p)
{
	int ans = 1 % p;
	for (; b ; b >>= 1) 
	{
		if(b & 1) ans = (long long)ans * a % p; // 如果当前位有数字 
		a = (long long) a * a % p;
	}	
	return ans;
}

long long mul(long long a, long long b, long long p)
{
	a %= p, b %= p;
} 
int main()
{
		
	return 0;
}
