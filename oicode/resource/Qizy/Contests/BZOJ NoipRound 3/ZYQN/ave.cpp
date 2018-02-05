#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 100000+9;
const double EPS = 0.00001;

LL arr[N],k;
double tmp[N];
int n,Rank[N];

inline int read(){
	char c=getchar(); int ret=0,f=1;
	while (c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while (c<='9'&&c>='0') {ret=ret*10+c-'0';c=getchar();}
	return ret*f;
}

namespace Fenwick_Tree{
	#define BIT Fenwick_Tree
	#define lowbit(x) ((x)&-(x))
	int cnt[N],tot,lim;
	
	inline void init(int w){
		memset(cnt,0,sizeof(cnt));
		tot = 1; lim = n+1; 
		for (int i=w;i<=lim;i+=lowbit(i)) {
			cnt[i]++;
		}
	}
	
	inline int query(int sta) {
		int ret = 0;
		for (int i=sta;i;i-=lowbit(i)) {
			ret += cnt[i];
		}
		return tot - ret;
	}
	
	inline void insert(int w) {
		tot++;
		for (int i=w;i<=lim;i+=lowbit(i)) {
			cnt[i]++;
		}
	}
};

bool judge(double sta) {
	for (register int i=1;i<=n;++i) {
		tmp[i] = arr[i] - sta*i;
	}
	tmp[n+1] = 0;
	sort(tmp+1,tmp+1+n+1);
	for (register int i=0;i<=n;++i) {
		Rank[i] = lower_bound(tmp+1,tmp+1+n+1,arr[i]-sta*i) - tmp;
	} 
	LL ret = 0;
	BIT::init(Rank[0]);
	for (int i=1;i<=n;i++) {
		ret += BIT::query(Rank[i]);
		BIT::insert(Rank[i]);
	}
	return ret >= k;
}

int main(){
	freopen("ave.in","r",stdin);
	freopen("ave.out","w",stdout);
	n = read(); cin>>k;
	for (int i=1;i<=n;i++) {
		arr[i] = arr[i-1] + read();
	}
	double L = 0, R = 1e9, mid;
	while (R - L > EPS) {
		mid = (L + R) / 2;
		if (judge(mid)) {
			R = mid;
		} else {
			L = mid;
		}
	}
	printf("%.4lf",(R+L)/2);
	return 0;
}

