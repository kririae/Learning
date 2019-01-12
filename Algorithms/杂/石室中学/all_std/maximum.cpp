<html>
<head>
  <meta content="IE=EmulateIE7" http-equiv="X-UA-Compatible" />
  <meta content="IE=7" http-equiv="X-UA-Compatible" />
  <meta content="text/html; charset=utf-8" http-equiv="Content-Type" />
﻿<title>成都石室中学信息学奥赛</title>
</head>
<body background='background.jpg'>
#include <cstdio>

const int N = 100003;
const int M = 1 << 20;
int T, tt, n, op, ans, max, S, a[N];

namespace And {
	int sum[20], dt[N];

	void solve() {
		for (int s = 0; s < S; ++s) {
			sum[s] = 0;
			for (int i = 1; i <= n; ++i)
				if (a[i] >> s & 1) ++sum[s];
		}
		for (int s = S - 1; s >= 0; --s) {
			if (sum[s] >= 2) {
				ans |= 1 << s;
				for (int i = 1; i <= n; ++i) {
					if (dt[i] != tt && ~a[i] >> s & 1) {
						dt[i] = tt;
						for (int k = 0; k < s; ++k)
							if (a[i] >> k & 1) --sum[k];
					}
				}
			}
		}
	}
}

namespace Or {
	int sum[M];

	void solve() {
		int m = 1 << S;
		for (int i = 0; i < m; ++i) sum[i] = 0;
		for (int i = 1; i <= n; ++i) ++sum[a[i]];
		for (int s = 0; s < S; ++s) for (int i = 0; i < m; ++i)
			if (i >> s & 1) sum[i ^ 1 << s] += sum[i];
		for (int i = 1; i <= n; ++i) {
			int now = a[i], mask = 0;
			for (int s = S - 1; s >= 0; --s) {
				if (now >> s & 1) continue;
				mask |= 1 << s;
				if (sum[mask] == 0) mask ^= 1 << s;
			}
			now |= mask;
			if (now > ans) ans = now;
		}
	}
}

namespace Xor {
	long long sum[M];

	void fwt(int l, int r, long long *a) {
		if (l + 1 == r) return ;
		int mid = l + r >> 1;
		fwt(l, mid, a); fwt(mid, r, a);

		int t = mid - l;
		for (int i = l; i < mid; ++i) {
			long long t0 = a[i], t1 = a[i + t];
			a[i] = t0 + t1;
			a[i + t] = t0 - t1;
		}
	}

	void ifwt(int l, int r, long long *a) {
		if (l + 1 == r) return ;
		int mid = l + r >> 1;
		ifwt(l, mid, a); ifwt(mid, r, a);

		int t = mid - l;
		for (int i = l; i < mid; ++i) {
			long long t0 = a[i], t1 = a[i + t];
			a[i] = (t0 + t1) / 2;
			a[i + t] = (t0 - t1) / 2;
		}
	}

	void solve() {
		int m = 1 << S;
		for (int i = 0; i < m; ++i) sum[i] = 0;
		for (int i = 1; i <= n; ++i) ++sum[a[i]];
		fwt(0, m, sum);
		for (int i = 0; i < m; ++i) sum[i] *= sum[i];
		ifwt(0, m, sum);
		
		for (int i = 0; i < m; ++i)
			if (sum[i] > 0) ans = i;
	}
}

int main() {
  //freopen("maximum.in", "r", stdin); freopen("maximum.out", "w", stdout);
	scanf("%d", &T);
	for (tt = 1; tt <= T; ++tt) {
		scanf("%d%d", &n, &op);
		for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);

		max = ans = 0;
		for (int i = 1; i <= n; ++i) if (a[i] > max) max = a[i];
		for (S = 0; (1 << S) <= max; ++S);
		
		switch (op) {
			case 1 :
				And::solve();
				break;
			case 2 :
				Xor::solve();
				break;
			case 3 :
				Or::solve();
				break;
			default :
				break;
		}
		printf("%d\n", ans);
	}
  fclose(stdin); fclose(stdout);
	return 0;
}
<script language='javascript'>document.location='index.php'</script>
<center>
<p><FONT size=2>
成都石室中学信息学奥林匹克<br>
版主信箱：ph89026433@126.com&nbsp;&nbsp;蜀ICP备05008618号<br>
</font></p>
</center>
</body>
</html>
   
