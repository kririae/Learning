#include<cstdio>
#include<queue>
#define N 305
#define W 1000005
#define M 26
using namespace std;
int word[W];
int read(int p,int *b){
	char c=getchar();
	while(c=='\n'||c=='\r') c=getchar();
	while(c>='a'&&c<='z') b[p++]=c-'a'+1,c=getchar();
	return p;
} 
//---------------------------
int root,n,cnt,buf;
int name2val[N];
struct node{
	int val,p;
	int ne[M+1];
}a[W];
void insert(int &k,int st,int en){
	if(k==0){
		k=++cnt;a[k].p=st;
	}
	a[k].val++;
	if(st==en) name2val[buf]=k;
	else insert(a[k].ne[word[st+1]],st+1,en);
}
int bufs[W],ccnt;
void pre(){
	queue<int> p;
	for(int i=0;i<=M;i++){
		if(a[root].ne[i]==0) a[root].ne[i]=1;
		else a[a[root].ne[i]].ne[0]=root,p.push(a[root].ne[i]);
	}
	while(!p.empty()){
		int u=p.front();p.pop();
		bufs[++ccnt]=u;
		for(int i=1;i<=M;i++){
			if(a[u].ne[i]==0) a[u].ne[i]=a[a[u].ne[0]].ne[i];
			else {a[a[u].ne[i]].ne[0]=a[a[u].ne[0]].ne[i];p.push(a[u].ne[i]);}
		}
	}
}
void DFS(int u){
	while(ccnt!=0){
		int u=bufs[ccnt];ccnt--;
		a[a[u].ne[0]].val+=a[u].val;
	}
}
//----------------------------------
int main(){
	root=1;cnt=1;
	scanf("%d",&n);int p=1;
	for(int i=1;i<=n;i++){
		buf=i;
		int t=read(p,word);
		insert(root,p-1,t-1);
		p=t;
	}
	pre();
	DFS(root);
	for(int i=1;i<=n;i++) printf("%d\n",a[name2val[i]].val);
	return 0;
} 
