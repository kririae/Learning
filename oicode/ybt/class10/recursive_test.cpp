#include <cstdio>
#include <iostream>
using namespace std;
int res[100];
int n;
void printOut()
{
	for (int i = 1; i <= n; ++i) {
		printf("%d", res[i]);
	}

	printf("\n");
}
bool allow_insert(int index, int value)
{
	for (int i = 1; i < index; ++i)
		if(res[i] == value) return false;

	return true;
}
void insert(int init)
{
	if(init > n) {
		printOut();
		return;
	}

	for (int i = 1; i <= n; ++i) {
		if(allow_insert(init, i)) {
			res[init] = i;
			insert(init + 1);
		}
	}
}
int main()
{
	n = 3;
	insert(1);
	return 0;
}
