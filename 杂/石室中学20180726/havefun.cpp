#define ll long long
// #define R register
// #define up t[k].son[0]
// #define down t[k].son[1]
// #define left t[k].son[2]
// #define right t[k].son[3]
#include <bits/stdc++.h>

using namespace std;

const int maxn = 2005;

namespace havefun
{
struct Node
{
	int val, son[4];
} t[maxn * maxn];
int n, m, q, A[maxn][maxn], qwq[maxn][maxn], ans[maxn][maxn];
Node qaq[maxn][10];

void spawning(int P,int Q,int R,int S,int Mod){
	int T=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			T=(T+(1ll*(i+j)*P+1ll*i*j*Q+1ll*i*R+1ll*j*S)%Mod+Mod)%Mod;
			A[i][j]=T;
		}
	A[P%n+1][P%m+1]^=1;A[P%n+1][Q%m+1]^=1;A[P%n+1][R%m+1]^=1;A[P%n+1][S%m+1]^=1;
	A[Q%n+1][P%m+1]^=1;A[Q%n+1][Q%m+1]^=1;A[Q%n+1][R%m+1]^=1;A[Q%n+1][S%m+1]^=1;
	A[R%n+1][P%m+1]^=1;A[R%n+1][Q%m+1]^=1;A[R%n+1][R%m+1]^=1;A[R%n+1][S%m+1]^=1;
	A[S%n+1][P%m+1]^=1;A[S%n+1][Q%m+1]^=1;A[S%n+1][R%m+1]^=1;A[S%n+1][S%m+1]^=1;
}

inline void swap_link(int x1, int y1, int x2, int y2, int h, int w)
{
	for (int i = x1; i <= x1 + h - 1; ++i)
		for (int j = y1; j <= y1 + w - 1; ++j)
			swap(A[i][j], A[x2 + (i - x1)][y2 + (j - y1)]);
}

void checker(){
	long long Pin=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			Pin+=(1ll*i*n+j)*A[i][j];
		}
	}printf("%lld\n",Pin);
}


inline void solve()
{
	freopen("havefun.in", "r", stdin);
	freopen("havefun.out", "w", stdout);
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m >> q;
	int tmp[6];
	for (int i = 1; i <= 5; ++i) cin >> tmp[i];
	spawning(tmp[1], tmp[2], tmp[3], tmp[4], tmp[5]);
	int x1, y1, x2, y2, h, w;
	while(q--)
	{
		cin >> x1 >> y1 >> x2 >> y2 >> h >> w;
		swap_link(x1, y1, x2, y2, h, w);
	}
	checker();
}
}

int main()
{
	return havefun::solve(), 0;
}

/*
#define ll long long
// #define R register
// #define up t[k].son[0]
// #define down t[k].son[1]
// #define left t[k].son[2]
// #define right t[k].son[3]
#include <bits/stdc++.h>

using namespace std;

const int maxn = 2005;

namespace havefun
{
struct Node
{
	int val, son[4];
} t[maxn * maxn];
int n, m, q, A[maxn][maxn], qwq[maxn][maxn], ans[maxn][maxn];
Node qaq[maxn][10];

void spawning(int P,int Q,int R,int S,int Mod){
	int T=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			T=(T+(1ll*(i+j)*P+1ll*i*j*Q+1ll*i*R+1ll*j*S)%Mod+Mod)%Mod;
			A[i][j]=T;
		}
	A[P%n+1][P%m+1]^=1;A[P%n+1][Q%m+1]^=1;A[P%n+1][R%m+1]^=1;A[P%n+1][S%m+1]^=1;
	A[Q%n+1][P%m+1]^=1;A[Q%n+1][Q%m+1]^=1;A[Q%n+1][R%m+1]^=1;A[Q%n+1][S%m+1]^=1;
	A[R%n+1][P%m+1]^=1;A[R%n+1][Q%m+1]^=1;A[R%n+1][R%m+1]^=1;A[R%n+1][S%m+1]^=1;
	A[S%n+1][P%m+1]^=1;A[S%n+1][Q%m+1]^=1;A[S%n+1][R%m+1]^=1;A[S%n+1][S%m+1]^=1;
}

inline void init()
{
	// 生成dancing link
	int cnt = 0;
	for (int i = 0; i <= n + 1; ++i)
		for (int j = 0; j <= m + 1; ++j)
			qwq[i][j] = ++cnt;
	for (int i = 0; i <= n + 1; ++i)
		for (int j = 0; j <= m + 1; ++j)
		{
			t[qwq[i][j]].son[0] = qwq[i - 1][j];
			t[qwq[i][j]].son[1] = qwq[i + 1][j];
			t[qwq[i][j]].son[2] = qwq[i][j - 1];
			t[qwq[i][j]].son[3] = qwq[i][j + 1];
			t[qwq[i][j]].val = A[i][j];
		}
		// qwq数组失效，开始交换
}

inline int get(int x, int y)
{
	// 整个都是一个链表撑起来的，所以需要快速获取信息
	int curr = qwq[0][0]; // 从0， 0开始走，因为这个一定不会变
	for (int i = 1; i <= x; ++i)
		curr = t[curr].son[1];
	for (int i = 1; i <= y; ++i)
		curr = t[curr].son[3];
	return curr;
}

inline int getval(int x, int y)
{
	int pos = get(x, y);
	return t[pos].val;
}

// inline void swap_link(int x1, int y1, int x2, int y2, int h, int w)
// {
// 	int first = get(x1, y1), second = get(x2, y2); // 或许初始位置的信息；
// 	Node tmp[maxn][17]; int tmp1[maxn][17];
// 	// 左链修改
// 	int curr1 = first, curr2 = second;
// 	for (int i = 1; i <= h; ++i)
// 	{
// 		tmp[i][1] = t[curr1], tmp[i][2] = t[curr2];
// 		tmp[i][3] = t[t[curr1].son[0]], tmp[i][4] = t[t[curr2].son[0]];
// 		// tmp1[i][0] = curr1, tmp1[i][1] = curr2;
// 		curr1 = t[curr1].son[1], curr2 = t[curr2].son[1];		
// 	}
// 	// 水平链修改
// 	curr1 = first, curr2 = second;
// 	for (int i = 1; i <= w; ++i)
// 	{
// 		tmp[i][5] = t[curr1], tmp[i][6] = t[curr2];
// 		tmp[i][7] = t[t[curr1].son[0]], tmp[i][8] = t[t[curr2].son[0]];
// 		// tmp1[i][0] = 
// 		curr1 = t[curr1].son[3], curr2 = t[curr2].son[3];
// 	}
// 	// 右侧链的备份
// 	curr1 = get(x1, y1 + w - 1), curr2 = get(x2, y2 + w - 1);
// 	for (int i = 1; i <= h; ++i)
// 	{
// 		tmp[i][9] = t[curr1], tmp[i][10] = t[curr2];
// 		tmp[i][11] = t[t[curr1].son[0]], tmp[i][12] = t[t[curr2].son[0]];
// 		curr1 = t[curr1].son[1], curr2 = t[curr2].son[1];	
// 	}
// 	// 下底链的备份
// 	curr1 = get(x1 + h - 1, y1), curr2 = get(x2 + h - 1, y2);
// 	for (int i = 1; i <= w; ++i)
// 	{
// 		tmp[i][13] = t[curr1], tmp[i][14] = t[curr2];
// 		tmp[i][15] = t[t[curr1].son[0]], tmp[i][16] = t[t[curr2].son[0]];
// 		// tmp1[i][0] = 
// 		curr1 = t[curr1].son[3], curr2 = t[curr2].son[3];
// 	}
// 	// 然后作链之间的交换，注意交换是多重方向的
// 	// [1, 2], [3, 4], [5, 6], [7, 8], [9, 10]
// 	// 
// }

inline void swap_link(int x1, int y1, int x2, int y2, int h, int w)
{
    ++w;
	// 将两个矩阵交换
	int first = get(x1, y1), second = get(x2, y2); // 或许初始位置的信息；
	// 准备开始rebuild
	// rebuild过程分为两个，断开所有的链，重连链，记住链是双向的
	int curr1 = first, curr2 = second;
	int curr3 = get(x1, y1), curr4 = get(x2, y2);
	int curr5 = get(x1, y1 + w - 1), curr6 = get(x2, y2 + w - 1);
	int curr7 = get(x1 + h - 1, y1), curr8 = get(x2 + h - 1, y2);
	// 左侧链的重连
	for (int i = 1; i <= h; ++i)
	{
		swap(t[t[curr1].son[2]].son[3], t[t[curr2].son[2]].son[3]);
		swap(t[curr1].son[2], t[curr2].son[2]);
		curr1 = t[curr1].son[1], curr2 = t[curr2].son[1];
	}
	// 上水平链的重连
	for (int i = 1; i <= w; ++i)
	{
		swap(t[t[curr3].son[0]].son[1], t[t[curr4].son[0]].son[1]);
		swap(t[curr3].son[0], t[curr4].son[0]);
		curr3 = t[curr3].son[3], curr4 = t[curr4].son[3];
	}
	// 右侧链的重连 上链左链已经破坏...
	for (int i = 1; i <= h; ++i)
	{
		swap(t[t[curr5].son[2]].son[3], t[t[curr6].son[2]].son[3]);
		swap(t[curr5].son[2], t[curr6].son[2]);
		curr5 = t[curr5].son[1], curr6 = t[curr6].son[1];
	}
	// 可能会存在已经修改的链影响的情况，注意注意
	for (int i = 1; i <= w; ++i)
	{
		swap(t[t[curr7].son[0]].son[1], t[t[curr8].son[0]].son[1]);
		swap(t[curr7].son[0], t[curr8].son[0]);
		curr7 = t[curr7].son[3], curr8 = t[curr8].son[3];
	}
	// fin， 不知道有没有锅
}

inline void RE()
{
	// 大常数ver
	int curr = qwq[0][0];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			A[i][j] = getval(i, j);
}

void checker(){
	long long Pin=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			Pin+=(1ll*i*n+j)*A[i][j];
		}
	}printf("%lld\n",Pin);
}

inline void solve()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m >> q;
	int tmp[6];
	for (int i = 1; i <= 5; ++i) cin >> tmp[i];
	spawning(tmp[1], tmp[2], tmp[3], tmp[4], tmp[5]);
	init();
	int x1, y1, x2, y2, h, w;
	while(q--)
	{
		cin >> x1 >> y1 >> x2 >> y2 >> h >> w;
		swap_link(x1, y1, x2, y2, h, w);
	}
	cout << endl;
	RE();
    checker();
}
}

int main()
{
	return havefun::solve(), 0;
}
*/
