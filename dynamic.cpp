#include <cassert>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Animal {
 public:
  ~Animal() {}
  virtual int age() const = 0;
};

class Fish : public Animal {
 public:
  int age() const { return age_; }

 private:
  int age_ = 9;
};

class Bird : public Animal {
 public:
  Bird() {}
  Bird(int age) : age_(age) {}
  int age() const override { return age_; }

 private:
  int age_{10};
};

int main() {
  shared_ptr<Animal> ap(make_shared<Fish>());
  cout << dynamic_pointer_cast<Fish>(ap)->age() << endl;

  shared_ptr<Animal> bd = make_shared<Bird>(312);
  cout << bd->age() << endl;
}
