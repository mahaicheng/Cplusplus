/*************************************************************************
        > 文件名: shared_ptr.cpp
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2016年05月20日 星期五 18时13分02秒
 ************************************************************************/

#include <iostream>
#include <memory>
#include <string>
#include <utility>

using namespace std;

class Person {
  friend ostream &operator<<(ostream &, const shared_ptr<Person> &);

 public:
  Person(const string &name = string("invalid name"), int age = -1)
      : name_(name), age_(age) {}

  void release() { delete this; }
  virtual ~Person() = default;

 private:
  string name_;
  int age_;
};

ostream &operator<<(ostream &os, const shared_ptr<Person> &personPtr) {
  os << "[" << personPtr->name_ << " : " << personPtr->age_ << "]";
  return os;
}

int main() {
  // shared_ptr<Person> a(new Person("Ma Haicheng", 26));
  shared_ptr<Person> a = make_shared<Person>("Ma Haicheng", 26);

  // shared_ptr<Person> b(new Person("Ma Dongmei", 25));
  shared_ptr<Person> b = make_shared<Person>("Ma Dongmei", 25);

  cout << a << endl << b << endl;
}
