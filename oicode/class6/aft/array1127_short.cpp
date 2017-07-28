#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[n][m];
    int c[m][n];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%d",&c[j][i]);
    for (int l = 0; l < m; ++l) {
        for (int i = n-1; i >= 0; --i)
            cout<<c[l][i]<<" ";
        cout<<endl;}
    return 0;
}