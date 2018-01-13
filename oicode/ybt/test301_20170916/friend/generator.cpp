#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
	freopen("friend.in", "w", stdout);
	srand(time(NULL));
	int n = rand() % 100000;
	cout << n << endl;

	for(int i = 0; i < n; ++i) {
		cout << rand() % 200 << endl;
	}
}
