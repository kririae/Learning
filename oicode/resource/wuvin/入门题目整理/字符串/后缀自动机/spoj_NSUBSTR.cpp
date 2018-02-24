#include<cstdio>
#include<iostream>
#include<cstring>
#define N 500005
using namespace std;
/*
总共260ms 
*/
int n;char s[N];
struct node{
	int len,par,times;
	int ne[30];
}sam[N];
int cnt,last,root;
void build(){
	last=root=++cnt;int w,nw,ch,k,lca;
	for(int i=1;i<=n;i++){
		w=last;ch=s[i]-'a';last=nw=++cnt;sam[nw].len=i;
		while(w&&sam[w].ne[ch]==0) sam[w].ne[ch]=nw,w=sam[w].par;
		if(w!=0){
			k=sam[w].ne[ch];
			if(sam[k].len!=sam[w].len+1){
				lca=++cnt;sam[lca]=sam[k];
				sam[lca].len=sam[w].len+1;
				sam[k].par=sam[nw].par=lca;
				while(w&&sam[w].ne[ch]==k) sam[w].ne[ch]=lca,w=sam[w].par;
			}else sam[nw].par=k;
		}else sam[nw].par=root;
	}
}
int tp[N];
int px[N];
void pre(){//处理每个节点的right数组的大小 
	//-----处理拓扑序-
	for(int i=1;i<=cnt;i++) px[sam[i].len]++;
	for(int i=1;i<=cnt;i++) px[i]+=px[i-1];
	for(int i=cnt;i>=1;i--) tp[px[sam[i].len]--]=i;
	//---------------这次是主链置1
	for(int i=root,j=1;j<=n;j++){
		i=sam[i].ne[s[j]-'a'];
		sam[i].times=1;
	}
	//for(int i=last;i;i=sam[i].par) sam[i].times=1;
	//---------------
	for(int i=cnt;i>=1;i--) sam[sam[tp[i]].par].times+=sam[tp[i]].times;
}
int out[N];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	build();
	pre();
	//------------------
	for(int i=1;i<=cnt;i++){
		int t=sam[i].len;
		out[t]=max(out[t],sam[i].times);
	}
	for(int i=n;i>=1;i--) out[i]=max(out[i],out[i+1]);
	for(int i=1;i<=n;i++) printf("%d\n",out[i]);
	return 0;
}
