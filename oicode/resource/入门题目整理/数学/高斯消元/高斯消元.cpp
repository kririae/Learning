/*
bzoj2460
奇怪的贪心+维护线性基
nlogV
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 1005
#define LL unsigned long long
using namespace std;
LL xxj[70];
int num;
struct ele {
	LL x;
	LL val;
	inline bool operator<(const ele &b)const
	{
		return val > b.val;
	}
} th[N];
int n;
int ans;
LL ret;
char ch;
inline LL read()
{
	ret = 0;
	ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
	return ret;
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		th[i].x = read();
		th[i].val = read();
	}
	sort(th + 1, th + n + 1);
	for(int i = 1; i <= n; i++) {
		for(int j = 63; j >= 0; j--)
			if(xxj[j] != 0 && (th[i].x & (1ull << j))) th[i].x ^= xxj[j];
		if(th[i].x) {
			ans += th[i].val;
			num++;
			if(num == 64) break;
			int p = 63;
			for(; p >= 0; p--) {
				if(th[i].x & (1ull << p)) break;
			}
			for(int j = 63; j >= 0; j--)
				if(xxj[j] & (1ull << p)) xxj[j] ^= th[i].x;
			xxj[p] = th[i].x;
		}
	}
	printf("%d\n", ans);
	return 0;
}
