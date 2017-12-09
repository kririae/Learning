/*
每块大小w=sqrt(n/logn)
总空间nlogn
预处理出现次数前缀
然后n^2/w + wn的预处理 

wkl:采用桶排将时间复杂度降到nsqrt(n)
此时块的大小sqrt(n) 
*/
#include<cstdio>
#include<algorithm>
#include<cmath>
#define N 100005
#define W 320
using namespace std;
int n,m,c,k,k2;//k->块的大小  k2->块的个数 
int a[N];
int f[N][W];
int kuai[W][W];
int fr[W],to[W];
inline int getplace(int f){
	return 1+((f-1)/k);
}
inline int query(int x,int st,int en){//x 在块[st,en]中出现次数  
	if(en<st) return 0;
	return f[x][en]-f[x][st-1];
}
struct mj{
	int val,times;
}tong[550];//采用桶排填入
inline int merge(int st,int en,int p1,int p2,mj *t){//合并t[p1-p2]的区间与st-en的块 
	int num=max(0,kuai[st][en]);
	for(int i=p1;i<=p2;i++){
		int tt=query(t[i].val,st,en);
		if(tt!=0&&((tt&1)==0)) num--;
		if(!((tt+t[i].times)&1)) num++;
	}
	return num;
}
int time1[257];//桶排
int time2[513];
int buf[1100];
int out[1100];
inline int insert(int from,int to,int *t){
	int len1=to-from+1,len2;
	for(int i=0;i<257;i++) time1[i]=0;
	for(int i=0;i<513;i++) time2[i]=0;
	for(int i=from;i<=to;i++) time1[t[i]&255]++;
	for(int i=1;i<256;i++) time1[i]+=time1[i-1];
	for(int i=to;i>=from;i--) buf[time1[t[i]&255]--]=t[i];
	for(int i=1;i<=len1;i++) time2[(buf[i]&(0x0001ff00))>>8]++;
	for(int i=1;i<512;i++) time2[i]+=time2[i-1];
	for(int i=len1;i>=1;i--) out[time2[(buf[i]&(0x0001ff00))>>8]--]=buf[i];
	out[0]=0x00ffff00;len2=0;
	for(int i=1;i<=len1;i++){
		if(out[i]==out[i-1]) tong[len2].times++;
		else tong[++len2].val=out[i],tong[len2].times=1;
	}
	return len2;
}
void pre(){k2=1;
	for(int i=1;i<=n;i+=k,k2++){
		fr[k2]=i;to[k2]=min(i+k-1,n);
	}k2--;
	for(int i=1;i<=k2;i++){
		for(int j=fr[i];j<=to[i];j++){
			f[a[j]][i]++;
		}
	}
	for(int i=1;i<=c;i++){
		for(int j=1;j<=k2;j++){
			f[i][j]+=f[i][j-1];
		}
	}
	for(int i=1;i<=k2;i++){
		int tt=insert(fr[i],to[i],a);
		kuai[i][i]=merge(i,i-1,1,tt,tong); 
	}
	for(int i=1;i<k2;i++){
		for(int j=i+1;j<=k2;j++){
			int tt=insert(fr[j],to[j],a);
			kuai[i][j]=merge(i,j-1,1,tt,tong);
		}
	}
}
int buf2[1100];
int getans(int l,int r){
	int cnt_=0;int ii;
	int pst=getplace(l);int pen=getplace(r);
	for(ii=l;ii<=min(r,to[pst]);ii++) buf2[++cnt_]=a[ii];
	for(ii=max(ii,fr[pen]);ii<=r;ii++) buf2[++cnt_]=a[ii];
	int tt=insert(1,cnt_,buf2);
	return merge(pst+1,pen-1,1,tt,tong);
}
int main(){
	scanf("%d%d%d",&n,&c,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	k=sqrt(n);
	pre();
	for(int i=1,last=0;i<=m;i++){
		int l,r;scanf("%d%d",&l,&r);
		l=(l+last)%n+1;r=(r+last)%n+1;
		if(l>r) swap(l,r);
		last=getans(l,r);
		printf("%d\n",last);
	}
	return 0;
}
