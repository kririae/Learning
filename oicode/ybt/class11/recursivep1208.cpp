#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 100;
void printOut(int value) {
	if(value == 2) {
		cout << "2";
		return;
	}

	if(value == 1) {
		cout << "";
		return ;
	}

	if(value == 0) {
		cout << "0";
		return ;
	}

	int *res = new int[MAXN];
	memset(res, 0, sizeof(res));
	int index = 0, index2 = 0;

	while(value > 0) {
		if(value % 2 == 1) {
			res[index2] = index;
			++index2;
		}

		value = (value - (value % 2)) / 2;
		++index;
	}

	for (int i = 0; i < index2 / 2; ++i) {
		int value;
		value = res[i];
		res[i] = res[index2 - i - 1];
		res[index2 - i - 1] = value;
	}

	for(int i = 0; i < index2; ++i) {
		if(i) cout << "+";

		cout << "2";

		if(res[i] != 1) cout << "(";

		printOut(res[i]);

		if(res[i] != 1) cout << ")";
	}
}
int main() {
	int n;
	cin >> n;
	printOut(n);
	return 0;
}