#include<bits/stdc++.h>
#define N ((1<<18)+3)
#define eps (0.3)
using namespace std;
inline int read(){
	char ch=getchar();while(ch<'0'||ch>'9') ch=getchar();
	return ch-'0'; 
}
//----------------------
const long double Pi=acos((long double)-1);
struct vec{
	double r,i;
	vec operator +(const vec &b){return (vec){r+b.r,i+b.i};}
	vec operator -(const vec &b){return (vec){r-b.r,i-b.i};}
	vec operator *(const vec &b){return (vec){r*b.r-i*b.i,r*b.i+i*b.r};}
};
vec wn[2*N]; 
int rv[N];
void fft(vec *x,int len,int fx){//2^len
	for(int i=0;i<len;i++) if(i<(rv[i])) swap(x[i],x[rv[i]]);
	for(int k=1,lnow;(lnow=1<<k)<=len;k++){
		vec t1,t2;int d=(len>>k)*fx;
		for(int i=0;i<len;i+=lnow){
			vec *x1=x+i,*x2=x1+(lnow>>1);vec *t=wn+len;
			for(int j=0,t3=lnow>>1;j<t3;j++,t+=d){
				x2[j]=x1[j]-(t2=x2[j]*(*t)),x1[j]=x1[j]+t2;
			}
		}
	}
}
//---------------
vec a[N];
int n,m,len;
int main(){
	scanf("%d%d",&n,&m);len=1;while((1<<len)<n+m+1) len++;
	for(int i=0,t;i<=n;i++) a[i].r=read();
	for(int i=0,t;i<=m;i++) a[i].i=read();
	
	for(int i=1;i<(1<<len);i++) rv[i]=(rv[i>>1]>>1)|((i&1)<<(len-1));len=1<<len;
	vec w=(vec){cos(2*Pi/len),sin(2*Pi/len)};wn[0]=(vec){1,0};
	for(int i=1;i<len;i++) wn[i]=wn[i-1]*w;//优化1记忆化 
	for(int i=len;i<(len<<1);i++) wn[i]=wn[i-len];
	
	fft(a,len,1);
	a[0]=(vec){a[0].r*a[0].i,0};
	for(int i=1;i<=(len>>1);i++){
		vec v1=a[i]+a[len-i],v2=a[len-i]-a[i];
		swap(v1.i,v2.r);swap(v1.i,v2.i);v1.i=-v1.i;v1=v1*v2;
		a[i]=(vec){v1.r/4,v1.i/4};a[len-i]=(vec){a[i].r,-a[i].i};
	}
	fft(a,len,-1);
	
	for(int i=0;i<=n+m;i++) printf("%d ",(int)(a[i].r/len+eps));
	return 0;
}
