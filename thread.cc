/*************************************************************************
        > 文件名: thread.cc
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2016年05月13日 星期五 20时01分48秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

void threadFunc(int count) {
  for (int i = 0; i < 1000; ++i) cout << count++ << endl;
}

int main() {
  int count = 0;
  thread t1(threadFunc, ref(count));
  thread t2(threadFunc, ref(count));

  t1.join();
  t2.join();
}
