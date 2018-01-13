#include<cstdio>
#include<vector>
using namespace std;
/*
【题目大意】
有 M 个猪圈，每个猪圈里初始时有若干头猪。一开始所有猪圈都是关闭的。依
次来了 N 个顾客，每个顾客分别会打开指定的几个猪圈，从中买若干头猪。每
个顾客分别都有他能够买的数量的上限。每个顾客走后，他打开的那些猪圈中的
猪，都可以被任意地调换到其它开着的猪圈里，然后所有猪圈重新关上。问总共
最多能卖出多少头猪。（1 <= N <= 100, 1 <= M <= 1000）
举个例子来说。有 3 个猪圈，初始时分别有 3、1 和 10 头猪。依次来了 3 个顾客，
第一个打开 1 号和 2 号猪圈，最多买 2 头；第二个打开 1 号和 3 号猪圈，最多买
3 头；第三个打开 2 号猪圈，最多买 6 头。那么，最好的可能性之一就是第一个
顾客从 1 号圈买 2 头，然后把 1 号圈剩下的 1 头放到 2 号圈；第二个顾客从 3
号圈买 3 头；第三个顾客从 2 号圈买 2 头。总共卖出 2+3+2=7 头。
*/
int n, m;
int c(int times, int pigname)
{
	return times * 1000 + pigname; //1000>=pigname>=1
}
struct edge {
	int from, to, flow, cap, cost;
	edge(int from_, int to_, int flow_, int cap_)
	{
		from = from_;
		to = to_;
		flow = flow_;
		cap = cap_;
	}
	edge(int from_, int to_, int flow_, int cap_, int cost_)
	{
		from = from_;
		to = to_;
		flow = flow_;
		cap = cap_;
		cost = cost_;
	}
};
vector<edge> e;

void addedge


int zhu[1005];//猪圈
struct custom {
	int a;//要买几个猪圈
	vector<int> v;
	int buy;//要买几只猪
} cu[105];







int main()
{
	scanf("%d%d", &m, &n);
	for(int i = 1; i <= m; i++) {
		scanf("%d", &zhu[i]);
	}
	for(int i = 1; i <= n; i++) {
		scanf("%d", &cu[i].a);
		for(int c, i = 1; i <= cu[i].a; i++) {
			scanf("%d", &c);
			cu[i].v.push_back(c);
		}
		scanf("%d", &cu[i].buy);
	}



	return 0;
}
