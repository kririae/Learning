#include<cstdio>
#define N 200005
#define low(x) (x&(-x))
using namespace std;
int place[N], number[N];
int bittree[N];
int xl[N];//×îÖÕ´ð°¸
int n, m;
void insert(int _place, int num)
{
	int x = 0;
	int sum = 0;
	for(int i = 18; i >= 0; i--) {
		x ^= 1 << i;
		if(x > n || low(x) - bittree[x] + sum >= _place) x ^= 1 << i;
		else sum += low(x) - bittree[x];
	}
	xl[++x] = num;
	for(int i = x; i <= n; i += low(i)) {
		bittree[i]++;
	}
}
int main()
{
	while(scanf("%d", &n) == 1) {
		for(int i = 1; i <= n; i++) {
			scanf("%d%d", &place[i], &number[i]);
			bittree[i] = 0;
		}
		for(int i = n; i >= 1; i--) {
			insert(place[i] + 1, number[i]);
		}
		for(int i = 1; i <= n; i++) {
			printf("%d ", xl[i]);
		}
		puts("");
	}
	return 0;
}
