// by kririae
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstdlib>
#include <algorithm>

using namespace std;

inline void read(int &x)
{
    x = 0;
    int f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-')f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    x *= f;
}

template<typename T>
inline T maxx(T a, T b) { return a > b ? a : b; };
template<typename T>
inline T minx(T a, T b) { return a > b ? a : b; };

struct cow {
    int id, l, r, basic;
    cow() {}
    cow(int a, int b, int c): basic(a), l(b), r(c) {}
};

inline bool comp1(cow a, cow b) {
    return a.l == b.l ? a.r < b.r : a.l < b.l;
}

inline bool comp2(cow a, cow b) {
    return a.basic <= b.basic;
}

struct p {
    int a, b;
    p() {}
    p(int x, int y): a(x), b(y) {}
    bool operator < (const p &val) const {
        return a > val.a;
    }
};

const int maxn = 5e4 + 5;
int n, cnt = 0;
int ai, bi;
int res = 0;
cow init[maxn];
priority_queue<p> stall; // end_time, id

int main() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(ai); read(bi);
        init[i] = cow(i, ai, bi);
    }
    sort(init + 1, init + 1 + n, comp1); 
    stall.push(p(init[1].r, 1));
    init[1].id = 1;
    ++cnt;
    for (int i = 2; i <= n; ++i) {
        if(stall.size() >= 1) {
            p f = stall.top();
            if(f.a < init[i].l) { 
                stall.pop();
                init[i].id = f.b;
                f.a = init[i].r;
                stall.push(f);
            }
            else {
                ++cnt;
                stall.push(p(init[i].r, cnt)); 
                init[i].id = cnt;
                res = maxx(res, cnt);
            }
        }
    }
    cout << res << endl;
    sort(init + 1, init + 1 + n, comp2);
    for (int i = 1; i <= n; ++i) {
        cout << init[i].id << endl;
    }
    return 0;
}