#include<cstdio>
#define N 100005
#define M 1800005
using namespace std;
int n,m,cnt;
const int L=0,R=1;
int root[N],n2k[N],k2n[N];
//////////////////////////////////
int bcj[N];
inline int ff(int x){
	return bcj[x]=(bcj[x]==x)? x:ff(bcj[x]);
}
inline void connect(int a,int b){//a->b;
	bcj[ff(a)]=ff(b);
}
///////////////////////////////////
int son[M][2],size[M];
void build(int &k,int fr,int to,int x){
	k=++cnt;son[k][L]=son[k][R]=0;size[k]=1;
	if(fr==to) return;
	int mid=(fr+to)>>1;
	if(x<=mid) build(son[k][L],fr,mid,x);
	else build(son[k][R],mid+1,to,x);
}
int merge(int x,int y){//y->x
	if(!x) return y;if(!y) return x;
	size[x]+=size[y];
	son[x][L]=merge(son[x][L],son[y][L]);
	son[x][R]=merge(son[x][R],son[y][R]);
	return x;
}
int query(int k,int fr,int to,int th){
	if(size[k]<th) return -1;
	if(fr==to) return fr;
	int t=size[son[k][L]];
	int mid=(fr+to)>>1;
	if(t<th) return query(son[k][R],mid+1,to,th-t);
	else return query(son[k][L],fr,mid,th);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) bcj[i]=i;
	for(int i=1;i<=n;i++) scanf("%d",&n2k[i]),k2n[n2k[i]]=i,build(root[i],1,n,n2k[i]);
	for(int i=1,f,t;i<=m;i++){
		scanf("%d%d",&f,&t);
		if(f==0) continue;
		merge(root[ff(f)],root[ff(t)]);
		connect(t,f);
	}
	int q=0;scanf("%d",&q);
	for(int i=1;i<=q;i++){
		char ins[3];int f,t;
		scanf("%s",ins);
		scanf("%d%d",&f,&t);
		if(f==0) continue;
		if(ins[0]=='Q'){
			int ans=query(root[ff(f)],1,n,t);
			if(ans!=-1)printf("%d\n",k2n[ans]);
			else puts("-1");
		}else merge(root[ff(f)],root[ff(t)]),connect(t,f);
	}
	return 0;
} 
