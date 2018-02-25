#include<cstdio>
#include<cstring>
#include<iostream>
#define N 100005
using namespace std;
//------------------
int n,cnt;
char s2[N+N];
struct hw{
	int len,fail;
	int ne[28];
	int times;
}h2[N+N];
//------------------------
void init(){
	scanf("%s",s2+1);
	n=strlen(s2+1);
	for(int i=1;i<=n;i++) s2[i]-='a'-1;
}
int ans=2;
int lft[N],rit[N];
void build(char *s,hw *h,int *pt){
	cnt=2;h[1].len=-1;h[1].fail=1;h[2].len=0;h[2].fail=1;int p=2;
	for(int i=1;i<=n;i++){
		while(s[i]!=s[i-h[p].len-1]) p=h[p].fail;
		if(h[p].ne[s[i]]){p=h[p].ne[s[i]];h[p].times++;pt[i]=h[p].len;continue;}
		int k=h[p].ne[s[i]]=++cnt;h[k].len=h[p].len+2;h[k].times=1;p=h[p].fail;
		//----update
		pt[i]=h[k].len;
		//----update
		if(h[k].len==1) {h[k].fail=2,p=k;continue;}
		while(s[i]!=s[i-h[p].len-1]) p=h[p].fail;
		h[k].fail=h[p].ne[s[i]];p=k;
	}
}
//------------------
int main(){
	init();
	build(s2,h2,lft);
	char *s3=&s2[N+1];
	for(int i=1;i<=n;i++) s3[n+1-i]=s2[i];
	build(s3,&h2[N+1],rit);
	for(int i=1;i<n;i++) ans=max(ans,lft[i]+rit[n-i]);
	printf("%d",ans);
	return 0;
}
