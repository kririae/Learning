/*O(n)*/
#include<cstdio>
#include<algorithm>
using namespace std;
int kind[65];
int k;
int n, m, p, ans;
struct buf {
	int color, place;
} v[1000005];
bool cmp(const buf &a1, const buf &a2) {
	return a1.place < a2.place;
}
int main() {
	scanf("%d%d", &n, &m);
	int cnt = 0;
	ans = 0x7fffffff;

	for(int i = 1, t; i <= m; i++) {
		scanf("%d", &t);

		for(int j = 1, b; j <= t; j++) {
			scanf("%d", &b);
			v[cnt].color = i;
			v[cnt].place = b;
			cnt++;
		}
	}

	sort(v, v + n, cmp);
	kind[v[0].color]++;
	k++;

	if(k == m) ans = 0;

	for(int i = 1, f = 0; i < cnt; i++) {
		if(kind[v[i].color] == 0) k++;

		kind[v[i].color]++;

		if(k == m) {
			while(kind[v[f].color] > 1) {
				kind[v[f].color]--;
				f++;
			}

			ans = min(ans, v[i].place - v[f].place);
		}
	}

	printf("%d", ans);
	return 0;
}
