/*************************************************************************
	> 文件名: thread_mutex.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2016年03月25日 星期五 10时25分16秒
 ************************************************************************/

#include <iostream>
#include <thread>
#include <mutex>
#include <string>
#include <functional>
#include <unistd.h>
#include <future>

using namespace std;

mutex mtx;

int thrd_fn(int &num, int c)
{
    lock_guard<mutex> lg(mtx);
    for (int i = 0; i < 10; ++i)
    {
        cout << "thread " << c << ": " << num++ << endl;
    }

    return c;
}

int main()
{
    int num = 0;
    future<int> t1 = async(launch::async, thrd_fn, ref(num), 1);
    future<int> t2 = async(launch::async, thrd_fn, ref(num), 2);
    future<int> t3 = async(launch::async, thrd_fn, ref(num), 3);

    cout << t1.get() << endl;
    cout << t2.get() << endl;
    cout << t3.get() << endl;

    //thread t1(thrd_fn, ref(num), 1);
    //thread t2(thrd_fn, ref(num), 2);
    //thread t3(thrd_fn, ref(num), 3);
    //thread t4(thrd_fn, ref(num), 4);

    //t3.join();
    //t4.join();

    //t1.join();
    //t2.join();
}
