#include <bits/stdc++.h>

// macros
#define forn(i, a, n) for (int i = a; i < n; ++i)
#define forr(i, a, n) for (int i = (n) - 1; i >= a; --i)
#define pb push_back

using namespace std;
const int N = 100005;

typedef vector<int> vi;
typedef pair<int, int> point;
typedef long long ll;
#define x first
#define y second
#define cp const point&

int n;
ll S;
point p[N];
inline ll absx(ll x) {
	return x < 0 ? -x : x;
}
point operator + (cp a, cp b) {
	return point(a.x + b.x, a.y + b.y);
}
point operator - (cp a, cp b) {
	return point(a.x - b.x, a.y - b.y);
}
ll cross(cp a, cp b) {
	return 1ll * a.x * b.y - 1ll * a.y * b.x;
}
ll cross(cp a, cp b, cp c) {
	return absx(cross(a, b) + cross(b, c) + cross(c, a));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> S;
	forn (i, 0, n) cin >> p[i].x >> p[i].y;
	//sort(p, p + n);//为什么要sort？其实不用 不过sort之后是不是期望会好一点
	random_shuffle(p, p + n);
	int a = 0, b = 1, c = 2;
	ll area = cross(p[a], p[b], p[c]);
	bool changed = true;

	while (changed) {
		changed = false;
		forn (i, 0, n) {
			ll check = cross(p[i], p[b], p[c]);

			if (check > area) {
				area = check;
				a = i;
				changed = true;
			}

			check = cross(p[a], p[i], p[c]);

			if (check > area) {
				area = check;
				b = i;
				changed = true;
			}

			check = cross(p[a], p[b], p[i]);

			if (check > area) {
				area = check;
				c = i;
				changed = true;
			}
		}
	}

	point A = p[b] - p[a] + p[c];
	point B = p[a] - p[b] + p[c];
	point C = p[a] + p[b] - p[c];
	cout << A.x << ' ' << A.y << endl;
	cout << B.x << ' ' << B.y << endl;
	cout << C.x << ' ' << C.y << endl;
}
//---------------------------or--------------------------------
#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for (int i = (a); i < (b); i++)
#define N 5678
typedef long long ll;

ll n, s, x[N], y[N];
ll ar(int a, int b, int c) {
	return abs((x[b] - x[a]) * (y[c] - y[a]) - (y[b] - y[a]) * (x[c] - x[a]));
}
int main() {
	scanf("%lld %lld", &n, &s);
	fo(i, 0, n) scanf("%lld %lld", x + i, y + i);
	int a = 0, b = 1, c = 2;

	while (1) {
		char g = 1;
		fo(i, 0, n) {
			if (ar(i, b, c) > ar(a, b, c)) a = i, g = 0;

			if (ar(a, i, c) > ar(a, b, c)) b = i, g = 0;

			if (ar(a, b, i) > ar(a, b, c)) c = i, g = 0;
		}

		if (g) break;
	}

	printf("%lld %lld\n%lld %lld\n%lld %lld\n",
	       x[a] + x[b] - x[c], y[a] + y[b] - y[c],
	       x[b] + x[c] - x[a], y[b] + y[c] - y[a],
	       x[c] + x[a] - x[b], y[c] + y[a] - y[b]);

	return 0;
}
