#include<iostream>
#include<thread>
#include<mutex>
#include<memory>

using namespace std;

class Singleton
{
public:
    Singleton(const Singleton &) = delete;

    static Singleton* get_instance()
    {
        call_once(f, init);
        return p;
    }
    int get_x() const
    {
        return x;
    }
private:
    Singleton() = default;

    static void init()
    {
        p = new Singleton();
    }
    int x = 8;

    static once_flag f;
    static Singleton *p;
};

int main()
{
    Singleton *p = Singleton::get_instance();
    cout << p->get_x() << endl;
}
