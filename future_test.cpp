#include <future>
#include <iostream>
#include <string>
#include <thread>

using namespace std;

string hello(string name) { return "Hello, " + name; }

int main() {
  auto ret = async(std::launch::async, hello, "Haicheng");
  cout << ret.get() << endl;
}
