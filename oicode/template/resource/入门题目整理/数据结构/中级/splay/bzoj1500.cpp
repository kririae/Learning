#include<cstdio>
#include<iostream> 
#include<stack>
#define N 1050005
#define INF 99999999
using namespace std;
const int L=0,R=1;
inline int read(){
   	int x=0;char c=getchar();int f=1;
   	while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
   	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();return x*f;
}
//-----------splay-------------
struct node{
    int son[2],fa,val;
    int size,sum,lseq,rseq,mseq;//需要被update的
    int c_tag,t_tag;//需要被pushdown的。
}a[N];
int n,m,cnt,root;
stack<int> sta; 
//看来必须要内存回收了。 
inline int get(){
	if(cnt<1050000) return ++cnt;
	int b=sta.top();sta.pop();return b;
}
void pick(int k){//捡垃圾 
	sta.push(k);
	if(a[k].son[L]!=0) pick(a[k].son[L]);
	if(a[k].son[R]!=0) pick(a[k].son[R]);
}

void printf_tree(int k){
	if(a[k].son[L]!=0) printf("%d %d\n",k,a[k].son[L]),printf_tree(a[k].son[L]);
	if(a[k].son[R]!=0) printf("%d %d\n",k,a[k].son[R]),printf_tree(a[k].son[R]);
}
//-----------------------------
inline void swa(int k){
	if(k==0) return;
	swap(a[k].son[L],a[k].son[R]);
	swap(a[k].lseq,a[k].rseq);
}
inline void make_same(int k,int c){
	a[k].sum=a[k].size*c;a[k].c_tag=c;
    a[k].lseq=a[k].rseq=a[k].mseq=max(c,a[k].sum);a[k].val=c;
}
inline void pushdown(int k){
    if(k==0) return;
    if(a[k].son[L]+a[k].son[R]==0){a[k].t_tag=0;a[k].c_tag=-INF;return;}
    if(a[k].t_tag==1){
        a[a[k].son[L]].t_tag^=1;a[a[k].son[R]].t_tag^=1;
        swa(a[k].son[L]);swa(a[k].son[R]);
        a[k].t_tag=0;
    }
    if(a[k].c_tag!=-INF){
        if(a[k].son[L]!=0) make_same(a[k].son[L],a[k].c_tag );//最大字段和不能为空
        if(a[k].son[R]!=0) make_same(a[k].son[R],a[k].c_tag );
        a[k].c_tag=-INF;
    }
}
inline void update(int k){
    if(k==0) return;
    a[k].size=1;a[k].sum=a[k].val;a[k].lseq=a[k].rseq=a[k].mseq=a[k].val;
	if(a[k].son[L]!=0){
		node& l=a[a[k].son[L]];
		a[k].mseq=max(a[k].mseq,max(l.mseq,a[k].lseq+l.rseq));
		a[k].lseq=max(l.lseq,l.sum+a[k].lseq);
		a[k].rseq=max(a[k].rseq,a[k].sum+l.rseq);
		a[k].sum+=l.sum;a[k].size+=l.size;
	}
    if(a[k].son[R]!=0){
    	node& r=a[a[k].son[R]];
    	a[k].mseq=max(a[k].mseq,max(r.mseq,a[k].rseq+r.lseq));
		a[k].rseq=max(r.rseq,r.sum+a[k].rseq);
    	a[k].lseq=max(a[k].lseq,a[k].sum+r.lseq);
    	a[k].size+=r.size;a[k].sum+=r.sum;
	}
}
inline void rotate(const int &x,int &k){
    int y=a[x].fa;int z=a[y].fa;
    int s=a[y].son[R]==x;
    a[y].son[s]=a[x].son[s^1];a[a[x].son[s^1]].fa=y;
    a[x].son[s^1]=y;a[x].fa=a[y].fa;a[y].fa=x;
    if(y==k) k=x;
    else a[z].son[a[z].son[R]==y]=x;
    update(y);
}
inline void splay(int x,int &k){
	int y,z;
    while(x!=k){//printf_tree(root);
        y=a[x].fa;z=a[y].fa;pushdown(a[z].fa);pushdown(z);pushdown(y);pushdown(x);
        if(y!=k){
            if((a[z].son[R]==y)^(a[y].son[R]==x)) rotate(x,k);
            else rotate(y,k);
        }
        rotate(x,k);
    }
    update(x);
}
inline int kth(int k,int x){
    while(1){
        pushdown(k);
        int t=a[a[k].son[L]].size+1;
        if(t==x) return k;
        if(t>x){k=a[k].son[L];continue;}
        else{k=a[k].son[R];x-=t;continue;}
    }
}
inline int get(int l,int r){
    l=kth(root,l);r=kth(root,r+2);
    splay(l,root);splay(r,a[root].son[R]);
    return a[r].son[L];
}
void build(int &k,int l,int r,int fr,const int* buf){
    k=get();a[k].size=r-l+1;a[k].fa=fr;a[k].c_tag=-INF;a[k].t_tag=0; 
    int mid=(l+r)>>1;a[k].val=buf[mid];a[k].son[L]=a[k].son[R]=0;
    if(l==r){}
    else if(l+1==r){build(a[k].son[R],r,r,k,buf);}
    else{build(a[k].son[L],l,mid-1,k,buf);build(a[k].son[R],mid+1,r,k,buf);}
    update(k);return;
}
inline void pre(){
    a[0].val=-INF;a[0].lseq=-INF;a[0].rseq=-INF;a[0].mseq=-INF;
}
//-----------------------------
int buf[N];
int main(){
    pre();
    n=read();m=read();
    for(int i=1;i<=n;i++){
        scanf("%d",&buf[i]);
    }
    buf[0]=buf[n+1]=-INF;
    build(root,0,n+1,0,buf);
    for(int i=1;i<=m;i++){
        char ins[20];int p,t,st;
        scanf("%s",ins);
        if(ins[2]=='S'){
            p=read();t=read(); 
            for(int j=1;j<=t;j++){
                buf[j]=read();
            }
            int poi=0;
            build(poi,1,t,0,buf);
            get(p+1,p);
            a[poi].fa=a[root].son[R];
            a[a[root].son[R]].son[L]=poi;
        }else if(ins[2]=='L'){
            p=read();t=read(); 
            int k=get(p,p+t-1);a[a[k].fa].son[L]=0;
            a[k].fa=0;pick(k);
        }else if(ins[2]=='K'){
            p=read();t=read();st=read();
            int k=get(p,p+t-1);
            make_same(k,st);
        }else if(ins[2]=='V'){
            p=read();t=read(); 
            int k=get(p,p+t-1);a[k].t_tag^=1;
            swa(k);
        }else if(ins[2]=='T'){
            p=read();t=read(); 
            int k=get(p,p+t-1);
            printf("%d\n",a[k].sum);
        }else if(ins[2]=='X'){
            printf("%d\n",a[root].mseq);
        }
        update(a[root].son[R]);update(root);
    }
    return 0;
}
