#include <cstdio>
#include <iostream>
#include "cstring"
using namespace std;
int res[100];
int n;
char a[100];
void printOut() {
	for (int i = 1; i <= n; ++i) {
		printf("%c", a[res[i] - 1]);
	}

	printf("\n");
}
bool allow_insert(int index, int value) {
	for (int i = 1; i < index; ++i)
		if (res[i] == value)
			return false;

	return true;
}
void insert(int init) {
	if (init > n) {
		printOut();
		return;
	}

	for (int i = 1; i <= n; ++i) {
		if (allow_insert(init, i)) {
			res[init] = i;
			insert(init + 1);
		}
	}
}
int main() {
	cin >> a;
	int length = strlen(a);
	n = length;
	insert(1);
	return 0;
}