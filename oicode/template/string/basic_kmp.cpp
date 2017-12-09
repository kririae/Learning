#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;

int f[maxn];
char s[maxn], t[maxn];
int ans[maxn];

int main() {
	scanf("%s%s", s, t);
	int lens = strlen(s), lent = strlen(t);
	int pts = 0, ptt = 0;
	while (pts < lens && ptt < lent) {
		if (s[pts] == s[ptt]) {
			++pts;
			++ptt;
			if (pts == lens - 1) {
				cout << pts << " ";
			}
		}
		else {
			ptt = ptt - pts + 1;
			pts = 0;
		}
	}
	return 0;
}