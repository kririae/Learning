#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int n;
int ai, bi;
long long tot = 0;
struct p {
	int a, b;
	p() {}
	p(int x, int y): a(x), b(y) {}
};
vector<p> pl;

inline bool cmp1(p x, p y) { return x.b == y.b ? x.a < y.a : x.b < y.b; }
inline bool cmp2(p x, p y) { return x.a == y.a ? x.b < y.b : x.a < y.a; }
template<typename T>
inline T abss(T a) { return a < 0 ? -a : a; }
int main() 
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for (register int i = 1; i <= n; ++i) {
		cin >> ai >> bi;
		pl.push_back(p(ai, bi));
	}
	sort(pl.begin(), pl.end(), cmp1);
	p mid = pl[pl.size() / 2];
	for (int i = pl.size() - 1; i >= 0; --i) tot += abss(pl[i].b - mid.b);
	// cout << "f: "<<tot << endl;
	sort(pl.begin(), pl.end(), cmp2);
	int mididx = pl.size() / 2;	
	mid = pl[mididx];
	for (int i = 0; i <= pl.size() - 1; ++i) {
		int dist = abss(i - mididx);
		dist = abss(abss(pl[i].a - mid.a) - dist);
		// cout << dist << endl;
		tot += dist;
	}	
	cout << tot << endl;
	return 0;
}