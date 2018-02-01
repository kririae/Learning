#include <bits/stdc++.h>
using namespace std;
inline bool is_lucky_number(int t, int b)
{
	return t % 10 == 7 || (t / 10) % 10 == 7 || b % 10 == 7 || (b / 10) % 10 == 7;
}
int main() {
	freopen("clock.in", "r", stdin);
	freopen("clock.out", "w", stdout);
	int x, hh, mm;
	cin >> x >> hh >> mm;
	int cnt = 0;
	while(!is_lucky_number(hh, mm))
	{
		if(mm > x) {
			mm -= x;
		}
		if(mm <= x) {
			mm = 60 - (x - mm);
			if(hh == 0) {
				hh = 23;
			}
			else {
				--hh;
			}
		}
		++cnt;
		// cout << hh << " " << mm << endl;
	}
	cout << cnt << endl;
	fclose(stdin); fclose(stdout);
}
