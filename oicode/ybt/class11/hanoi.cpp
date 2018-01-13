#include <cstdio>
#include <iostream>
using namespace std;
int k = 0;
void hanoi(char a, char c, char b, int num)
{
	if(num == 0) {
		return;
	}

	++k;
	hanoi(a, b, c, num - 1);
	cout << a << "->" << k << "->" << c << endl;
	hanoi(b, c, a, num - 1);
}
int main()
{
	int n;
	char a, b, c;
	cin >> n >> a >> b >> c;
	hanoi(a, b, c, n);
	return 0;
}