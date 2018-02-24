#include<cstdio>
#include<queue>
#define N 105
using namespace std;
/*
石子合并的最小值不可以这么做
最大值也不行
4 17 4 6 2 
*/
int shizi[N];
int xiao[N];
int n,ansx=0,ansd=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&shizi[i]);
		xiao[i]=shizi[i];
	}
	for(int i=1;i<n;i++){
		int min=1e7+1,p=0;
		for(int j=1;j<=n-i;j++){
			if(xiao[j]+xiao[j+1]<min){
				min=xiao[j]+xiao[j+1];
				p=j;
			}
		}
		xiao[p]=xiao[p]+xiao[p+1];
		ansx+=xiao[p];
		xiao[p+1]=-1; 
		int cnt=1;
		for(int j=1;j<=n-i+1;j++){
			if(xiao[j]!=-1){
				xiao[cnt++]=xiao[j];
			}
		}
	}
	printf("%d\n",ansx);
}
