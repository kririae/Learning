#include<bits/stdc++.h> 
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

struct pos{
	int x, y, c;
}a[1005];

bool ccw(pos a, pos b, pos c){
	int dx1 = b.x - a.x, dy1 = b.y - a.y;
	int dx2 = c.x - a.x, dy2 = c.y - a.y;
	return 1ll * dx1 * dy2 > 1ll * dy1 * dx2;
}

int n;
int dp[1005][1005];
int sum[1005][1005];

struct bit{
	int tree[1005];
	void init(){memset(tree,0,sizeof(tree));}
	void add(int x, int v){
		while(x <= n){
			tree[x]+=v;
			x += x & -x;
		}
	}
	int sum(int x){
		int ret = 0;
		while(x){
			ret += tree[x];
			x -= x & -x;
		}
		return ret;
	}
}bit;

int main(){
	int p, q;
	scanf("%d %d",&p,&q);
	n = p + q;
	for(int i=1; i<=p; i++){
		scanf("%d %d",&a[i].x,&a[i].y);
		a[i].c = 1;
	}
	for(int i=p+1; i<=n; i++){
		scanf("%d %d",&a[i].x,&a[i].y);
		a[i].c = -1;
	}
	
	sort(a+1, a+n+1,[&](const pos &p, const pos &q){
		return ccw(a[0], p, q);
	});
	for(int i=1; i<=n; i++){
		vector<int> v;
		for(int j=i+1; j<=n; j++){
			v.push_back(j);
		}
		sort(v.begin(), v.end(), [&](const int &p, const int &q){
			return ccw(a[i], a[q], a[p]);
		});
		bit.init();
		for(auto &j : v){
			sum[i][j] = bit.sum(j-1);
			bit.add(j, a[j].c);
		}
	}
}

