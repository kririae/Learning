#include <iostream>
#include <cstdio>
using namespace std;
int char_list[20], n;
bool can_insert(int index, int value) {
	for(int i = 1; i <= index - 1; ++i)
		if(char_list[index] == value)
			return false;

	return true;
}
void printOut() {
	for(int i = 1; i <= n; ++i) {
		printf("%d", char_list[i]);
	}

	printf("\n");
}
void arrangement(int value) {
	if(value > n) printOut();
	else {
		for(int i = 1; i <= n; ++i) {
			if(can_insert(i, value)) char_list[i] = value;

			arrangement(value + 1);
		}
	}
}
int main() {
	n = 3;
	arrangement(0);
	return 0;
}