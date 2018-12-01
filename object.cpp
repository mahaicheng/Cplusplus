/*************************************************************************
        > 文件名: object.cpp
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2016年04月22日 星期五 09时18分50秒
 ************************************************************************/

#include <cstdlib>
#include <iostream>
using namespace std;

class Object {
 public:
  Object() { cout << "Hello, I am born." << endl; }
  ~Object() { cout << "Bye, I am died." << endl; }
  void hello() { cout << "I am Object." << endl; }
};

int main() {
  Object *ObjectA = (Object *)malloc(sizeof(Object));
  ObjectA->hello();
  free(ObjectA);
  ObjectA = nullptr;

  ObjectA = new Object;
  ObjectA->hello();
  delete ObjectA;
}
