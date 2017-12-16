/*
既然河北省选出题偏了就不要
浪费时间，还是来写一下线段树
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#define N 200005
#define db double
#define eps 1e-7
#define INF 1e9+100
using namespace std;
struct point {
    db x,y;
};
point operator -(const point &p1,const point &p2){
    return (point){p1.x-p2.x,p1.y-p2.y};
}
point operator +(const point &p1,const point &p2){
    return (point){p1.x+p2.x,p1.y+p2.y};
}
struct seg{
    point p1,p2;//p2 is on the left
};
bool equ(double a,double b){
    return fabs(a-b)<eps;
}
double get_inter(const seg& x,int xx){
    if(equ(x.p1.x,x.p2.x)) return max(x.p1.y,x.p2.y);
    long double p=(long db)(xx-x.p2.x)/(long db)(x.p1.x-x.p2.x);
    return (x.p1.y-x.p2.y)*p+x.p2.y;
}
//------------------------------------------------
struct xds{
    int fr,to;
    int son[2];
    int seg_num;
}a[N];
seg segment[N];
int cnt,segcnt;
const int L=0,R=1;
void build(int &k,int fr,int to){
    k=++cnt;a[k].fr=fr;a[k].to=to;a[k].seg_num=INF;
    if(fr==to) return;
    int mid=(fr+to)>>1;
    build(a[k].son[L],fr,mid);build(a[k].son[R],mid+1,to);
}
inline bool addseg(int num,int k){
    if(a[k].seg_num==INF){a[k].seg_num=num;return true;}
    db ya1,ya2,yb1,yb2;
    ya1=get_inter(segment[a[k].seg_num],a[k].fr);
    ya2=get_inter(segment[a[k].seg_num],a[k].to);
    yb1=get_inter(segment[num],a[k].fr);
    yb2=get_inter(segment[num],a[k].to);
    if(equ(ya1,yb1)&&equ(ya2,yb2)) {a[k].seg_num=min(a[k].seg_num,num);return true;}
    if(ya1>yb1-eps&&ya2>yb2-eps) return true;
    if(ya1-eps<yb1&&ya2-eps<yb2) {a[k].seg_num=num;return true;}
    return false;
}
void insert(int k,int sgn){
    seg &sg=segment[sgn];
    if(sg.p2.x-eps>a[k].to||sg.p1.x+eps<a[k].fr) return;
    if(sg.p2.x-eps<a[k].fr&&sg.p1.x+eps>a[k].to){
        if(addseg(sgn,k)) return;
    }
    insert(a[k].son[L],sgn);
    insert(a[k].son[R],sgn);
}
int query(int k,int v){
    if(a[k].fr==a[k].to) return a[k].seg_num;
    int mid=(a[k].fr+a[k].to)>>1;
    int s=v<=mid? L:R;
    int buf=query(a[k].son[s],v);
    if(a[k].seg_num==INF) return buf;
    if(buf==INF) return a[k].seg_num;
    int ret=a[k].seg_num;
    double ya,yb;
    ya=get_inter(segment[ret],v);
    yb=get_inter(segment[buf],v);
    if(equ(ya,yb)) return min(buf,ret);
    return ya<yb? buf:ret;
}
//------------------------------------------------
int n;
int main(){
    scanf("%d",&n);
    int root,lastans=0;
    build(root,1,39990);
    for(int i=1;i<=n;i++){
        int ins,v;
        scanf("%d",&ins);
        if(ins==1){
            int xx1,xx2,yy1,yy2;//yy yy...
            scanf("%d%d%d%d",&xx1,&yy1,&xx2,&yy2);
            xx1=(xx1+lastans-1)%39989+1;
            xx2=(xx2+lastans-1)%39989+1;
            yy1=(yy1+lastans-1)%(1000000000)+1;
            yy2=(yy2+lastans-1)%(1000000000)+1;
            if(xx1<xx2) swap(xx1,xx2),swap(yy1,yy2);
            segment[++segcnt]=(seg){(point){xx1,yy1},(point){xx2,yy2}};
            insert(root,segcnt);
        }else if(ins==0){
            scanf("%d",&v);
            v=(v+lastans-1)%39989+1;
            lastans=query(root,v);
            if(lastans==INF) lastans=0;
            printf("%d\n",lastans);
        }
    }
    return 0;
}
