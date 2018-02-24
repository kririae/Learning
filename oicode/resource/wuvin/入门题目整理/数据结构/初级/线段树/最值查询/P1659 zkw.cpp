#include<cstdio>
#define N 1<<18
#define INF 1<<28
#include<iostream>
using namespace std;
int maxn[N],a[N];//a-标记 
int n,m,nn;
inline void add(int k,int c){//区间k+标记c 
	a[k]+=c;
	maxn[k]+=c;
}
inline void update(int k){
	if(k<nn) maxn[k]=max(maxn[k<<1],maxn[(k<<1)+1])+a[k];
}
int main(){
	scanf("%d",&n);
	for(nn=1;nn<n+2;nn<<=1){}
	for(int i=nn+1;i<=nn+n;i++){
		scanf("%d",&maxn[i]);
	}
	for(int i=nn-1;i>0;i--)	maxn[i]=max(maxn[i<<1],maxn[(i<<1)+1]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int k,l,r,c,ans;
		scanf("%d%d%d",&k,&l,&r);
		if(k==1){
			scanf("%d",&c);
			for(int L=l+nn-1,R=r+nn+1;L!=0;L>>=1,R>>=1){
				update(L),update(R);
				if(L<R-1){
					if((L&1)==0) add(L+1,c);
					if((R&1)==1) add(R-1,c);
				}
			}
		}else{
			int lret=-INF,rret=-INF;
			bool fl=false,fr=false;
			for(int L=l+nn-1,R=r+nn+1;L!=0;L>>=1,R>>=1){
				if(fl) lret+=a[L];
				if(fr) rret+=a[R];
				if(L<R-1){
					if((L&1)==0) lret=max(lret,maxn[L+1]),fl=true;
					if((R&1)==1) rret=max(rret,maxn[R-1]),fr=true; 
				}
				
			}
			ans=max(lret,rret);
			printf("%d\n",ans);
		}
	}
	return 0;
} 
