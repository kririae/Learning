#include<cstdio>
using namespace std;
int ans[20000];
int mod = 10007;
int main() {
	ans[1] = 1;

	for(int i = 2; i <= 10006; i++) {
		ans[i] = mod - ((mod / i) * ans[mod % i] % mod);
	}

	for(int i = 1; i <= 10006; i++) {
		if(i * ans[i] % mod != 1) printf("false\n");
	}

	printf("OK\n");
	return 0;
}
