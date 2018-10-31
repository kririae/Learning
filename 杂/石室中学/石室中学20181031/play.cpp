#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX=500005,L=0,R=1;
int n,c,root,cnt;
struct treee{
	int son[2],l,r;
	ll sum,mx;
}N[MAX*3];
inline char gc(){
  static char buf[1 << 18],*fs,*ft;
  return (fs==ft&&(ft=(fs=buf)+fread(buf,1,1<<18,stdin)),fs==ft)?EOF:*fs++;
}
inline ll read(){
  register ll k = 0, f = 1;
  register char c=gc();
  for (;!isdigit(c);c=gc()) if(c=='-') f=-1;
  for (;isdigit(c);c=gc())  k=(k<<3)+(k<<1)+(c-'0');
  return k*f;
}
inline void updata(int k){
	int l=N[k].son[L],r=N[k].son[R];
	N[k].sum=N[l].sum+N[r].sum;
	N[k].mx=max(N[l].mx,N[r].mx);
}
void build(int &k,int l,int r){
	k=++cnt,N[k].l=l,N[k].r=r;
	if(l==r) return;
	int mid=(l+r)/2;
	build(N[k].son[L],l,mid),build(N[k].son[R],mid+1,r);
}
void insert(int k,int num,ll len,ll h){
	if(N[k].l==N[k].r){
		N[k].sum=len;
		N[k].mx=h;
		return;
	}
	int mid=(N[k].l+N[k].r)/2;
	if(num<=mid) insert(N[k].son[L],num,len,h);
	else insert(N[k].son[R],num,len,h);
	updata(k);
}
void modify(int k,int num){
	if(N[k].l==N[k].r){
		N[k].sum=0;
		N[k].mx=0;
		return;
	}
	int mid=(N[k].l+N[k].r)/2;
	if(num<=mid) modify(N[k].son[L],num);
	else modify(N[k].son[R],num);
	updata(k);
}
ll query(int k,int l,int r){
	if(N[k].l==l&&N[k].r==r) return N[k].mx;
	int mid=(N[k].l+N[k].r)/2;
	if(r<=mid) return query(N[k].son[L],l,r);
	if(l>mid) return query(N[k].son[R],l,r);
	return max(query(N[k].son[L],l,mid),query(N[k].son[R],mid+1,r));
}
ll findl(int k,ll l){
	if(N[k].l==N[k].r) return N[k].l;
	if(N[N[k].son[L]].sum>=l) return findl(N[k].son[L],l);
	else return findl(N[k].son[R],l-N[N[k].son[L]].sum);
}
ll findr(int k,ll r){
	if(N[k].l==N[k].r) return N[k].l;
	if(N[N[k].son[L]].sum>r) return findl(N[k].son[L],r);
	else return findl(N[k].son[R],r-N[N[k].son[L]].sum);
}
int mair()
{
	n=read(),c=read();
	build(root,1,n);
	int lastans=0,num=0;
	for(int i=1;i<=n;++i){
		ll l,r,len,h;
		int id=read(),p;
		if(id==1){
			len=read(),h=read();
			if(c==1){
				len=(len*2333+lastans*666)%100000007+1;
				h=(h*2333+lastans*666)%100000007+1;
			}
			insert(root,++num,len,h);
		}
		if(id==2){
			p=read();
			modify(root,p);
		}
		if(id==3){
			l=read(),r=read();
			l=findl(root,l),r=findr(root,r);
			lastans=query(root,l,r);
			printf("%lld\n",lastans);
		}
	}
	return 0;
}

