#include<cstdio>
#define N 100005
#define ST static
/*wrong*/
using namespace std;
struct suffix_automatic{
	int par,len;
	int ne[30];
}sam[N];
char s[N];int n,cnt,root,last;
void add(){
	root=++cnt;last=root;
	for(int i=1;i<=n;i++){
		ST int ch,w,nw;ch=s[i]-'a';w=last;sam[nw=++cnt].len=sam[w].len+1;
		while(w&&(!sam[w].ne[ch])) sam[w].ne[ch]=nw,w=sam[w].par;
		if(w){
			ST int k;k=sam[w].ne[ch];
			if(sam[k].len==sam[w].len+1) sam[nw].par==k;
			else{
				ST int nk;sam[nk=++cnt]=sam[k];sam[nk].len=sam[w].len+1;sam[k].par=sam[nw].par=nk;
				while(w&&sam[w].ne[ch]==k) sam[w].ne[ch]=nk,w=sam[w].par;
			}
		}else sam[nw].par=root;
		last=nw;
	}
}
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	add();
	return 0;
} 
