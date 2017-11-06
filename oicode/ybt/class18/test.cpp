#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;
int main() {
	freopen("test.in", "w", stdout);
	srand(time(NULL));
	int n = rand() % 2000;
	cout << n << endl;
	for(int i = 0; i < n; ++i) {
		cout << rand() % 200 << " ";
	}
	fclose(stdout);
	return 0;
}
