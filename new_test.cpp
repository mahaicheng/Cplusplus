#include <iostream>
#include <string>

using namespace std;

class HeapObject
{
  public:
    HeapObject() = default;

  private:
    ~HeapObject() = default;
};

class StackObject
{
  private:
    void *operator new(size_t) = delete;
};

class A : public HeapObject
{
  public:
    int x;
};

class B : StackObject
{
    int y;
};

int main()
{
    A *a = new A();
}
