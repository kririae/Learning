/*
DS维护最短路转移
代码题啊
*/
//二维线段树
//写死我了，代码能力退步啊，还是改写4个二维树状数组的
//T了
//算了去写树状数组吧
//哎呀，140ms就过了
//常数啊常数，怎么差别这么大？
//莫非我花式线段树写残了？
#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
const int LT = 0, RT = 1, LB = 2, RB = 3, H = 1, Z = 0, L = 0, R = 1; // 左上 右上 左下 右下
//-----------------------
/*struct xds{
    int son[2],side,le,ri,tp,bt;
    int vision[4],mn[4];
}a[200000];int cnt;
void build(int &k,int l,int r,int t,int b){
    k=++cnt;
    int side=(r-l>b-t)? H:Z;a[k].side=side;a[k].le=l;a[k].ri=r;a[k].tp=t;a[k].bt=b;
    a[k].vision[0]=a[k].vision[1]=a[k].vision[2]=a[k].vision[3]=-1;
    a[k].mn[0]=a[k].mn[1]=a[k].mn[2]=a[k].mn[3]=0x3f3f3f3f;
    if(side==H){
        if(l!=r){
            build(a[k].son[L],l,(l+r)>>1,t,b);
            build(a[k].son[R],1+((l+r)>>1),r,t,b);
        }
    }else if(side==Z){
        if(t!=b){
            build(a[k].son[L],l,r,t,(t+b)>>1);
            build(a[k].son[R],l,r,1+((t+b)>>1),b);
        }
    }
}
#define minn(x,y) x<y? x:y
//int vis,fx,val,x,y;
void insert(int k,int x,int y,int vis,int fx,int val){
    if(a[k].vision[fx]!=vis){
        a[k].vision[fx]=vis;a[k].mn[fx]=val;
    }else a[k].mn[fx]=minn(a[k].mn[fx],val);
    if(a[k].le!=a[k].ri||a[k].tp!=a[k].bt){
        if(a[k].side==H) insert(a[k].son[((a[k].le+a[k].ri)>>1)>=x? L:R],x,y,vis,fx,val);
        else if(a[k].side==Z) insert(a[k].son[((a[k].tp+a[k].bt)>>1)>=y? L:R],x,y,vis,fx,val);
    }
}
int query(int k,int stx,int endx,int sty,int endy,int fx,int vis){
    if(a[k].le==stx&&a[k].ri==endx&&a[k].tp==sty&&a[k].bt==endy)
        return a[k].vision[fx]==vis? a[k].mn[fx]:0x3f3f3f3f;
    if(a[k].side==H){
        int mid=(a[k].le+a[k].ri)>>1;
        if(mid<stx) return query(a[k].son[R],stx,endx,sty,endy,fx,vis);
        else if(mid>=endx) return query(a[k].son[L],stx,endx,sty,endy,fx,vis);
        else return min(query(a[k].son[L],stx,mid,sty,endy,fx,vis),query(a[k].son[R],mid+1,endx,sty,endy,fx,vis));
    }else if(a[k].side==Z){
        int mid=(a[k].tp+a[k].bt)>>1;
        if(mid<sty) return query(a[k].son[R],stx,endx,sty,endy,fx,vis);
        else if(mid>=endy) return query(a[k].son[L],stx,endx,sty,endy,fx,vis);
        else return min(query(a[k].son[L],stx,endx,sty,mid,fx,vis),query(a[k].son[R],stx,endx,mid+1,endy,fx,vis));
    }
}*/
int ffx[4][305][305], vfx[4][305][305];
void build() {
	memset(vfx, -1, sizeof(vfx));
}
//lt x->x y->y
//lb x->x y->n+1-y
//rt x->m+1-x y->y
//rb x->m+1-x y->n+1-y
#define low(x) x&(-x)
#define minn(x,y) x<y? x:y
int n, m, pall;
int (*v)[305];
int (*biao)[305];
int* w;
int *wb;
void insert(int x, int y, int vis, int fx, int val) {
	if(fx & 1) x = m + 1 - x;

	if(fx > 1) y = n + 1 - y;

	v = ffx[fx];
	biao = vfx[fx];

	for(int i = x; i <= m; i += low(i)) {
		w = v[i];
		wb = biao[i];

		for(int j = y; j <= n; j += low(j)) {
			if(wb[j] != vis) wb[j] = vis, w[j] = val;
			else w[j] = minn(w[j], val);
		}
	}
}
int ret;
int query(int x, int y, int fx, int vis) {
	if(fx & 1) x = m + 1 - x;

	if(fx > 1) y = n + 1 - y;

	v = ffx[fx];
	biao = vfx[fx];
	ret = 0x3f3f3f3f;

	for(int i = x; i; i -= low(i)) {
		w = v[i];
		wb = biao[i];

		for(int j = y; j; j -= low(j)) {
			if(wb[j] == vis) ret = minn(ret, w[j]);
		}
	}

	return ret;
}
//-----------------------
int p[305][305];
int dp[305][305];
struct pl {
	int x, y;
};
vector<pl> vec[90005];
#define min4(a,b,c,d) min(min(a,b),min(c,d))
int main() {
	scanf("%d%d%d", &n, &m, &pall);

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			scanf("%d", &p[i][j]);
			vec[p[i][j]].push_back((pl) {
				j, i
			});
		}

	build();
	insert(1, 1, 0, LT, -2);

	for(int i = 1, xx, yy; i <= pall; i++) {
		for(int j = vec[i].size() - 1; j >= 0; j--) {
			xx = vec[i][j].x;
			yy = vec[i][j].y;
			dp[xx][yy] = min4(query(xx, yy, LT, i - 1) + xx + yy, query(xx, yy, LB, i - 1) + xx - yy,
			                  query(xx, yy, RT, i - 1) - xx + yy, query(xx, yy, RB, i - 1) - xx - yy);
		}

		for(int j = vec[i].size() - 1; j >= 0; j--) {
			xx = vec[i][j].x;
			yy = vec[i][j].y;
			insert(xx, yy, i, LT, dp[xx][yy] - xx - yy);
			insert(xx, yy, i, LB, dp[xx][yy] - xx + yy);
			insert(xx, yy, i, RT, dp[xx][yy] + xx - yy);
			insert(xx, yy, i, RB, dp[xx][yy] + xx + yy);
		}

		if(i == pall) {
			printf("%d\n", dp[xx][yy]);
		}
	}

	return 0;
}
