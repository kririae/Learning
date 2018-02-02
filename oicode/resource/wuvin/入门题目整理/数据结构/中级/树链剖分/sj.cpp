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
	printf("%d\n", n);
	for(int i = 2; i <= n; i++) {
		printf("%d %d\n", rand() % (i - 1) + 1, i);
	}
	for(int i = 1; i <= n; i++) {
		printf("%d ", rand() % 10 - 5);
	}
	printf("\n%d\n", m);
	for(int i = 1; i <= m; i++) {
		int ins = rand() % 3 + 1;
		if(ins == 1) {
			printf("QMAX %d %d\n", rand() % n + 1, rand() % n + 1);
		} else if(ins == 2) {
			printf("QSUM %d %d\n", rand() % n + 1, rand() % n + 1);
		} else if(ins == 3) {
			printf("CHANGE %d %d\n", rand() % n + 1, rand() % 20 - 10);
		}
	}
	return 0;
}
