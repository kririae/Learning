#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstdio>
using namespace std;
int main()
{
	int n, m;
	srand(time(0));
	n = rand() % 20 + 1;
	m = rand() % 10;
	printf("%d %d\n", n, m);
	for(int i = 1; i <= m; i++) {
		printf("%d %d\n", rand() % n + 1, rand() % n + 1);
	}
	return 0;
}
