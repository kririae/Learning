#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	freopen("watfly.in", "w", stdout);
	srand(time(NULL));
	int n = rand() % 10000 - 8000;
	cout << n << endl;

	for(int i = 0; i < n; ++i) {
		int f = 1;

		if(rand() % 2 == 0) f = -1;

		cout << rand() % 500 * f << " ";
	}
}
