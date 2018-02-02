#include<cstdio>
#include<iostream>
#include<set>
#define low(x) (x&(-x))
#define N 300005//3e5的数据有点吓人，不过相信不会T,(but I MLE..bzoj 3524)
/*但是 bzoj2223 A了
虽然树状数组常数小
但是常数巨大的set把树状数组带得来比二分+主席树还慢
无语。。。
不过还是作死成功，虽然没有开天辟地创造出什么特快结构，但是新结构还是有的
现在，去学莫队过2223了
*/
using namespace std;
int n, m, cnt, maxn; // 。cnt要倒叙 因为lowerbound 返回>=x的
struct nodedate {
	int date, vision;
	bool operator <(const nodedate &b)const
	{
		return vision < b.vision;
	}
};
set<nodedate> bi_t[10005];//有点吓人，这么多set
void add(int x)
{
	for(int i = x; i <= maxn; i += low(i)) {
		set<nodedate>::iterator itr = bi_t[i].begin();
		bi_t[i].insert((nodedate) {
			(*bi_t[i].begin()).date + 1, cnt
		});
	}
}
int times = 1;
int query(int fr, int en)
{
	fr--;//(,]
	int at = 0, ele = (en - fr) >> 1, sum = 0;
	nodedate bufr = (nodedate) {
		1, n - fr + 1
	};
	nodedate bufen = (nodedate) {
		1, n - en + 1
	};//突然发觉我把data拼成了date
	for(int i = times; i >= 0; i--) {
		at ^= 1 << i;
		if(at > maxn) {
			at ^= 1 << i, sum = 0;
			continue;
		}
		int num = (*bi_t[at].lower_bound(bufen)).date - (*bi_t[at].lower_bound(bufr)).date;
		if(num > ele) at ^= 1 << i, sum = 0;
		else sum += num;
	}
	int buf = (*bi_t[at + 1].lower_bound(bufen)).date - (*bi_t[at + 1].lower_bound(bufr)).date;
	if(buf - sum > ele) return at + 1;
	return 0;
}
int bufin[N];
int main()
{
	scanf("%d%d", &n, &maxn);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &bufin[i]);
	}
	for(int i = 0; i <= maxn; i++) bi_t[i].insert((nodedate) {
		0, n + 5
	});
	while((1 << times) <= maxn) times++;
	times--;
	for(cnt = n; cnt > 0; cnt--)
		add(bufin[n - cnt + 1]);
	scanf("%d", &m);
	for(int i = 1; i <= m; i++) {
		int fr, to;
		scanf("%d%d", &fr, &to);
		int x = query(fr, to);
		if(x != 0) {
			printf("yes %d\n", x);
		} else printf("no\n");
	}
	return 0;
}
