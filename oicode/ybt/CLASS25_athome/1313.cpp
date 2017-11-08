#include <bist/stdc++.h>
using namespace std;
int even[10001] = {0}, odd[10001] = {0};
int main() {
    int n, x = 9;
    cin >> n;
    even[1] = 9;
    odd[1] = 1;
    for(int i = 2; i <= n; ++i) {
        if(i == n) x = 8;
        even[i] = (even[i - 1] * x + odd[i - 1]) % 12345;
        odd[i] = (even[i - 1] + odd[i - 1] * 9) % 12345;
    }
    cout << even[n];
    return 0;
}