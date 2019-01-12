#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
double a1, b1, a2, b2;
double dis(double a, double b) {
  return sqrt(a * a + b * b);
}
int main() {
  // freopen("girls.in", "r", stdin);
  // freopen("girls.out", "w", stdout);
  scanf("%d", &n);
  while (n--) {
    scanf("%lf%lf%lf%lf", &a1, &b1, &a2, &b2);
    if (a1 > b1) swap(a1, b1);
    if (a2 > b2) swap(a2, b2);
    if (a1 >= a2 && b1 >= b2) {
      puts("Yes");
      continue;
    }
    if (a1 <= a2 && b1 <= b2) {
      puts("Yes");
      continue;
    }
    ll s1 = a1 * b1, s2 = a2 * b2;
    if (s1 > s2) swap(a1, a2), swap(b1, b2);
    double d1 = dis(a1, b1),
           d2 = dis(a2, b2);
    if (d1 <= a2) {
      if ((2 * a1 * b1 / d1) <= b2) {
        puts("Yes");
        continue;
      } else {
        puts("No");
        continue;
      }
    }
    double d3 = sqrt(d1 * d1 - a2 * a2);
    // cout << d3 << endl;
    double d4 = (a1 * b1 - d3 * a2) / (a1 - (d3 * d3) / a1);
    if (d4 < 0) {
      puts("No");
      continue;
    }
    double d5 = (d4 * d3) / a1;
    if (d5 < 0) {
      puts("No");
      continue;
    }
    double d6 = b1 - d4;
    double d7 = b1 * d5 / d6;
    double d8 = a2 - d7;
    if (d8 < 0 || d6 < 0 || d7 < 0) {
      puts("No");
      continue;
    }
    double d9 = sqrt(a1 * a1 - d8 * d8);
    double d10 = d9 * 2 + d3;
    if (d10 <= b2) {
      puts("Yes");
      continue;
    }
    puts("No");
  }
}
