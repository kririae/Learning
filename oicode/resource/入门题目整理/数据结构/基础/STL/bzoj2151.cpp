//Á´±í+¶Ñ
#include<cstdio>
#include<queue>
#define N 200005
using namespace std;
int n,m;
struct chain{
	int pre,ne,val;
}a[N];
struct nn{
	int val,x;
	inline bool operator <(const nn &b)const{
		return val<b.val;
	}
};
priority_queue<nn> pq;
int main(){
	scanf("%d%d",&n,&m);
	if(m>(n/2)) {printf("Error!");return 0;}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].val);
		a[i].pre=i-1;
		a[i].ne=i+1;
		pq.push((nn){a[i].val,i});
	}
	a[1].pre=n;a[n].ne=1;
	long long ans=0;
	for(int i=1;i<=m;i++){
		while(a[pq.top().x].val==-9999) pq.pop();
		nn v=pq.top();pq.pop();
		ans+=v.val;int l=a[v.x].pre,r=a[v.x].ne;
		a[a[l].pre].ne=v.x;a[v.x].pre=a[l].pre;
		a[v.x].ne=a[r].ne;a[a[r].ne].pre=v.x;
		a[v.x].val=v.val=a[l].val+a[r].val-v.val;
		a[l].val=-9999;a[r].val=-9999;
		pq.push(v);
	}
	printf("%lld\n",ans);
	return 0;
} 
