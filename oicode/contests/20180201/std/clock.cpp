#include<bits/stdc++.h>
#define LL long long
using namespace std;

inline int read() {
	char c = getchar(); int ret = 0, f = 1;
	for (; c < '0' || c > '9'; f = c == '-'? -1: 1, c = getchar());
	for (; '0' <= c && c <= '9'; ret = ret * 10 + c - '0', c = getchar());
	return ret * f;
}

inline bool check(int x) {
	return ((x % 10) == 7) || ((x / 10) == 7);
}

int main() {
    freopen("clock.in", "r", stdin);
    freopen("clock.out", "w", stdout);
	int x = read();
	int h = read(), m = read();
	for (int i = 0; 1; i++) {
		cerr<<h<<' '<<m<<endl;
		if (check(h) || check(m)) {
			cout<<i<<endl;
			break;
		} else {
			if ((m -= x) < 0) {
				m += 60;
				h -= 1;
			}
			if (h < 0) {
				h = 23;
			}
		}
	}
	return 0;
}