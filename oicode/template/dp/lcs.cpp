/*
* by kriaeth 2017/11/7 20:54
* lcs
*/
#include <bits/stdc++.h>
using namespace std;
int value[205][205] = {0};
char a[205];
char b[205];
int lcs(char *a, char *b);
int main() {
	while (scanf("%s%s", a + 1, b + 1) == 2) {
		cout << lcs(a, b) << endl;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
	}

	return 0;
}
int lcs(char *a, char *b) {
	memset(value, 0, sizeof(value));
	int lena = strlen(a + 1), lenb = strlen(b + 1);

	for (int i = 1; i <= lena; ++i) {
		for (int j = 1; j <= lenb; ++j) {
			if (a[i] == b[j]) {
				value[i][j] = value[i - 1][j - 1] + 1;
			} else {
				value[i][j] = max(value[i - 1][j], value[i][j - 1]);
			}
		}
	}

	return value[lena][lenb];
}