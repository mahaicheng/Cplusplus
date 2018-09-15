#include <iostream>
#include <functional>

using namespace std;

void AddOne(int &num)
{
    cout << num << endl;
    num += 1;
}

void f(int num)
{
    AddOne(num);
}

int main()
{
    int n = 2;
    f(std::ref(n));
    n += 1;
    //cout << n << endl;
}
