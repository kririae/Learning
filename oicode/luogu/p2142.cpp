#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct high_per {
	int value[256], length;
	high_per()
	{
		memset(value, 0, sizeof(value));
	}
};
void loads(high_per &value)
{
	int count = 0;
	char c;

	while (!isspace(c = getchar())) {
		value.value[count] = c - '0';
		++count;
	}

	value.length = count;
	high_per reversed = value;

	for (int i = 0; i < value.length; ++i) {
		value.value[value.length - i - 1] = reversed.value[i];
	}
}
int main()
{
	high_per a, b, c;
	loads(a);
	loads(b);
	int i = 0;
	int length = a.length > b.length ? a.length : b.length;

	for (int j = 0; j < length; ++j) {
		if (a.value[j] < b.value[j]) {
			a.value[j] += 10;
			a.value[j + 1] -= 1;
		}

		c.value[j] = a.value[j] - b.value[j];
	}

	while (c.value[length - 1] == 0 && length > 1)
		--length;

	for (int k = length - 1; k >= 0; --k) {
		cout << c.value[k];
	}

	return 0;
}