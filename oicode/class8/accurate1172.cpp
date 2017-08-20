#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct accurate{
    int length;
    int value[50000];
    accurate(){
        memset(value,0,sizeof(value));
    }
};
char a[50000];
void load(accurate &value){
    gets(a);
    value.length = strlen(a);
    for (int i = 0; i < value.length; ++i) {
        value.value[value.length-i-1] = a[i]-'0';
    }
}
accurate sub(accurate a,accurate b){
    accurate c;
    int length = a.length>b.length?a.length:b.length;
    for (int j = 0; j < length ; ++j) {
        if(a.value[j]<b.value[j]){
            a.value[j]+=10;
            a.value[j+1]-=1;
        }
        c.value[j]=a.value[j]-b.value[j];
    }
    while (c.value[length-1]==0&& length>1 ) --length;
    c.length = length;
    return c;
}
accurate multi(accurate a, accurate b){
    accurate c;
    for (int i = 0; i < a.length; ++i)
        for (int j = 0; j < b.length; ++j) {
            int res =  a.value[i] * b.value[j];
            if (res >= 10) {
                c.value[i + j + 1] += res / 10;
                c.value[i + j] += res%10;
            }
            else c.value[i + j] += res;

        }
    for (int k = 0; k < a.length ; ++k) {
        for (int i = 0; i < b.length; ++i) {
            if(c.value[k+i]>=10) {
                c.value[k+i+1] += c.value[k+i]/10;
                c.value[k+i] %=10;
            }
        }
    }
    c.length=a.length+b.length;
    while(c.value[c.length-1] == 0 && c.length > 1)
        --c.length;
    return c;
}
int convert(accurate a){
    int num;
    int x = 1;
    for (int j = a.length-1; j >= 0; --j) {
        num += (a.value[a.length-j-1])*x;
        x *= 10;
    }
    return num;
}
int main(){
    accurate a,b,c;
    load(a);
    int num_a = convert(a);
    accurate one;
    one.value[0] = 1;one.length = 1;
    c = one;
    for (int j = 0; j < num_a; ++j) {
        c = multi(c, a);
        a = sub(a,one);
    }
    for (int i = c.length-1; i >= 0 ; --i) {
        printf("%d",c.value[i]);
    }
}