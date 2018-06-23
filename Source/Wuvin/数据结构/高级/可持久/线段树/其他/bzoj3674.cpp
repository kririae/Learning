/*
这是一个有趣的故事。
详见hzwer博客。
可怜的zky
orz hzwer
要么路径压缩，要么启发合并
写哪个好呢，路径压缩吧。
这个空间有点难算
姑且当成nlognlogn吧
好吧这样数组开不下，尽量开吧 
好吧真被卡内存了。那就启发合并算了，随机合并也不错 
启发 1.2s,随机+路径压缩2s 

*/
#include<cstdio>
#include<cstdlib>
#define N 200005
#define XDS 12000005
using namespace std;
inline void swap(int &a,int &b){
	int t=a;a=b;b=t;
}
inline int read(){
	char c=getchar();int r=0;
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') r=r*10+c-'0',c=getchar();
	return r;
}
int n,m,root[N],cnt;
const int L=0,R=1;
//-------------------
int son[XDS][2],val[XDS],fr[XDS],to[XDS];
inline void build(int &k,int st,int en){
    k=++cnt;fr[k]=st;to[k]=en;son[k][L]=son[k][R]=0;
    int mid=(st+en)>>1;
    if(st==en) val[k]=st;
    else build(son[k][L],st,mid),build(son[k][R],mid+1,en);
}
inline int a(const int &k,int x){//query
    if(fr[k]==to[k]) return val[k];
    if(x<=((fr[k]+to[k])>>1)) return a(son[k][L],x);
    else return a(son[k][R],x);
}
inline void ch(int &k,int x,int y){
	int f=++cnt;fr[f]=fr[k];to[f]=to[k];son[f][L]=son[k][L];son[f][R]=son[k][R];
    if(fr[k]==to[k]){
        val[f]=y;
    }else{
        int mid=(fr[k]+to[k])>>1;
        if(x<=mid) ch(son[f][L],x,y);
        else ch(son[f][R],x,y);
    }
    k=f;
}
inline int ff(int vis,int x){
    int buf=a(root[vis],x);
    if(buf==x) return x;
    int t=ff(vis,buf);
    ch(root[vis],x,t);
    return t;
}
inline void connect(int vis,int x,int y){//干脆随机合并算了
    if(rand()&1) swap(x,y);
    int x1=ff(vis,x);int y1=ff(vis,y);
    if(x1==y1) return;ch(root[vis],x1,y1);
}
inline bool toge(int vis,int x,int y){
    int x1=ff(vis,x);int y1=ff(vis,y);
    return x1==y1;
}
//-------------------
int main(){//等等有点不对，我没有解密但A过了 
	n=read();m=read(); 
	build(root[0],1,n);
    for(int i=1,last=0,ins,a,b;i<=m;i++){
		ins=read();
        if(ins==1){
            a=read();b=read();
            root[i]=root[i-1];
            connect(i,a,b);
        }else if(ins==2){
        	a=read();
            root[i]=root[a];
        }else{
        	a=read();b=read();
            root[i]=root[i-1];
            if(toge(i,a,b)) puts("1");
            else puts("0");
        }
    }
	return 0;
}  
