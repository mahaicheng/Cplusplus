#include <iostream>
#include <string>
#include <memory>
#include <cassert>

using namespace std;

class Animal
{
  public:
    virtual int age() const
    {
        return num;
    }
    int num;
};

class Fish : public Animal
{
  public:
    int age() const
    {
        return age_;
    }
    int age_ = 9;
};

int main()
{
    shared_ptr<Animal> ap(make_shared<Fish>());
    cout << dynamic_pointer_cast<Fish>(ap)->age_ << endl;
}
