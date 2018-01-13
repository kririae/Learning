#include <iostream>
#include <cstdio>
using namespace std;
int n, k;
int summary = 0;
int times[100005];
bool can[100005];
int main()
{
	cin >> n >> k;
	memset(can, false, sizeof(can));
	times[n] = 1;
	times[k] = 1;
	int curr = n, proc = n + 1;

	while(n <= k) {
		if(n == k) break;

	}
}
