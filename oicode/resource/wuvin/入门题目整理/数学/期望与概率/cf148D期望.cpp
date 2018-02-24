#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
double psb[2][1005][1005];//turn 0 1 white black
int b,w;
double win;
struct sta{int t,w,b;};
queue<sta> que;
int main(){
	cin>>w>>b;
	psb[0][w][b]=1;	//记忆化DP 老鼠只数相同时 经过的次数相同 
	que.push((sta){0,w,b});
	while(!que.empty()){
		sta u=que.front();que.pop();
		double &p=psb[u.t][u.w][u.b];if(p==-1) continue;
		if(u.t==0){
			if(u.w==0) continue;
			win+=p*(u.w/(double)(u.w+u.b));
			if(u.b-1>=0)psb[1][u.w][u.b-1]+=p*(u.b/(double)(u.w+u.b)),que.push((sta){1,u.w,u.b-1});
		}else{
			if(u.w+u.b<=2) continue;//fail 
			if(u.b-1>=0&&u.w-1>=0){
				psb[0][u.w-1][u.b-1]+=p*(u.b/(double)(u.w+u.b))*(u.w/(double)(u.w+u.b-1)),que.push((sta){0,u.w-1,u.b-1});
			}
			if(u.b>=2) psb[0][u.w][u.b-2]+=p*(u.b/(double)(u.w+u.b))*((u.b-1)/(double)(u.w+u.b-1)),que.push((sta){0,u.w,u.b-2});
		}
		p=-1;
	}
	printf("%.9lf",win);
	return 0;
}
