#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("binary.in", "r", stdin);
    freopen("binary.out", "w", stdout);
    // cout << bitset<12>(1) << endl;
    // cout << bitset<12>(10) << endl;
    // cout << bitset<12>(11) << endl;
    // cout << bitset<12>(100) << endl;
    // cout << bitset<12>(101) << endl;
    // cout << bitset<12>(110) << endl;
    // cout << bitset<12>(111) << endl;
    // cout << bitset<12>(1000) << endl;
    // cout << bitset<12>(1001) << endl;
    // cout << bitset<12>(1010) << endl;
    // cout << bitset<12>(1011) << endl;
    // cout << bitset<12>(1100) << endl;
    // cout << bitset<12>(1101) << endl;
    // cout << bitset<12>(1110) << endl;
    int val;
    scanf("%d", &val);
    int lst[] = {1, 10, 11, 10, 101, 110, 111, 1000, 1001, 1100};
    cout << lst[val - 1] << endl;
}