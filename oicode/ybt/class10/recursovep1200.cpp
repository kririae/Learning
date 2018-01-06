#include <iostream>
#include <cstdio>

using namespace std;
int recur(int num) {
	if(num == 1) return 1;

	if(num == 2) return 1;

	return recur(num - 1) + recur(num - 2);
}
int main() {
	int count;
	cin >> count;
	int value[count];

	for(int i = 0; i < count; ++i) {
		int v;
		cin >> v;
		cout << recur(v) << endl;
	}
}
