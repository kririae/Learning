#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    for(int k = 0; k < n; ++k) {
        register int a = 1, b = 1, c = 1, r;
        cin >> r;
        for(register int i = 1; i < r - 1; ++i) {
            c = (a + b) % 1000;
            a = b;
            b = c;
        }
        cout << c << endl;
    }
    return 0;
}