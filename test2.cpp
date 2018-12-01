#include <functional>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
  int a;
  cin >> a;

  stringstream ss;
  ss << a;

  string str;
  ss >> str;

  cout << str << endl;
}
