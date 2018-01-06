#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
/*-----------------------------------------------------
匈牙利算法
二分图匹配
O(mn)
有反向弧/或者临界矩阵

codevs1222
直接删边来测试是否必须
删了就可以不用还回去了
-----------------------------------------------------*/
int n;
int map[105][105];//  x,y   1-false
bool vis[105];//标记y
int pi[105];//y点的匹配 0-未匹配
int pix[105];
int cur[105];
bool find(int u) { //匹配u点  u->x
	for(int i = 1; i <= n; i++) {
		if(map[u][i] != 1 && vis[i] == false) {
			vis[i] = true;

			if(pi[i] == 0) { //找到未匹配点
				pi[i] = u;
				pix[u] = i;
				return true;
			} else {
				int c = pi[i]; //代替
				pi[i] = u;

				if(find(c)) { //和谐
					pix[u] = i;
					return true;
				} else {
					pi[i] = c; //不和谐还回去
					continue;
				}
			}
		}
	}

	return false;
}
int main() {
	scanf("%d", &n);
	int a = 0, b = 0;

	do {
		map[a][b] = 1;
		scanf("%d%d", &a, &b);
	} while(a != 0);

	fill(cur + 1, cur + n + 1, 1);
	int ans = 0;

	for(int i = 1; i <= n; i++) {
		memset(vis, false, sizeof(vis));

		if(find(i)) ans++;
	}

	if(ans != n) {
		printf("none");
		return 0;
	}

	bool fl = false;

	//开始删边
	for(int i = 1; i <= n; i++) {
		int last = 0;

		if(pix[i] == 0) {
			continue;
		} else { //有匹配
			last = pix[i];
			map[i][last] = 1;
			pix[i] = 0;
			pi[last] = 0;
		}

		memset(vis, false, sizeof(vis));

		if(!find(i)) {
			fl = true;
			printf("%d %d\n", i, last);
			pi[last] = i;
		}

		map[i][last] = 0;
	}

	if(!fl) {
		printf("none");
	}

	return 0;
}
