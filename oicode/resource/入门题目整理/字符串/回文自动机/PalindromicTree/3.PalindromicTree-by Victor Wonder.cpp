//BZOJ 3676
//»ØÎÄÊ÷
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 300010;
char ch[N];
int n, cur, now, tmp, last, tot, s[N];
int nxt[N][26], len[N], link[N], cnt[N];
ll ans;
int newnode(int l) {
	len[tot] = l;
	return tot++;
}
void init() {
	newnode(0);
	newnode(-1);
	link[0] = 1;
	s[0] = -1;
}
int getnode(int x) {
	while (s[n - len[x] - 1] != s[n]) x = link[x];

	return x;
}
void add(int c) {
	s[++n] = c;
	cur = getnode(last);

	if (!nxt[cur][c]) {
		now = newnode(len[cur] + 2);
		tmp = getnode(link[cur]);
		link[now] = nxt[tmp][c];
		nxt[cur][c] = now;
	}

	last = nxt[cur][c];
	cnt[last]++;
}
int main() {
	int i, LEN;
	gets(ch);
	LEN = strlen(ch);
	init();

	for (i = 0; i < LEN; i++) add(ch[i] - 'a');

	for (i = tot - 1; i > 1; i--) cnt[link[i]] += cnt[i];

	for (i = 2; i < tot; i++) if ((ll)len[i]*cnt[i] > ans) ans = (ll)len[i] * cnt[i];

	return printf("%lld\n", ans), 0;
}
