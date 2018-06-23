#include<cstdio>
#include<algorithm>
#include<iostream>
/*
神奇的贪心
受限排序
以a代表长 b代表宽
若ai>aj && bi>bj
删除j
然后余下的数a单减b单增 
从左向右依次尝试合并（ai*bi+aj*bj>ai*bj）
如果不行就结束该块的合并
开始下一块合并
具体证明自己打下草稿就对了
(以上方法错误)
下面是错误样例
*/
using namespace std;
struct node{
	long long a,b;
	bool operator <(const node &c)const{
		if(a!=c.a)
			return a>c.a;
		else
			return b>c.b;
	}
}x[50005];
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x[i].a,&x[i].b);
	}
	sort(x+1,x+n+1);
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[i].b>=x[j].b){
				x[j].a=x[j].b=-1;
			}else{
				i=j-1;
				break;
			}
		}
	}
	int p1=1;
	for(int i=1;i<=n;i++){
		if(x[i].a!=-1){
			x[p1].a=x[i].a;
			x[p1].b=x[i].b;
			p1++;
		}
	}
	p1--;
	
	int sta=1;long long ans=0;
	for(int i=2;i<=p1;i++){
		if(x[i].a*x[i].b+x[sta].a*x[i-1].b>=x[sta].a*x[i].b){
			continue;
		}else{
			ans+=x[i-1].b*x[sta].a;
			sta=i;
			continue;
		}
	}
	ans+=x[sta].a*x[p1].b;
	//cout<<ans;
	printf("%lld",ans);
	return 0;
}
