//400+ms 800+k
#include <cstdio>
#include <cstring>
#define N 20005
int n,m,cnt,edgeNum;
int ans[N],col[N],head[N];
struct edge{int v,next;}edge[2*N];
void add(int a,int b){
    edge[edgeNum].v=b;
    edge[edgeNum].next=head[a];
    head[a]=edgeNum++;
}
bool dfs(int v){
    if(col[v]==2)
        return false;
    if(col[v]==1)
        return true;
    col[v]=1;
    col[v^1]=2;
    ans[cnt++]=v;
    for(int i=head[v];i!=-1;i=edge[i].next){
        if(!dfs(edge[i].v))
            return false;
    }
    return true;
}
bool solve(){
    memset(col,0,sizeof(col));
    for(int i=0;i<n;i++){
        if(col[i]) continue;
        cnt=0;
        if(!dfs(i)){
            for(int j=0;j<cnt;j++){
                col[ans[j]]=0;
                col[ans[j]^1]=0;
            }
            if(!dfs(i^1))
                return false;
        }
    }
    return true;
}
int main(){
    int a,b;
    while(scanf("%d%d",&n,&m)!=EOF){
        n=n<<1;
        edgeNum=0;
        memset(head,-1,sizeof(head));
        while(m--){
            scanf("%d%d",&a,&b);
            a--;
            b--;
            add(a,b^1);
            add(b,a^1);
        }
        if(solve()){
            for(int i=0;i<n;i++){
                if(col[i]==1)
                    printf("%d\n",i+1);
            }
        }
        else puts("NIE");
    }
    return 0;
}
