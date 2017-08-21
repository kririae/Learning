#include <iostream>
#include <cstdio>
using namespace std;
int reverse(int digit){
    if(digit>=1){cout<<digit%10;reverse(digit/10);}
}
int main() {
    int n;
    cin>>n;
    reverse(n);
    return 0;
}