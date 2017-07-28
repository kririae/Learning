#include <iostream>
#include <cstdio>
using namespace std;
struct a{
    int value;
    int line,l;
};
int main(){
    int n[5][5];
    int count=0;
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            scanf("%d",&n[i][j]);
    a maxn,minn;
    for (int k = 0; k < 5; ++k) {
        maxn.value=n[k][0];maxn.line=k;maxn.l=0;
        //minn=n[0][k].value;
        for (int i = 0; i < 5; ++i)
            if(n[k][i]>maxn.value) {maxn.value=n[k][i];maxn.line=k;maxn.l=i;}
            //if(n[i][k].value<minn) {minn=n[i][k].value;n[i][k].line=i;n[i][k].l=k;}
        minn.value=n[0][maxn.l];minn.line=0;minn.l=0;
        for (int j = 0; j < 5; ++j) {
            if(minn.value>n[j][maxn.l]){minn.value=n[j][maxn.l];minn.line=k;minn.l=j;};
        }
        if(minn.value==maxn.value){
            cout<<k+1<<" "<<maxn.l+1<<" "<<maxn.value<<endl;
            count+=1;
        }
    }
    if(count==0) cout<<"not found";
    return 0;
}