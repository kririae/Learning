/*
Áô¿Ó 
*/
#include<cstdio>
#define LL unsigned int
#define N 10000007
using namespace std;
int read(int st,char *w){
    int p=st;char c=getchar();
    while(c=='\n'||c=='\r') c=getchar();
    while(c!='\n'&&c!='\r') w[p++]=c,c=getchar();
    return p;
}
char bufbuf,word[N];
int get(char c){
	if(c>='a'&&c<='z') return c-'a';
	if(c>='A'&&c<='Z') return c-'A'+26;
	if(c==' ') return 52;
}
//-------------------------
LL ans,root,cnt,ncnt;
LL neic[260000][53];
struct node{
	int st,en,size;
	LL *c;
}a[1500000];
void insert(LL &k,int st,int en,int f){
	if(st>en) return;
	if(k==0){
		k=++cnt;a[k].st=st;a[k].en=en;a[k].size=f;a[k].c=NULL;return;
	}
	if(a[k].c==NULL) a[k].c=neic[ncnt++];
	if(a[k].en-a[k].st!=0){
		insert(a[k].c[get(word[a[k].st+1])],a[k].st+1,a[k].en,a[k].size);
		a[k].en=a[k].st;
	}
	a[k].size+=f;
	insert(a[k].c[get(word[st+1])],st+1,en,f);
}
void DFS(int k,LL len){
	if(k==0) return;
	LL t=a[k].en-a[k].st+1+len;
	LL x=a[k].size*(t);
	ans=ans<x? x:ans;
	if(a[k].c==NULL) return;//pay attention
	for(int i=0;i<53;i++){
		/*ÕâÀïREÁË*/
		if(a[k].c[i]!=0) DFS(a[k].c[i],t);
	}
}
//-------------------------
int n;
int main(){
	scanf("%d",&n);int p=0;root=1;cnt=1; 
	for(int i=1;i<=n;i++){
		int m=read(p,word);
		insert(root,p-1,m-1,1);
		p=m;
	}
	DFS(root,-1);
	printf("%d",ans);
	return 0;
} 
