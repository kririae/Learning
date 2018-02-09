/*
转化为两个                                                                                                                                                                                                                                                                                                                  问题:
求一个最大子段和，长度不限
求一个最大子段和，长度不小于L
 */
#include <bits/stdc++.h>
namespace solve
{

template<typename T>
inline void read(T &val)
{
    val = 0; int f = 1;
    char ch = getchar();
    while(!isdigit(ch)) {
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(isdigit(ch)) {
        val = val * 10 + ch - '0';
        ch = getchar();
    }
    val *= f;
}

const int maxn = 1e5 + 5;
int n, f;
unsigned int fields[maxn];
unsigned int addup[maxn];
inline void init()
{
    read(n); read(f);
    for (register int i = 1; i <= n; ++i) 
        read(fileds[i]); // init the 
    
}

inline void solve() 
{

}
}

int main() 
{
    solve::solve();
    return 0;
}