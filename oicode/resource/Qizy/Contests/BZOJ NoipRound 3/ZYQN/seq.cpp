#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 100000+9; 
const int M = 10000000;

int n,m,q,arr[N]; 
LL last_ans;
vector<int> Q_tmp[N];

inline int read(){
	char c=getchar(); int ret=0,f=1;
	while (c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while (c<='9'&&c>='0') {ret=ret*10+c-'0';c=getchar();}
	return ret*f;
}

namespace Segment_Tree{
	#define CT Segment_Tree
	int ch[M][2],sum[M],root[N],cnt,ans_tmp;
	
	void insert(int p, int &w, int l, int r, int pur) {
		w = ++cnt; 
		sum[w] = sum[p] + 1;
		memcpy(ch[w],ch[p],sizeof(ch[w]));
		if (l < r) {
			int mid = l + r + 1 >> 1;
			if (pur < mid) {
				insert(ch[p][0], ch[w][0],l,mid-1,pur);
			} else {
				insert(ch[p][1], ch[w][1],mid,r,pur);
			}
		}
	} 
	
	inline void build_tree(){
		for (int i=1;i<=n;i++) {
			insert(root[i-1],root[i],1,n,arr[i]);
		}
	}
	
	void query(int w, int l, int r, int x, int f) {
		if (!w) {
			return;
		} else if (l < r){
			int mid = l + r + 1 >> 1;
			if (mid <= x) {
				query(ch[w][1],mid,r,x,f);
			} else {
				ans_tmp += sum[ch[w][1]]*f;
				query(ch[w][0],l,mid-1,x,f);
			} 
		} else if (l == r && l == x) {
			ans_tmp += sum[w]*f;
		} 
	}
	
	inline int query(int l, int r, int x) {
		ans_tmp = 0; 
		query(root[l-1],1,n,x,-1);
		query(root[r],1,n,x,1);
		return ans_tmp;
	}
	
	void modify(int p, int &w, int l, int r, int x, int f) {
		w = ++cnt;
		sum[w] = sum[p] + f; 
		memcpy(ch[w],ch[p],sizeof(ch[w]));
		if (l < r) {
			int mid = l + r + 1 >> 1;
			if (x < mid) {
				modify(ch[p][0],ch[w][0],l,mid-1,x,f);
			} else {
				modify(ch[p][1],ch[w][1],mid,r,x,f);
			}
		}
	}
	
	inline void rebuild(){
		memset(ch,0,sizeof(ch));
		memset(sum,0,sizeof(sum));
		memset(root,0,sizeof(root));
		cnt = 0;
		for (int i=1;i<=n;i++) {
			root[i] = root[i-1];
			for (int j=0,lim=Q_tmp[i].size();j<lim;j++) {
				int tmp = Q_tmp[i][j];
				if (tmp < 0) {
					modify(root[i],root[i],1,n,-tmp,-1);
				} else {
					modify(root[i],root[i],1,n,tmp,1);
				}
			}
		}
	}
	
	void ask(int w, int l, int r, int x) {
		if (!w) {
			return;
		} else if (l == r && r == x) {
			ans_tmp += sum[w];
		} else if (l < r) {
			int mid = l + r + 1 >> 1;
			if (x >= mid) {
				ask(ch[w][1],mid,r,x);
				ans_tmp += sum[ch[w][0]];
			} else {
				ask(ch[w][0],l,mid-1,x);
			}
		}
	}
	
	inline int requery(int p, int x) {
		ans_tmp = 0;
		ask(root[p],1,n,x);
		return ans_tmp;
	}
};

int main(){
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	n = read(); m = read(); q = read();
	for (int i=1;i<=n;i++) {
		arr[i] = read();
	}
	CT::build_tree();
	for (int i=1,l,r,x;i<=m;i++) {
		l = read(); r = read(); x = read();
		last_ans += CT::query(l,r,x);
		Q_tmp[l].push_back(x);
		Q_tmp[r+1].push_back(-x);
	}
	CT::rebuild();
	printf("%lld\n",last_ans);
	for (int T=1,a,b;T<=q;T++) {
		a = read() ^ last_ans;
		b = read() ^ last_ans;
		last_ans += CT::requery(a,b);
		last_ans -= CT::requery(a,arr[a]);
		arr[a] = b;
		printf("%lld\n",last_ans);
	}
	return 0;
}

