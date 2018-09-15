#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class X
{
  public:
    virtual void f()
    {
        cout << "X::f()" << endl;
    }
};

class A : public X
{
  public:
    void f()
    {
        cout << "A::f()" << endl;
    }
};

class B : public X
{
  public:
    void f()
    {
        cout << "B::f()" << endl;
    }
};

class C : public A
{
  public:
    void f()
    {
        cout << "C::f()" << endl;
    }
};

class E : public X
{
  public:
    void f()
    {
        cout << "E::f()" << endl;
    }
};

class F : public E
{
  public:
    void f()
    {
        cout << "F::f()" << endl;
    }
};

///               X
///               |
///        ---------------
///        |             |
///    ---------         E
///    |       |         |
///    A       B         F
///    |
///    C

int main()
{
    vector<shared_ptr<X>> vec;

    vec.push_back(make_shared<X>());
    vec.push_back(make_shared<A>());
    vec.push_back(make_shared<B>());
    vec.push_back(make_shared<C>());
    vec.push_back(make_shared<E>());
    vec.push_back(make_shared<F>());

    for (const auto &sp : vec)
    {
        shared_ptr<C> ptr(static_cast<C *>(sp.get()));
        ptr->f();
    }
}
