/*
利用好5%
bzoj o2卡精度
*/
#include<cstdio>
#include<vector>
#include<iostream>
#define low(x) (x&(-x))
#define N 100005
#define eps 1e-8
using namespace std;
int n;
double A;
int mi[N];
double sum;
vector<int> up[N];
int last[N];
int main() {
	scanf("%d%lf", &n, &A);

	for(int i = 1; i <= n; i++) {
		scanf("%d", &mi[i]);
	}

	int p = 0;

	for(int i = 1; i <= n; i++) {
		for(int j = 0, len = up[i].size(); j < len; j++) {
			int u = up[i][j];
			sum -= mi[u] / (double)(last[u] - u);
			sum += mi[u] / (double)(i - u);
			last[u] = i;
			up[min(n + 1, max(i + 1, (int)(eps + (i - u) / 0.96) + u))].push_back(u);
		}

		if((int)(A * i + eps) > p) {
			p++;
			sum += mi[p] / (double)(i - p);
			last[p] = i;
			up[min(n + 1, max(i + 1, (int)(eps + (i - p) / 0.96) + p))].push_back(p);
		}

		printf("%.6lf\n", sum * mi[i]);
	}

	return 0;
}
