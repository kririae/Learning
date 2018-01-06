/*水题
好吧不是水题（样例都没有过我是沙茶）
天哪还要状压
据说还有spfa优化（不会会只有卡常了）
实际上只要刷表就可以过，无效状态太多
*/
#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#define N 105
#define M 26
#define LL long long
using namespace std;
//-----------------------------
inline int read(int p, int *b) {
	char c = getchar();

	while(c == '\n' || c == '\r' || c == ' ') c = getchar();

	while(c >= 'a' && c <= 'z') b[p++] = c - 'a' + 1, c = getchar();

	return p;
}
//----------AC自动机-----
int buf0, word[N], cnt, root;
struct node {
	int st;//字符串位置
	int end;//是否是一个字符串的结尾
	int ne[28];//1~26字符 0-fail
} a[N];
int kind;
void insert(int &k, int st, int en) {
	if(st > en) return;

	if(k == 0) {
		k = ++cnt;
		a[k].st = st;
	}

	if(st == en) {
		a[k].end |= kind;
		return;
	} else insert(a[k].ne[word[st + 1]], st + 1, en);
}
inline void pre_fail(int root) {
	queue<int> p;

	for(int i = 0; i <= M; i++) {
		if(a[root].ne[i] == 0) a[root].ne[i] = root;
		else {
			a[a[root].ne[i]].ne[0] = root;
			p.push(a[root].ne[i]);
		}
	}

	while(!p.empty()) {
		int u = p.front();
		p.pop();

		if(a[a[u].ne[0]].end != 0) a[u].end |= a[a[u].ne[0]].end; //用于串中匹配

		for(int i = 1; i <= M; i++) {
			if(a[u].ne[i] == 0) a[u].ne[i] = a[a[u].ne[0]].ne[i];
			else {
				a[a[u].ne[i]].ne[0] = a[a[u].ne[0]].ne[i];
				p.push(a[u].ne[i]);
			}
		}
	}
}
//-----------------------
int n, m, k;
LL dp1s[105][(1 << 10) + 1];
LL dp2s[105][(1 << 10) + 1];
const LL mod = 20090717;
LL (*dp1)[1025];
LL (*dp2)[1025];
int ones[(1 << 10) + 1];
int bbuf;
int main() {
	dp1 = dp1s;
	dp2 = dp2s;

	for(int i = 1; i < (1 << 10) + 1; i++)
		ones[i] = ones[i >> 1] + (i & 1);

	while(scanf("%d%d%d", &n, &m, &k) == 3) {
		if(n == 0 && m == 0 && k == 0) break;

		bbuf = 1 << m;

		for(int i = 1; i <= cnt; i++) {
			a[i].end = a[i].st = 0;

			for(int j = 0; j <= M; j++)
				a[i].ne[j] = 0;
		}

		int p = 1;
		cnt = root = 1;

		for(int i = 1; i <= m; i++) {
			int t = read(p, word);
			kind = 1 << (i - 1);
			insert(root, p - 1, t - 1);
		}

		pre_fail(root);
		dp1[1][0] = 1;

		for(int i = 0; i < n; i++) {
			for(int j = 1; j <= cnt; j++) {
				for(int kk = 0; kk < bbuf; kk++) {
					if(dp1[j][kk] == 0) continue;

					for(int p = 1; p <= 26; p++) {
						dp2[a[j].ne[p]][(kk) | a[a[j].ne[p]].end] += dp1[j][kk];
					}
				}
			}

			for(int j = 1; j <= cnt; j++)
				for(int kk = 0; kk < bbuf; kk++)
					dp2[j][kk] %= mod;

			swap(dp1, dp2);

			for(int j = 1; j <= cnt; j++)
				for(int i = 0; i < bbuf; i++)
					dp2[j][i] = 0;
		}

		LL ans = 0;

		for(int j = 1; j <= cnt; j++)
			for(int kk = 0; kk < bbuf; kk++) {
				if(ones[kk] >= k)
					ans += dp1[j][kk];
			}

		ans %= mod;
		printf("%d\n", (int)ans);

		for(int j = 1; j <= cnt; j++)
			for(int i = 0; i < (1 << m) + 1; i++)
				dp1[j][i] = 0;

		for(int j = 1; j <= cnt; j++)
			for(int i = 0; i < (1 << m) + 1; i++)
				dp2[j][i] = 0;
	}
}
