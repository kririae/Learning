//
// Created by AliceMargatroid on 2017/12/30.
//
#include <bits/stdc++.h>

using namespace std;
double n, r;
vector<double> pos;
double res[10005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> r;
    for (int i = 0; i < n; ++i) {
        double curr;
        cin >> curr;
        pos.push_back(curr);
    };
    res[0] = r;
    for (int i = 0; i < pos.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            double delx = fabs(pos[i] - pos[j]);
            res[i] = max(res[i], res[j] + sqrt(4 * r * r - delx * delx));
        }
    }
    for (int i = 0; i < n; ++i) cout << setprecision(10) << res[i] << " ";
    return 0;
}
