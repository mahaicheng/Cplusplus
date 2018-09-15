#include <iostream>
#include <future>
#include <thread>
#include <string>

using namespace std;

string hello(string name)
{
    return "Hello, " + name;
}

int main()
{
    auto ret = async(std::launch::async, hello, "Haicheng");
    cout << ret.get() << endl;
}
