#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdio>
#define rep(i,l,r) for (int i=l;i<=r;i++)
#define down(i,l,r) for (int i=l;i>=r;i--)
#define clr(x,y) memset(x,y,sizeof(x))
#define ll long long
#define maxn 1000500
#define mm 19930726
using namespace std;
ll ans, k;
ll n, m, len;
char ch[maxn];
struct data {
	ll x, y;
} a[maxn];
ll read() {
	ll x = 0, f = 1;
	char ch = getchar();

	while (!isdigit(ch)) {
		if (ch == '-') f = -1;

		ch = getchar();
	}

	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}

	return x * f;
}
struct PT {
	ll sum;
	int n, tot, fail[maxn], l[maxn], nxt[maxn][30], s[maxn], last;
	ll cnt[maxn];
	int newnode(int len) {
		clr(nxt[tot], 0);
		l[tot] = len;
		cnt[tot] = 0;
		return tot++;
	}
	void init() {
		tot = 0;
		sum = 0;
		clr(fail, 0);
		newnode(0);
		newnode(-1);
		fail[0] = 1;
		last = 1;
		s[0] = -1;
		n = 0;
	}
	int getfail(int v) {
		while (s[n - l[v] - 1] != s[n]) v = fail[v];

		return v;
	}
	void add(int c) {
		s[++n] = c;
		int cur = getfail(last);

		if (!nxt[cur][c]) {
			int now = newnode(l[cur] + 2);
			fail[now] = nxt[getfail(fail[cur])][c];
			nxt[cur][c] = now;
		}

		last = nxt[cur][c];
		cnt[last]++;
	}
} T;
void p(ll x, ll y) {
	while (y) {
		if (y & 1) ans = ans * x % mm;

		x = x * x % mm;
		y /= 2;
	}
}
bool cmp(data a, data b) {
	return a.x > b.x;
}
int main() {
	freopen("1.in", "r", stdin);
	len = read();
	k = read();
	scanf("%s", ch);
	T.init();
	rep(i, 0, len - 1) T.add(ch[i] - 'a');
	down(i, T.tot - 1, 0) {
		T.cnt[T.fail[i]] += T.cnt[i];

		if (i > 1 && T.l[i] & 1) a[++m] = (data) {
			T.l[i], T.cnt[i]
		};
	}
	sort(a + 1, a + 1 + m, cmp);
	ans = 1;
	rep(i, 1, m) {
		if (a[i].y >= k) {
			p(a[i].x, k);
			k = 0;
			break;
		} else if (a[i].y < k) {
			p(a[i].x, a[i].y);
			k -= a[i].y;
		}
	}

	if (k) puts("-1");
	else printf("%I64d\n", ans);

	return 0;
}
