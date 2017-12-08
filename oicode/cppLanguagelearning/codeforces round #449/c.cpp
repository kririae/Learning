#include <bits/stdc++.h>
using namespace std;
int q;
typedef long long ll;
struct question {
    int n;
    int q;
    bool operator < (const question (&a)) const {
        if(this->n == a.n) { return this->q < a.q; }
        return this->n < a.n;
    }
} p[15];
// p1 What are you doing while sending " 34
// p2 What are you doing at the end of the world? Are you busy? Will you save us? 75
// p3 "? Are you busy? Will you send " 32
// p4 What are you doing at the end of the world? Are you busy? Will you save us? 75
// p5 "?" 3
inline int buildd(node a) {
    if(a.s5 >= k) {
        // TODO
    }
    node newone;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> p[i].n >> p[i].q;
    }
    sort(p, p + q);
    for (int i = 2; i <= n; ++i) {

    }
    return 0;
}