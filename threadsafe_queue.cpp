#include<iostream>
#include<string>
#include<memory>
#include<thread>
#include<functional>
#include<iterator>
#include<algorithm>
#include<queue>
#include<condition_variable>

using namespace std;

template<typename T>
class threadsafe_queue
{
private:
    std::mutex mtx;
    std::condition_variable cond;
    std::queue<T> data;
public:
    template<typename M>
    void push(const M &v)
    {
        std::lock_guard<std::mutex> lg(mtx);
        data.push(static_cast<T>(v));
        cond.notify_one();
    }
    T pop()
    {
        std::lock_guard<std::mutex> lg(mtx);
        if (data.empty())
            throw std::logic_error("no element!");

        T ret = data.front();
        data.pop();
        return ret;
    }
    void wait_and_pop(T &ret)
    {
        std::unique_lock<std::mutex> lk(mtx);
        cond.wait(lk, [this]{
                    return !this->data.empty();
                  });
        ret = data.front();
        data.pop();
    }
    shared_ptr<T> wait_and_pop()
    {
        std::unique_lock<std::mutex> lk(mtx);
        cond.wait(lk, [this]{
                    return !this->data.empty();
                  });
        shared_ptr<T> ret = shared_ptr<T>(new T((data.front())));
        data.pop();
        return ret;
    }
};

int main()
{
    threadsafe_queue<int> q;
    q.push(4);
    q.push(9.7);
    cout << q.pop() << endl;
    cout << *(q.wait_and_pop()) << endl;
    q.push(8);
    q.push(321.43);
    int a, b;
    a = q.pop();
    q.wait_and_pop(b);
    cout << a << " " << b << endl;
    //cout << q.pop() << endl;
}
