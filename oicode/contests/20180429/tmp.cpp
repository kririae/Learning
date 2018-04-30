#include <cstdio>
#include <cctype>
const int BufferSize=1<<16;
char buffer[BufferSize],*_head,*_tail;
inline char GET_CHAR(){
	if(_head==_tail){
		int l=fread(buffer,1,BufferSize,stdin);
		_tail=(_head=buffer)+l;
		if(_head==_tail)return EOF;
	}
	return *_head++;
}
inline int READ(){
	int x=0,f=1;char c=GET_CHAR();
	for(;!isdigit(c);c=GET_CHAR()){
		if(c==EOF)return EOF;
		if(c=='-')f=-1;
	}
	for(;isdigit(c);c=GET_CHAR())x=(((x<<2)+x)<<1)+c-'0';
	return x*f;
}
int que[1000005],head,tail;
int main(){
	freopen("blue.in", "r", stdin);
	freopen("blue.out", "w", stdout);
	int a,n,m,D,L,T;int flag;
	for(T=READ();T--;){
		head=tail=0;flag=2;
		n=READ();m=READ();D=READ();L=READ();
		for(int i=1;i<=n;i++){
			a=READ();
			if(flag==2){
				if(a<=D)que[tail++]=a;
				else {
					flag=1;
					goto fst;
				}
			}else if(flag==1){
				fst:
				while(head<tail&&a-que[head]>D)head++;
				if(head==tail)flag=0;
				else {
					que[tail++]=a;
					head++;
				}
			}
		}
		while(head<tail&&L-que[head]>D)head++;
		if(flag==2||tail-head>=m)printf("Excited\n");else printf("%d\n",tail-head); 
	}
} 
