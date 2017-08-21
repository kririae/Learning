#include <iostream>
#include <cstdio>
using namespace std;
int fb(int index){
    if(index == 1) return 0;
    if(index == 2) return 1;
    return fb(index-1)+fb(index-2);
}
int main() {
    int n;
    cin>>n;
    cout<<fb(n);
    return 0;
}