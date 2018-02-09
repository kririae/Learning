#include<cstdio>
#include<queue>
using namespace std;
int dp[100005];
int n, k;
struct no {
	int pl, step;
};
queue<no> q;
void BFS()
{
	q.push((no) {
		n, 1
	});
	dp[n] = 1;
	while(!q.empty()) {
		if(dp[k] != 0) {
			printf("%d", dp[k] - 1);
			return;
		}
		no u = q.front();
		q.pop();
		if(u.pl + 1 <= 100000 && dp[u.pl + 1] == 0) {
			dp[u.pl + 1] = u.step + 1;
			q.push((no) {
				u.pl + 1, u.step + 1
			});
		}
		if(u.pl - 1 >= 0 && dp[u.pl - 1] == 0) {
			dp[u.pl - 1] = u.step + 1;
			q.push((no) {
				u.pl - 1, u.step + 1
			});
		}
		if((u.pl << 1) <= 100000 && dp[u.pl << 1] == 0) {
			dp[u.pl << 1] = u.step + 1;
			q.push((no) {
				u.pl << 1, u.step + 1
			});
		}
	}
}
int main()
{
	scanf("%d%d", &n, &k);
	BFS();
	return 0;
}
