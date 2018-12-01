#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>

using namespace std;

template <int N>
void print(char (&a)[N]) {
  cout << "has " << N << " chars: " << endl;
  copy(begin(a), end(a), ostream_iterator<int>(cout, " "));
  cout << endl;
}

int main() {
  char str[]{"mahaicheng"};
  print(str);
}
