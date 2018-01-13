#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int int_max = 4294967295;
struct accurate {
	int length;
	int value[10000];
	accurate()
	{
		memset(value, 0, sizeof(value));
	}
};
accurate multi(accurate a, accurate b)
{
	accurate c;

	for (int i = 0; i < a.length; ++i)
		for (int j = 0; j < b.length; ++j)
			c.value[i + j] +=  a.value[i] * b.value[j];

	for (int k = 0; k < a.length ; ++k)
		for (int i = 0; i < b.length; ++i)
			if(c.value[i + k] >= 10) {
				c.value[i + k + 1] += c.value[i + k] / 10;
				c.value[i + k] %= 10;
			}

	c.length = a.length + b.length;

	while(c.value[c.length - 1] == 0 && c.length > 1)
		--c.length;

	return c;
}
void split(int x, int res[])
{
	int i = 1;

	for(int j = 0; i <= x; ++j)
		while(true) {
			if(res[j]*i >= int_max - 10001) break;
			else {
				res[j] *= i;
				++i;
			}
		}
}
accurate re_convert(int x)
{
	int y = x, count = 0;
	accurate c;

	while(true) {
		if (y > 0) {
			c.value[count] = y % 10;
			y /= 10;
			count += 1;
		} else break;
	}

	c.length = count;
	return c;
}
int main()
{
	int res[10000];
	memset(res, 1, sizeof(res));
	accurate a, b;
	b.value[0] = 1;
	b.length = 1;
	int num, length = 0;
	scanf("%d", &num);
	split(num, res);

	for(int i = 0; i < 10000; ++i) {
		if(res[i] == 1) break;

		++length;
	}

	for(int i = 0; i < length; ++i)
		b = multi(re_convert(res[i]), b);

	for(int i = b.length - 1; i >= 0 ; --i) cout << b.value[i] << " ";

	return 0;
}