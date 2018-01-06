#include<bits/stdc++.h>
using namespace std;
int main() {
	srand(time(0));
	int n = 1000000;
	long long k = 1e10;
	printf("%d %I64d\n", n, k);

	for(int i = 1; i <= n; i++) printf("%c", 'a' - 1 + (rand() % 1 + 1));

	return 0;
}
