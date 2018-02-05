#include <bits/stdc++.h>

using namespace std;

inline void read(int &x)
{
	x = 0;
	int f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
    x *= f;
}

template<typename T>
inline T maxx(T a, T b) { return a > b ? a : b; };
template<typename T>
inline T minx(T a, T b) { return a > b ? a : b; };

struct cow {
	int id, l, r, basic;
	cow() {}
	cow(int a, int b, int c): basic(a), l(b), r(c) {}
	bool operator < (const cow (&a)) const {
		return l == a.l ? r < a.r : l < a.l;
	}
};

const int maxn = 5e4 + 5;
int n, cnt = 0;
int ai, bi;
int res = 0;
cow init[maxn];
priority_queue<pair<int, int> > stall; // end_time, id

int main() {
	read(n);
	for (int i = 1; i <= n; ++i) {
		read(ai); read(bi);
		init[i] = cow(i, ai, bi);
	}
	sort(init + 1, init + 1 + n); 
	stall.push(make_pair(init[1].r, 1));
	init[1].id = 1;
	++cnt;
	for (int i = 2; i <= n; ++i) {
		if(stall.size() >= 1) {
			pair<int, int> f = stall.top();
			if(f.first <= init[i].l) { 
			    stall.pop();
				init[i].id = f.second;
				f.first = init[i].r;
				stall.push(f);
			}
			else {
			    ++cnt;
				stall.push(make_pair(init[i].r, cnt));
				init[i].id = cnt;
				res = maxx(res, cnt);
			}
		}
	}
	cout << res << endl;
	for (int i = 1; i <= n; ++i) {
		cout << init[i].id << " " << init[i].basic << endl;
	}
	return 0;
}