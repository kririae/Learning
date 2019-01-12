<html>
<head>
  <meta content="IE=EmulateIE7" http-equiv="X-UA-Compatible" />
  <meta content="IE=7" http-equiv="X-UA-Compatible" />
  <meta content="text/html; charset=utf-8" http-equiv="Content-Type" />
﻿<title>成都石室中学信息学奥赛</title>
</head>
<body background='background.jpg'>
#include <cstdio>
#include <algorithm>

const int N = 202;
const int M = 1002;
const int mod = 1e9 + 7;
int n, m, a[N];
int f[2][N][M];

int main() {
  freopen("group.in", "r", stdin); freopen("group.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	std::sort(a, a + n);

	int cur = 0, nxt = 1;
	f[cur][1][0] = f[cur][0][0] = 1;
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j <= n; ++j) {
			for (int k = 0; k <= m; ++k) {
				int v = f[cur][j][k]; f[cur][j][k] = 0;
				if (!v) continue;
				int t = (a[i] - a[i - 1]) * j + k;
				if (t > m) continue;
				(f[nxt][j + 1][t] += v) %= mod;
				if (j) (f[nxt][j - 1][t] += (long long)j * v % mod) %= mod;
				(f[nxt][j][t] += (long long)j * v % mod) %= mod;
				(f[nxt][j][t] += v) %= mod;
			}
		}
		std::swap(cur, nxt);
	}

	int ans = 0;	
	for (int i = 0; i <= m; ++i)
		(ans += f[cur][0][i]) %= mod;
	printf("%d\n", ans);
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
   
