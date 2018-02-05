/*
 * by kririae 2018/2/5
 * 贪心 无大量常数优化
 */
#include <bits/stdc++.h>
using namespace std;

struct person {
	int a, int b, int c;
	person() {}
	person(int x, int y, int z): a(x), b(y), c(z) {}
	bool operator < (const person (&val)) const {
		return a * b < val.a * val.b
	}
};

const int maxn = 1e5 + 5;
int n, a, b;
int maxval = 0, maxidx = 0;
vector<person> que;
int val;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	++n;
	for (int i = 1; i <= n; ++i) {
		cin >> a >> b;
		que.push_back(person(a, b, i));
	}

	unsigned int tpr = 1;
	for (int i = 1; i <= n; ++i) {
		val = tpr / que[i].second;
		if(val >= maxval) 
			maxidx = i, maxval = val;
		tpr *= que[i].first;
	} // 获取了最大值和最大值的index O(n)

	sort(que + 2, que + 1 + n); // 所有大臣排个序

	// 才反应过来需要高静，瞬间弃坑
}