#include<cstdio>
#include<cstring>
#define N 100005
/*好像不对*/
using namespace std;
//-------后缀数组------
char str[N];
int sa[N * 2];
int n;
int px[N], tong1[N], tong2[N], buf[N];
void build() {
	int m = 256; //桶的大小

	for(int i = 1; i <= n; i++) px[str[i]] = 1;

	for(int i = 1; i <= m; i++) px[i] += px[i - 1];

	for(int i = 1; i <= n; i++) sa[i] = px[str[i]];

	for(int k = 0; (1 << k) <= n && m != n; k++) {
		for(int i = 0; i <= m; i++) px[i] = 0;

		for(int i = 1; i <= n; i++) px[sa[i + (1 << k)]]++;

		for(int i = 1; i <= m; i++) px[i] += px[i - 1];

		for(int i = n; i >= 1; i--) tong1[px[sa[i + (1 << k)]]--] = i;

		for(int i = 0; i <= m; i++) px[i] = 0;

		for(int i = 1; i <= n; i++) px[sa[tong1[i]]]++;

		for(int i = 1; i <= m; i++) px[i] += px[i - 1];

		for(int i = n; i >= 1; i--) tong2[px[sa[tong1[i]]]--] = tong1[i];

		m = 0;

		for(int i = 1; i <= n; i++) {
			if(sa[tong2[i]] != sa[tong2[i - 1]] || sa[tong2[i] + (1 << k)] != sa[tong2[i - 1] + (1 << k)]) buf[tong2[i]] = ++m;
			else buf[tong2[i]] = m;
		}

		for(int i = 1; i <= n; i++) sa[i] = buf[i];
	}
}
int st[20][N];
int fr[20][N];
int LOG[N];
void build_st() {
	for(int i = 1; i <= n; i++) {
		st[0][i] = sa[i];
		fr[0][i] = i;
	}

	for(int j = 1; (1 << j) <= n; j++)
		for(int i = (1 << j); i <= n; i++) {
			if(st[j - 1][i] > st[j - 1][i - (1 << (j - 1))]) fr[j][i] = fr[j - 1][i], st[j][i] = st[j - 1][i];
			else fr[j][i] = fr[j - 1][i - (1 << (j - 1))], st[j][i] = st[j - 1][i - (1 << (j - 1))];
		}
}
inline int query(int l, int r) {
	int d = LOG[r - l + 1];
	return st[d][r] > st[d][l + (1 << d) - 1] ? fr[d][r] : fr[d][l + (1 << d) - 1];
}
int main() {
	scanf("%s", str + 1);
	n = strlen(str + 1);
	int m;

	for(int i = 2; i <= n; i++) LOG[i] = LOG[i >> 1] + 1;

	scanf("%d", &m);
	build();
	build_st();

	for(int i = 1, l, r; i <= m; i++) {
		scanf("%d%d", &l, &r);
		printf("%d\n", query(l, r));
	}

	return 0;
}
