#include<cstdio>
#include<set>
#include<stack>
#define N 50005
using namespace std;
stack<int> s;
struct interval {
	int from, to;
	bool operator <(const interval &b)const {
		if(from == b.from) return to < b.to;

		return from < b.from;
	}
};
set<interval> a;
int alive[N];//destroyed -1
int n, m;
void del(int x) {
	alive[x]--;
	s.push(x);

	if(alive[x] < -1) return;

	set<interval>::iterator itr = a.upper_bound((interval) {
		x, n + 1
	});
	itr--;
	interval t = (*itr);
	a.erase(itr);

	if(t.from != x) a.insert((interval) {
		t.from, x - 1
	});

	if(t.to != x) a.insert((interval) {
		x + 1, t.to
	});
}
int query(int x) {
	if(alive[x] != 0) return 0;

	set<interval>::iterator itr = a.upper_bound((interval) {
		x, n + 1
	});
	itr--;
	return (*itr).to - (*itr).from + 1;
}
inline set<interval>::iterator merge(set<interval>::iterator &itr1, set<interval>::iterator &itr2) {
	int f = (*itr1).from, t = (*itr2).to;
	a.erase(itr1);
	a.erase(itr2);
	return a.insert((interval) {
		f, t
	}).first;
}
void rebuild() {
	int x = s.top();
	alive[x]++;
	s.pop();

	if(alive[x] != 0) return;

	set<interval>::iterator itr = a.insert((interval) {
		x, x
	}).first;

	if(x - 1 > 0 && alive[x - 1] == 0) {
		set<interval>::iterator itr2 = itr;
		itr2--;
		itr = merge(itr2, itr);
	}

	if(x + 1 <= n && alive[x + 1] == 0) {
		set<interval>::iterator itr2 = itr;
		itr2++;
		itr = merge(itr, itr2);
	}

	return;
}
int main() {
	scanf("%d%d", &n, &m);
	a.insert((interval) {
		1, n
	});

	for(int i = 1; i <= m; i++) {
		char c = getchar();
		int x;

		while(c < 'A' || c > 'Z') c = getchar();

		if(c == 'D') {
			scanf("%d", &x);
			del(x);
		} else if(c == 'Q') {
			scanf("%d", &x);
			printf("%d\n", query(x));
		} else if(c == 'R') {
			rebuild();
		}
	}

	return 0;
}
