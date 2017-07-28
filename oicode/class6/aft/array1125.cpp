#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int a[n][m],b[m][k],c[n][k];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%d",&a[i][j]);
    for (int l = 0; l < m; ++l)
        for (int i = 0; i < k; ++i)
            scanf("%d",&b[l][i]);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            c[i][j]=0;
            for (int h = 0; h < m; ++h) {
                c[i][j] += a[i][h] * b[h][j];
            }
        }
    }
    for (int j1 = 0; j1 < n; ++j1) {
        for (int i = 0; i < k; ++i) {
            cout<<c[j1][i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}