/*今天智商欠费，只好来学习*/
#include<cstdio>
#include<map>
#include<iostream>
#define N 5000005
using namespace std;
int miu[N],check[N];
int prime[N];int pcnt;
void pre(){
	miu[1]=1;
	for(int i=2;i<N;i++){
		if(check[i]==0)	miu[i]=-1,prime[++pcnt]=i;
		for(int j=1;i*prime[j]<N&&j<=pcnt;j++){
			miu[i*prime[j]]=-miu[i];check[i*prime[j]]=1;
			if(i%prime[j]==0) miu[i*prime[j]]=0;
		}
	}
	for(int i=2;i<N;i++) miu[i]+=miu[i-1];
}
//---记忆化------
map<long long,int> mp;
map<long long,int>::iterator itr;
int F(long long x){
	if(x<N) return miu[x];
	if((itr=mp.find(x))!=mp.end()) return (*itr).second;
	int ret=1;long long ne;
	for(long long i=2,t;i<=x;i=ne+1){
		ne=x/(t=x/i);
		ret-=(ne-i+1)*F(t);
	}
	mp[x]=ret;
	return ret;
}
int main(){
	pre();
	long long a,b;
	cin>>a>>b;
	cout<<F(b)-F(a-1)<<endl;
	return 0;
}
