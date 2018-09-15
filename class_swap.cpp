#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class A
{
  public:
    A(int x_ = 0) : x(new int(x_)) {}
    ~A()
    {
        if (x != nullptr)
        {
            delete x;
            x = nullptr;
        }
    }
    A(const A &rhs)
    {
        x = new int(*(rhs.x));
    }
    void swap(A &rhs)
    {
        using std::swap;
        swap(x, rhs.x);
    }
    A &operator=(const A &rhs)
    {
        if (this != &rhs)
        {
            A tmp(*(rhs.x)); //�쳣��ȫ
            swap(tmp);
        }
        return *this;
    }
    int *x;
};

void swap(A &lhs, A &rhs)
{
    lhs.swap(rhs);
}

int main()
{
    A a(9);
    cout << *(a.x) << endl;
    A b(5);
    cout << *(b.x) << endl;
    A c(b);
    cout << *(c.x) << endl;
    c = a;
    cout << *(c.x) << endl;
    swap(a, b);
    cout << *(a.x) << endl;
    cout << *(b.x) << endl;
}
