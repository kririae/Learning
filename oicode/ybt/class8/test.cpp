#include "iostream"
#include "cstdio"
#include "cmath"
#include "cstring"
using namespace std;
struct high_precision {
	int length, value[101];
	high_precision() {
		memset(value, 0, sizeof(value));
	}
};

void load(high_precision &input) {
	char string[101];
	scanf("%s", string);

	while(string[0] == '0' && strlen(string) > 0)
		strcpy(string, &string[1]);

	int k = strlen(string), count = 0;
	input.length = strlen(string);

	for (int i = input.length - 1; i >= 0; --i) {
		input.value[count] = string[i] - 48;
		count++;
	}
}

high_precision multi(high_precision a, high_precision b) {
	high_precision c;

	for (int i = 0; i < a.length; ++i) {
		for (int j = 0; j < b.length; ++j) {
			c.value[i + j] += a.value[i] * b.value[j];
			c.value[i + j + 1] += c.value[i + j] / 10;
			c.value[i + j] %= 10;
		}
	}

	if(c.value[a.length + b.length] == 0)
		c.length = a.length + b.length - 1;
	else
		c.length = a.length + b.length;

	return c;
}
int main() {
	high_precision a, b;
	load(a);
	load(b);
	high_precision c = multi(a, b);
	bool a_0 = false, b_0 = false;

	for (int j = 0; j < a.length; ++j)
		if(a.value[j] != 0) a_0 = true;

	for (int j = 0; j < b.length; ++j)
		if(b.value[j] != 0) b_0 = true;

	for (int i = c.length; i >= 0; --i) {
		if(c.value[i] != 0) {
			cout << c.value[i];
		}
	}

	return 0;
}
