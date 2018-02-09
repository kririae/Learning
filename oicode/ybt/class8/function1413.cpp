#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct accurate {
	int value[1000];
	int length;
	accurate()
	{
		memset(value, -1, sizeof(value));
		length = 0;
	}
};
accurate convert(int num, int binary)
{
	accurate res, placed;
	int i = 0;

	while(num > 0) {
		res.value[i] = num % binary;
		num /= binary;
		++i;
	}

	for(int i = 0; i < 100; ++i) {
		if(res.value[i] == -1)break;
		else res.length += 1;
	}

	placed = res;

	for(int i = 0; i < res.length; ++i) {
		res.value[i] = placed.value[res.length - i - 1];
	}

	return res;
}
bool count_a_b(accurate x)
{
	int res = 0;

	for (int i = 0; i < x.length; ++i)
		res += x.value[i];

	if(res > x.length - res) return true;
	else return false;
}
int main()
{
	int a, b;
	a = b = 0;

	for (int i = 1; i <= 1000; ++i) {
		if(count_a_b(convert(i, 2))) ++a;
		else ++b;
	}

	cout << a << " " << b;
	return 0;
}