#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[n][m];
    int c[m][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d",&a[i][j]);
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < m; ++i) {
            c[i][k]=a[k][i];
        }
    }
    for (int l = 0; l < m; ++l) {
        for (int i = n-1; i >= 0; --i) {
            cout<<c[l][i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}