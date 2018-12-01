#include <fstream>
#include <future>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ofstream out("helloworld.txt");
  for (int i = 0; i < 9999999; ++i) {
    async(
        [&out](int i) { out << "hello world! I am the " << i << "th" << endl; },
        i);
    // out << "hello world! I am the " << i << "th" << endl;
  }
}
