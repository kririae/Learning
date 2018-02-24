//这个该是队列的启发式合并
//就是对于短的每一个检查是否+1或-1的位置不对 
#include<cstdio>
#include<vector>
#define N 1000005
using namespace std;
int color[N];
int n,m,ans;
vector<int> ys[N];
int ran[N];//对于某种颜色到达该染什么 
//-----------------------
void merge(int a,int b){
	int aa=a,bb=b;bool sw=false;
	for(int i=0,len=ys[a].size();i<len;i++){
		int c=ys[a][i];
		if(color[c+1]==b) ans--;
		if(color[c-1]==b) ans--;
		ys[b].push_back(c);
	}
	for(int i=0,len=ys[a].size();i<len;i++)
		color[ys[a][i]]=b;
	ys[a].clear();
}


int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=1000000;i++) ran[i]=i;
	ans=n;color[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&color[i]);
		if(color[i]==color[i-1]) ans--;
		ys[color[i]].push_back(i);
	}
	for(int i=1,ins,a,b;i<=m;i++){
		scanf("%d",&ins);
		if(ins==1){
			scanf("%d%d",&a,&b);
			if(a==b) continue;
			if(ys[a].size()>ys[b].size()) swap(ran[a],ran[b]);
			merge(ran[a],ran[b]);
		}else if(ins==2){
			printf("%d\n",ans);
		}
	}	
	return 0;
} 
