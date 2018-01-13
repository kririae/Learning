#include <iostream>
#include <cstdio>
using namespace std;

const int maxn = 500005;

int n, cnt;
long long ans;
int height[maxn];
int q[maxn];
int time[maxn];

inline void push(int val)
{
	q[cnt++] = val;
}

inline void pop()
{
	--cnt;
}

inline bool empty()
{
	return (cnt == 0);
}

int main()
{
	cnt = 0;
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int t;
		cin >> t;
		while(cnt != 0 && q[cnt - 1] < t) {
			// 如果上一个小于这一个
			// 那么这一个能够看到全部之前的
			// 然后就向前走一格 然后就pop出来 直到有一个比自己大的
			ans += time[cnt - 1];
			pop();
		}
		if(cnt == 0) {
			// 如果一个都没有了 那就把当前的加进去
			push(t);
			time[cnt - 1] = 1;
		} else if(q[cnt - 1] == t) {
			// 如果前一个人和自己相同
			// 那前一个人能够多看见一个人
			// 答案也++
			ans += time[cnt - 1];
			++time[cnt - 1];
			// 上一个也能看见这一个qwq...
			if(cnt != 1) ++ans;
		} else {
			++ans;
			push(t);
			time[cnt - 1] = 1;
		}
	}
	cout << ans << endl;
}