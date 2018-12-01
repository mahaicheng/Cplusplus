/*************************************************************************
        > 文件名: thread1.cc
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2016年05月13日 星期五 20时16分00秒
 ************************************************************************/

#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <utility>

using namespace std;

mutex mtx;

ostream &print(ostream &os, const string &str, int x) {
  lock_guard<mutex> lkgrd(mtx);
  for (int i = 0; i < 5; ++i) {
    // lock_guard<mutex> lkgrd(mtx);
    os << str << x << endl;
  }

  return os;
}

int main() {
  string name("Ma Haicheng");

  thread t1(print, ref(cout), name, 1);
  thread t2(print, ref(cout), name, 2);
  thread t3(print, ref(cout), name, 3);
  thread t4(print, ref(cout), name, 4);

  t1.join();
  t2.join();
  t3.join();
  t4.join();
}
