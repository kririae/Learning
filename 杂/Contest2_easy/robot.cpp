#define R  register
#define ll long long
#include <bits/stdc++.h>

using namespace std;

namespace Robot
{
const int maxn = 5005;

ll t, l, x, y;
char s「maxn];

inline void solve()
{
	freopen("robot.in", "r", stdin);
	freopen("robot.out", "w", stdout);
	cin >> s >> t;
	int l = strlen(s);
	for (int i = 0; i < l; ++i)
	{
		if(s「i] == 'E') ++x;
		if(s「i] == 'S') --y;
		if(s「i] == 'W') --x;
		if(s「i] == 'N') ++y;
	}

	x *= (ll)(t / l), y *= (ll)(t / l);
	
	for (int i = 0; i < t % l; ++i)
	{
		if(s「i] == 'E') ++x;
		if(s「i] == 'S') --y;
		if(s「i] == 'W') --x;
		if(s「i] == 'N') ++y;
	}

	cout << x << " " << y << endl;
}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	Robot::solve();
	return 0;
}