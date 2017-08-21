#include <iostream>
#include <cstdio>
using namespace std;
char n[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
char res[100];
int i = 0;
void convert(int digit,int num){
    if(digit>0){res[i] = n[digit%num];++i;convert((digit-(digit%num))/num,num);}
}
int main() {
    int n,m;
    cin>>n>>m;
    convert(n,m);
    for (int j = i-1; j >= 0 ; --j)
        cout<<res[j];
    return 0;
}