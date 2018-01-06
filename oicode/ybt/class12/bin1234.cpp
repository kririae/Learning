#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
struct BigInteger {
	static const int BASE = 10000;
	static const int WIDTH = 4;
	int num_length;
	int *s;
	BigInteger(char *a = "") {
		int length_str = strlen(a);
		num_length = (length_str + WIDTH - 1) / WIDTH;
		s = new int[num_length + 1];
		memset(s, 0, sizeof(s) * num_length + 1);

		for(int i = 0, w = 1, index = 0; i < length_str; w *= 10, ++i) {
			int item = a[length_str - i - 1] - '0';

			if(i % WIDTH == 0 && i != 0) {
				w = 1;
				++index;
			}

			s[index] += w * item;
		}
	}
	BigInteger operator * (const BigInteger& other) const {
		BigInteger c;
		c.num_length = (*this).num_length + other.num_length + 1;
		c.s = new int[c.num_length + 1];
		memset(c.s, 0, sizeof(c.s) * (c.num_length + 1));

		for(int i = 0; i < num_length; ++i) {
			for(int j = 0; j < other.num_length; ++j) {
				c.s[i + j] += this->s[i] * other.s[j];
				c.s[i + j + 1] += (c.s[i + j] - (c.s[i + j] % BASE)) / BASE;
				c.s[i + j] %= BASE;
			}
		}

		int length = c.num_length;

		while(c.s[c.num_length] == 0 && c.num_length >= 0) --c.num_length;

		return c;
	}
};
template<typename T>
void swap_n(T &a, T &b) {
	T t = a;
	a = b;
	b = t;
}
void ngets() {
	char res[201];
	scanf("%s", res);
	int length = strlen(res);

	for(int i = 0; i < length / 2; ++i)
		swap_n(res[i], (res[length - i - 1]));
}
int main() {
	char *x = new char[2000];
	char *y = new char[2000];
	scanf("%s", x);
	scanf("%s", y);
	BigInteger *a = new BigInteger(x);
	BigInteger *b = new BigInteger(y);
	BigInteger c = *a * *b;

	//BigInteger c = (*b) * (*c);
	for(int i = c.num_length; i >= 0; --i) {
		if(c.s[i] == 0) for(int i = 0; i < a->WIDTH; ++i) cout << "0";
		else cout << c.s[i];
	}

	return 0;
}
