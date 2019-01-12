#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>
 
#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
 
#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
 
int IN(){
    int c,f,x;
    while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
    while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}
 
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;
 
const int N=1000+19;
 
struct Edge{
    int y,nxt;
} E[N*2];
int Last[N],S[N],bel[N],rt[N];
int n,cnt,B,tot,num;
 
void Link(int x,int y){
    E[cnt]=(Edge){y,Last[x]};Last[x]=cnt++;
    E[cnt]=(Edge){x,Last[y]};Last[y]=cnt++;
}
void dfs(int x,int fa){
    int tmp=tot;
    for (int i=Last[x],y;~i;i=E[i].nxt)
        if ((y=E[i].y)!=fa){
            dfs(y,x);
            while (tot-tmp>=B){
                rt[++num]=x;
                while (tot!=tmp) bel[S[tot--]]=num;
            }
        }
    S[++tot]=x;
}
 
int main(){
    memset(Last,-1,sizeof(Last));
    n=IN(),B=IN();
    For(i,1,n) Link(IN(),IN());
    dfs(1,-1);
    while (tot) bel[S[tot--]]=num;
    printf("%d\n",num);
    For(i,1,n+1) printf("%d ",bel[i]);puts("");
    For(i,1,num+1) printf("%d ",rt[i]);puts("");
}
