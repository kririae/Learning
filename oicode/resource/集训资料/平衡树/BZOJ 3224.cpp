#include<cstdio>
#include<cctype>
#include<algorithm>
 
#define For(i,x,y) for (int i=x;i<y;i++)
#define Rep(i,x,y) for (int i=x;i>y;i--)
#define Mid (L+R>>1)
#define CH isdigit(c=getchar())
using namespace std;
 
int IN()
{
    int c,f,x;
    while (!CH&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
    while (CH) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}
 
const double Alpha=0.75;
int n,v;
 
const int N=100000+19;
struct SGT *null;
struct SGT
{
    SGT *L,*R;
    int key,S,Sr,Del;
 
    void Update() {if (this!=null) S=L->S+R->S+1,Sr=L->Sr+R->Sr+!Del;}
    bool Balance() {return L->S<=S*Alpha&&R->S<=S*Alpha;}
} Nd[N],*S[N],*tmp[N],*RT;
int Tcnt,k,kt,f,Q,opt,x;
 
void Find(SGT *x)
{
    if (x==null) return;
    Find(x->L);if (!x->Del) tmp[++kt]=x;Find(x->R);
}
SGT *Build(int L,int R)
{
    if (L>R) return null;
    tmp[Mid]->L=Build(L,Mid-1),tmp[Mid]->R=Build(Mid+1,R);
    return tmp[Mid]->Update(),tmp[Mid];
}
void Ins(SGT *&x,int v)
{
    if (x==null) {x=Nd+(++Tcnt),*x=(SGT){null,null,v,1,1,0};return;}
    S[++k]=x,v<x->key?Ins(x->L,v):Ins(x->R,v);
}
void Insert(int v)
{
    k=0,Ins(RT,v);Rep(i,k,0) S[i]->Update();
    For(i,1,k+1)
        if (!S[i]->Balance())
        {
            f=(i>1&&S[i-1]->L==S[i]),kt=0,Find(S[i]);
            SGT *T=Build(1,kt);
            if (i==1) RT=T;else f?S[i-1]->L=T:S[i-1]->R=T;
            return;
        }
}
bool Del(SGT *x,int v)
{
    if (x==null) return 0;
    if (x->key==v&&!x->Del) {x->Del=1,x->Update();return 1;}
    return S[++k]=x,v==x->key?Del(x->L,v)||Del(x->R,v):Del(v<x->key?x->L:x->R,v);
}
void Delete(int v) {k=0,Del(RT,v);Rep(i,k,0) S[i]->Update();}
int Rank(SGT *x,int v)
{
    if (x==null) return 0;
    return v<x->key?Rank(x->L,v):Rank(x->R,v)+x->L->Sr+!x->Del;
}
int Findkth(SGT *x,int k)
{
    if (x->L->Sr+1==k&&!x->Del) return x->key;
    return k<=x->L->Sr+!x->Del?Findkth(x->L,k):Findkth(x->R,k-x->L->Sr-!x->Del);
}
 
int main()
{
    RT=null=Nd;
    Q=IN();
    while (Q--)
    {
        opt=IN(),x=IN();
        if (opt==1) Insert(x);
        if (opt==2) Delete(x);
        if (opt==3) printf("%d\n",Rank(RT,x-1)+1);
        if (opt==4) printf("%d\n",Findkth(RT,x));
        if (opt==5) printf("%d\n",Findkth(RT,Rank(RT,x-1)));
        if (opt==6) printf("%d\n",Findkth(RT,Rank(RT,x)+1));
    }
}
