/*************************************************************************
        > 文件名: typetraits.cpp
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2016年04月15日 星期五 15时46分14秒
 ************************************************************************/

#include <initializer_list>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

void typeHelper(const char &a, char b) { cout << "char: " << a << endl; }

void typeHelper(const int &a, int b) { cout << "int: " << a << endl; }

void typeHelper(const double &a, double b) { cout << "double: " << a << endl; }

void typeHelper(const string &a, string b) { cout << "string: " << a << endl; }

template <typename T>
void typeHelper(const T *a, size_t N) {
  cout << "C-array: ";
  for (int i = 0; i < N; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
}

template <typename T>
void type(const T &a) {
  typeHelper(a, T());
}

template <typename T, size_t N>
void type(const T (&a)[N]) {
  typeHelper(a, N);
}

int main() {
  type(8);
  type(9.3);
  type("mahaicheng");
  type(string("mahaicheng"));

  int a[]{1, 2, 3, 4, 5, 4};
  type(a);

  string name[]{"mahaicheng", "madongmei", "liuchunling", "machengjian"};
  type(name);

  char c{'f'};
  type(c);
}
