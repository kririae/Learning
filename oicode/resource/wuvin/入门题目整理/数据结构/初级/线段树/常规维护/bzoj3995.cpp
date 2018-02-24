#include<cstdio>
#include<iostream>
#define N 60005
using namespcae std;
const int L=0,R=1,TOP=0,BUTT=1;
int wang[N*2][4];//0 <-left  1 ->right  2->oppsite
int c(int lie,int side){
    return 2*(lie-1)+side;
}
struct node{
    node* son[2];
    int fr,to;
    int dis[5];//左右两侧的连通关系
}a[N];
int update(int k){
    if(a[k].son[L]==0) return 0;
    int disup=wang[c(a[k].son[L]->to,TOP)][1];
    int disdown=wang[c(a[k].son[L]->to,BUTT)][1];
    a[k].dis[0]=min(disup+disdown+a[k].son[L]->dis[0]+a[k].son[R]->dis[0],
    min(disup,disdown)+a[k].son[L]->dis[2]+a[k].son[R]->dis[3]);
    a[k].dis[1]=min(min(disup,disdown)+a[k].son[L]->dis[1]+a[k].son[R]->dis[1],
    disup+dismin+min(a[k].son[L]->dis[0]+a[k].son[R]->dis[1],a[k].son[L]->dis[1]+a[k].son[R]->dis[0]));
    a[k].dis[2]=min(disup+a[k].son[L]->dis[0]+a[k].son[R]->dis[1],)
}
int main(){
    
    return 0;
}