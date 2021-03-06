#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
  double n, m;
  while (cin >> n >> m) {
    if (n < 1.0 || m < 1.0) continue;

    double result = n;
    for (int i = 1; i < m; ++i) {
      n = sqrt(n);
      result += n;
    }
    printf("%.2f\n", result);
  }
}
