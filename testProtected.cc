/*************************************************************************
        > 文件名: testProtected.cc
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2016年05月16日 星期一 16时11分15秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Base {
 public:
  Base(int a = 9) : a_(a) {}
  virtual ~Base() = default;

 protected:
  int a_;
  int &a() { return a_; }
};

class Derived : public Base {
 public:
  Derived(int b) : b_(b) {}
  int &a() { return b_; }

 private:
  int b_;
};

int main() {
  Base base(3);
  Derived derived(7);

  Base *pBase = &derived;
  // cout << base.a() << endl;
  cout << derived.a() << endl;
  // cout << pBase->a() << endl;
}
