/*-----------------------------------------------------
点分治是一种树上二分的方法
可以将普通统计由n^2优化到n log n
------------------------------------------------------*/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
struct edge {
	int f, to, dis;
	edge(int fr, int t, int di): f(fr), to(t), dis(di) {}
};
vector<edge> e;
int e_len;
struct tr {
	int x[3];//余数统计  注意存的是点
	vector<int> sons;
	int father;
	int leaf;//叶节点
} tree[20005];
void addedge(int from, int to, int len) {
	e.push_back(edge(from, to, len));
	tree[from].sons.push_back(e_len++);
	e.push_back(edge(to, from, len));
	tree[to].sons.push_back(e_len++);
}
int n;
void DFS1(int u, int fa) {
	tree[u].father = fa;
	tree[u].leaf = 1;

	for(int i = 0, len = tree[u].sons.size(); i < len; i++) {
		edge& ed = e[tree[u].sons[i]];

		if(ed.to == fa) continue;

		DFS1(ed.to, u);
		tree[u].leaf = 0;
	}
}
int ansall;//和为零的组数
void DFS2(int u) { //返回三元组
	if(tree[u].leaf == 1) {
		tree[u].x[0] = 1;
		return;
	}

	for(int i = 0, len = tree[u].sons.size(); i < len; i++) {
		edge& ed = e[tree[u].sons[i]];

		if(ed.to == tree[u].father) continue;

		DFS2(ed.to);
	}

	int sum[3] = {0, 0, 0};
	int ans2 = 0;

	for(int i = 0, len = tree[u].sons.size(); i < len; i++) {
		edge& ed = e[tree[u].sons[i]];

		if(ed.to == tree[u].father) continue;

		for(int j = 0; j < 3; j++) {
			sum[(j + ed.dis) % 3] += tree[ed.to].x[j];
		}
	}

	for(int i = 0, len = tree[u].sons.size(); i < len; i++) {
		edge& ed = e[tree[u].sons[i]];

		if(ed.to == tree[u].father) continue;

		int ax[3];

		for(int j = 0; j < 3; j++) {
			ax[(j + ed.dis) % 3] = tree[ed.to].x[j];
		}

		for(int j = 0; j < 3; j++) {
			/*
			int ys=tree[ed.to].x[j];//该子节点中余数为j的个数
			int qt=sum[(3-j)%3]-tree[ed.to].x[(-j-ed.dis+3000)%3];//其他子节点与之配对个数
			ans2+=ys*qt;*/
			ans2 += ax[j] * (sum[(3 - j) % 3] - ax[(3 - j) % 3]);
		}
	}

	for(int j = 0; j < 3; j++) {
		tree[u].x[j] = sum[j];
	}

	//ans2/=2;
	ans2 += sum[0] * 2;
	tree[u].x[0]++;
	ansall += ans2;
}
int gcd(int a, int b) { //a<b
	if(b % a == 0) return a;

	return gcd(b % a, a);
}

int main() {
	scanf("%d", &n);

	for(int f, t, d, i = 1; i < n; i++) {
		scanf("%d%d%d", &f, &t, &d);
		addedge(f, t, d);
	}

	DFS1(n, n);
	DFS2(n);
	int ans1 = ansall + n;

	if(ans1 == 0) {
		printf("0");
		return 0;
	}

	int ans2 = n * n;
	int c = gcd(ans1, ans2);
	ans1 /= c;
	ans2 /= c;
	printf("%d/%d", ans1, ans2);
	return 0;
}
