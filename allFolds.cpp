#include <iostream>
#include <string>

using namespace std;

void printAllFolds(int i, int n, bool down) {
  if (i > n) return;

  printAllFolds(i + 1, n, true);

  cout << (down ? "down" : "up") << " ";

  printAllFolds(i + 1, n, false);
}

int main() {
  int n;
  while (cin >> n) {
    if (n < 1) continue;

    printAllFolds(1, n, true);
    cout << endl;
  }
}
