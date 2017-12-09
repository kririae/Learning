#include<cstdio>
#include<iostream>
#include<cstdlib>
/*
实际上我已经忘了堆该怎么写了
当然就只有像树一样写了。
至于插入，为了防止被卡成链，加个随机就对了。（其实可以科学一点统计size）
至于删除类似，为了防空，每个堆初始化时有一个INF
至于合并，据说有递归合并的方法，但我当初没仔细看。
只有脑补一下，去除两个堆最小的元素保留最小的作为根，
连接两边的堆，另一个就只有直接插入了。
第一次脑抽加了10^6个INF防止挂掉（事实证明没有用），T了
删掉，A了
貌似这个脑补的比左偏块一点

既然如此肯定还能优化，del操作并不一定要落实，下个10层后打个标记 
事实证明，由于logn本来就比较小最多也就十几，所以并没有什么用 

加了足量inline，少了100ms，误差范围以内 
*/
#define INF 99999999
#define DEEP 3
#define N 2000005 //10^6  我感觉我logn的堆要挂，费波拉契堆？我不会。。
using namespace std;
const int L=0,R=1;//小根堆
int n,m,cnt;
int root[N],son[N][2],deleted[N];
struct person{
    int mark,name;
    inline bool operator <(const person &b){
    	if(name==0||b.name==0) return name>b.name;
        return mark<b.mark;
    }
}val[N];
bool died[N];
inline void insert(int &k,person &val_){
    if(k==0){
        k=++cnt;son[k][L]=son[k][R]=0;val[k]=val_;
    }else{
        if(val_<val[k]) swap(val_,val[k]);
        insert(son[k][(rand()&(1<<2))>>2],val_);
    }
}
inline void del(const int &k,int deep){
    if(val[k].name==0) return;
    if(deep<=0&&deleted[k]==false){
    	deleted[k]=true;return;
	}
	int s=val[son[k][L]]<val[son[k][R]]? L:R;
	if(deleted[son[k][s]]) deleted[son[k][s]]=false,del(son[k][s],DEEP);
	s=val[son[k][L]]<val[son[k][R]]? L:R;
    val[k]=val[son[k][s]];
	del(son[k][s],deep-1);
}
//貌似还需要一个bcj
int bcj[N];
inline int ff(int k){
	return bcj[k]=(bcj[k]==k)? k:ff(bcj[k]);
}
inline void connect(int a,int b){//a->b
    bcj[ff(a)]=ff(b);
}
inline void merge(int a,int b){//合并以ab为根的bcj
    a=ff(a);b=ff(b);
    if(!(val[root[a]]<val[root[b]])) swap(a,b); //_a为根
    person t=val[root[a]];del(root[a],DEEP);
    int k=++cnt;son[k][L]=root[a];son[k][R]=root[b];val[k]=t;root[a]=k;
    connect(b,a);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        bcj[i]=i;//insert(root[i],(person){INF,0});貌似不用防止访问空节点，不然相当于数据量翻一倍，会T 
    }
    for(int i=1;i<=n;i++){
        int t;scanf("%d",&t);
        person buf=(person){t,i};
        insert(root[i],buf);
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        char c=getchar();while(c==' '||c=='\n'||c=='\r') c=getchar();
        if(c=='M'){
            int a,b;scanf("%d%d",&a,&b);
            if(died[a]==false&&died[b]==false){
                merge(a,b);
            }
        }else{
            int a;scanf("%d",&a);
            if(died[a]==false){
                a=ff(a);
                printf("%d\n",val[root[a]].mark);
                died[val[root[a]].name]=true;
                del(root[a],DEEP);
            }else{
                puts("0");
            }
        }
    }
    return 0;
}
