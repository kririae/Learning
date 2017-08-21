#include "iostream"
#include "cstdio"
#include "cmath"
#include "cstring"
using namespace std;
struct high_precision{
    int length,value[101];
    high_precision(){memset(value,0,sizeof(value));}
};

void load(high_precision &input){
    char string[101];scanf("%s",string);
    while(string[0]=='0'&&strlen(string)>0)
        strcpy(string,&string[1]);
    int k = strlen(string),count=0;
    input.length=strlen(string);
    for (int i = input.length-1; i >= 0; --i) {
        input.value[count]=string[i]-48;count++;
    }
}

high_precision multi(high_precision a,high_precision b){
    high_precision c;
    for (int i = 0; i < a.length; ++i) {
        for (int j = 0; j < b.length; ++j) {
            c.value[i+j]+=a.value[i]*b.value[j];
            c.value[i+j+1]+=c.value[i+j]/10;
            c.value[i+j]%=10;
        }
    }
    if(c.value[a.length+b.length]==0)
        c.length=a.length+b.length-1;
    else
        c.length=a.length+b.length;
    return c;
}
int main() {
    high_precision a,b;
    load(a);load(b);
    high_precision c = multi(a,b);
    bool a_0=false,b_0=false;
    for (int j = 0; j < a.length; ++j)
        if(a.value[j]!=0) a_0=true;
    for (int j = 0; j < b.length; ++j)
        if(b.value[j]!=0) b_0=true;
    for (int i = c.length; i>=0; --i) {
        if(c.value[i]!=0){
            cout<<c.value[i];}
    }

    return 0;
}
/*
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
struct sd{
    int len,d[300];
    sd(){memset(d,0,sizeof(d));}
};

void readit(sd &x){
    char st[300];scanf("%s",st);
    while(st[300]=='0'&&strlen(st)>0){
        strcpy(st,&st[1]);
    }
    int j=0;
    for (int i = x.len-1; i >=0; ++i) {
        x.d[j]=st[i]-48;j++;
    }
}

sd cheng(sd a,sd b){
    sd c;
    for (int i = 0; i < a.len; ++i) {
        for (int j = 0; j < b.len; ++j) {
            c.d[i + j] = c.d[i + j] + a.d[i] * b.d[i];
            c.d[i + j + 1] += c.d[i + j] / 10;
            c.d[i + j] %= 10;
        }
        for (int k = 0; k < a.len + b.len - 1; ++k) {
            c.d[k + 1] = c.d[k + 1] + c.d[k] / 10;
            c.d[k] %= 10;
        }
        if (c.d[a.len + b.len] > 0) c.len = a.len + b.len;
        else c.len = a.len + b.len - 1;
        return c;
    }
}
int main(){
    sd a,b,c;
    readit(a);readit(b);
    c=cheng(a,b);
    for (int i = c.len-1; i>=0; --i) {
        cout<<c.d[i];
    }
    return 0;
}*/