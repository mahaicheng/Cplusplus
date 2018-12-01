#include <functional>
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>

using namespace std;

class A {
  friend ostream &operator<<(ostream &os, const A &rhs);

 public:
  A(int *x_ = new int(0), double *y_ = new double(0.0)) : x(x_), y(y_) {}
  ~A() {
    if (x != nullptr) delete x;
    if (y != nullptr) delete y;
  }
  A(const A &rhs) {
    x = new int(*(rhs.x));
    y = new double(*(rhs.y));
  }
  A(A &&rhs) {
    x = rhs.x;
    rhs.x = nullptr;
    y = rhs.y;
    rhs.y = nullptr;
  }

 private:
  int *x;
  double *y;
};

ostream &operator<<(ostream &os, const A &rhs) {
  if (rhs.x == nullptr)
    os << "nullptr";
  else
    os << *(rhs.x);

  os << " ";

  if (rhs.y == nullptr)
    os << "nullptr";
  else
    os << *(rhs.y);

  return os;
}

template <typename T>
class Shared_ptr final {
 public:
  explicit Shared_ptr(T *m) : ptr(m) {
    mtx = new mutex();
    ref_count = new int(1);
  }
  Shared_ptr(const Shared_ptr &rhs) {
    ptr = rhs.ptr;
    mtx = rhs.mtx;
    ref_count = rhs.ref_count;
    lock_gard<mutex> lg(*mtx);
    *ref_count++;
  }
  ~Shared_ptr() {
    {
      lock_gard<mutex> lg(*mtx);
      *ref_count--;
    }
    if (*ref_count == 0) {
      delete ptr;
      delete mtx;
      delete ref_count;
    }
  }

 private:
  T *ptr;
  mutex *mtx;
  int *ref_count;
};

int main() {
  A a1(new int(1), new double(5.4));
  cout << a1 << endl;

  A a2(a1);
  cout << a2 << endl;

  A a3(std::move(a1));
  cout << a3 << endl;
  cout << a1 << endl;
}
