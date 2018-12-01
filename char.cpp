#include <iostream>

using namespace std;

int main() {
  char c = 0;
  int count = 0;
  for (int i = 0; i < 128; ++i) {
    count++;
    cout << c++ << " ";
    if (count == 20) {
      cout << endl;
      count = 0;
    }
  }
}
