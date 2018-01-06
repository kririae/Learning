/*
区间众数详见clj论文
时间复杂度n^1.5
当然是优化了的。
空间n^1.5+n+n
首先离散化（nlogn）
然后为每一个数在每一个区间里的出现次数开一个
n^1.5的数组。
关键是每次合并most(a or b) belong to most(a)or b
这样保证n^1.5的预处理。
最后n^1.5的查询
*/
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
#define N 40005
using namespace std;
const int n2 = 205;
int a[N];
int n, m, k, p, lss;
//------------------
int start[n2], end[n2];
int data[N][n2];
int most[n2][n2];
//-------lsh----------
struct lsh {
	int *a;
	int name;
	bool operator <(const lsh &b)const {
		return *a < *(b.a);
	}
} ls[N];
int na2val[N];
inline bool cmp1(int temp, int p1, int p2, int tim2, int times, int num) {
	int b = data[temp][p2] - data[temp][p1] + tim2;

	if(p1 > p2) b = tim2;

	if(b != times) return b > times;

	return temp < num;
}
void pre() {
	for(int i = 1; i <= n; i++) {
		ls[i].a = &a[i];
	}

	sort(ls + 1, ls + n + 1);
	lss = 1;
	ls[1].name = 1;
	na2val[1] = *(ls[1].a);

	for(int i = 2, cnt = 2; i <= n; i++) {
		if(*(ls[i].a) == *(ls[i - 1].a)) {
			ls[i].name = ls[i - 1].name;
		} else {
			ls[i].name = cnt++;
			lss++;
			na2val[cnt - 1] = *(ls[i].a);
		}
	}

	for(int i = 1; i <= n; i++) {
		*(ls[i].a) = ls[i].name;
	}

	//--------finished----------------
	k = sqrt(n + 1);
	p = 1;

	for(int i = 1; i <= n; i += k, p++) {
		start[p] = i;
		end[p] = min(i + k - 1, n);
	}

	p--;

	for(int i = 1; i <= p; i++) {
		for(int j = start[i]; j <= end[i]; j++) {
			data[a[j]][i]++;
		}
	}

	for(int i = 1; i <= lss; i++) {
		for(int j = 2; j <= p; j++) {
			data[i][j] += data[i][j - 1];
		}
	}

	for(int i = 1; i <= p; i++) {
		int times = 0, num = 0;

		for(int j = start[i]; j <= end[i]; j++) {
			if(cmp1(a[j], i - 1, i, 0, times, num)) {
				num = a[j];
				times = data[a[j]][i] - data[a[j]][i - 1];
			}
		}

		most[i][i] = num;
	}

	for(int i = 1; i < p; i++) {
		for(int j = 1; i + j <= p; j++) {
			//merge i,i+j-1 i+j,i+j
			int num = most[i][i + j - 1];
			int times = data[num][i + j] - data[num][i - 1];

			for(int k = start[i + j]; k <= end[i + j]; k++) {
				if(cmp1(a[k], i - 1, i + j, 0, times, num)) {
					num = a[k];
					times = data[a[k]][i + j] - data[a[k]][i - 1];
				}
			}

			most[i][i + j] = num;
		}
	}
}
int get(int x) { //返回x所在区间
	for(int i = 1; i <= p; i++) {
		if(start[i] <= x && end[i] >= x) return i;
	}

	return 0;
}
struct mj {
	int x, times;
};
vector<mj> tube[257];
int MOD = 0x000000ff; //hash
inline void insert(int x) {
	int k = x & MOD;

	for(int i = 0, len = tube[k].size(); i < len; i++) {
		if(tube[k][i].x == x) {
			tube[k][i].times++;
			return;
		}
	}

	tube[k].push_back((mj) {
		x, 1
	});
}
inline void clr() {
	for(int i = 0; i < 256; i++) tube[i].clear();
}
int query(int fr, int to) {
	clr();
	int p1, p2;
	p1 = get(fr);
	p2 = get(to);
	int ps;

	for(ps = fr; ps <= min(to, end[p1]); ps++) {
		insert(a[ps]);
	}

	for(ps = max(ps, start[p2]); ps <= to; ps++) {
		insert(a[ps]);
	}

	int num = most[p1 + 1][p2 - 1];
	int times = data[num][p2 - 1] - data[num][p1];

	for(int i = 0; i <= 255; i++) {
		for(int j = 0, len = tube[i].size(); j < len; j++) {
			int temp = tube[i][j].x;
			int tim2 = tube[i][j].times;

			if(cmp1(temp, p1, p2 - 1, tim2, times, num)) {
				times = max(0, data[temp][p2 - 1] - data[temp][p1]) + tim2;
				num = temp;
			}
		}
	}

	return na2val[num];
}
int main() {
	scanf("%d%d", &n, &m);

	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	pre();

	for(int i = 1, last = 0; i <= m; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		l = (l + last - 1) % n + 1;
		r = (r + last - 1) % n + 1;

		if(l > r) swap(l, r);

		last = query(l, r);
		printf("%d\n", last);
	}

	return 0;
}
