#include <bits/stdc++.h>
using namespace std;
int f[2002][2002];
char a[2002], b[2002];
int main() {
	memset(f, 0, sizeof(f));
	cin >> a >> b;
	int lena = strlen(a);
	int lenb = strlen(b);

	for (int i = 1; i <= lena; ++i)
		f[i][0] = i;

	for (int i = 1; i <= lenb; ++i)
		f[0][i] = i;

	for (int i = 1; i <= lena; ++i) {
		for (int j = 1; j <= lenb; ++j) {
			if (a[i - 1] == b[j - 1]) {
				f[i][j] = f[i - 1][j - 1];
			} else {
				f[i][j] = min(min(f[i - 1][j], f[i][j - 1]), f[i - 1][j - 1]) + 1;
			}
		}
	}

	cout << f[lena][lenb];
}