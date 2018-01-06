#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int kh[200005];
char s[200005];
int n;
struct pp {
	int l, r;
	pp(int ll, int rr) {
		l = ll;
		r = rr;
	}
};
vector<pp> ans;
int main() {
	scanf("%s", s);
	n = strlen(s);

	for(int i = 1; i <= n; i++) {
		if(s[i - 1] == '(') {
			kh[i] = 1;
		} else {
			kh[i] = -1;
		}
	}

	int p = 0;

	for(int i = 1; i <= n; i++) {
		p += kh[i];

		if(p >= 0) continue;

		for(int j = i + 1; j <= n; j++) {
			p += kh[j];

			if(p >= 0) {
				ans.push_back(pp(i, j));
				i = j;
				break;
			}
		}
	}

	printf("%d\n", (int)ans.size());

	for(int i = 0, len = ans.size(); i < len; i++) {
		printf("%d %d\n", ans[i].l, ans[i].r);
	}

	return 0;
}
