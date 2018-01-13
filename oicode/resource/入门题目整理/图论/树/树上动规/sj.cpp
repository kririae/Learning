#include<bits/stdc++.h>
using namespace std;
int main()
{
	srand(time(0));
	int n, m;
	n = 500000;
	printf("%d\n%d\n", n, rand() % n + 1);
	for(int i = 2; i <= n; i++) {
		printf("%d %d %d\n", rand() % (i - 1) + 1, i, rand() % 1000000);
	}
	return 0;
}
