#include <iostream>
#include <string>

using namespace std;

bool valid(int i) {
  int orignal = i;

  int result = 0;
  while (i > 0) {
    int tmp = i % 10;
    result += tmp * tmp * tmp;
    i /= 10;
  }

  if (result == orignal)
    return true;
  else
    return false;
}

int main() {
  int m, n;
  while (cin >> m >> n) {
    if (m < 1 || n < 1) continue;

    bool hasAnyValid = false;
    for (int i = m; i <= n; ++i) {
      if (valid(i)) {
        hasAnyValid = true;
        cout << i << " ";
      }
    }

    if (!hasAnyValid) cout << "no";

    cout << endl;
  }
}
