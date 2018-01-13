#include<cstdio>
using namespace std;
int st[500005];int cnt,n;
long long ans;
int times[500005];//相同升高合并 
inline void push(int &c){
	st[cnt++]=c;
}
inline void pop(){
	cnt--;
}
int main(){
	cnt=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int t;
		scanf("%d",&t);
		while(cnt!=0&&st[cnt-1]<t){
			ans+=times[cnt-1];
			pop();
		}
		if(cnt==0){
			push(t);
			times[cnt-1]=1;
		}else if(st[cnt-1]==t){
			ans+=times[cnt-1];
			times[cnt-1]++;
			if(cnt!=1){
				ans++;
			}
		}else{
			ans++;
			push(t);
			times[cnt-1]=1;
		}
	}
	printf("%lld",ans);
	return 0;
} 
