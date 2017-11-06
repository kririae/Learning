/ Created by 34189 on 2017/7/25.
//
#include<iostream>
#include<cstdio>
int main() {
    using namespace std;
    int n,f=1;
    double sum=0;
    cin>>n;
    for (double i = 1; i <= n; ++i) {
        sum+=f*(1.0/i);
        f=-f;
    }
    printf("%.4lf",sum);
}
