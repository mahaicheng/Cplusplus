#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class ListNode
{
  public:
    ListNode() = default;
    ListNode(int val_, ListNode *next_ = nullptr) : val(val_), next(next_) {}

  private:
    int val;
    ListNode *next;
};

int main()
{
    shared_ptr<int> p(new int[8], [](int *p) {
        delete[] p;
    });
    cout << *p << endl;
    int *s = p.get();
    for (int i = 0; i < 8; ++i)
    {
        //        cout << *p.get()++ << endl;
    }

    cout << endl;

    //    p = new int[8]();
    for (int i = 0; i < 8; ++i)
    {
        //        cout << *p++ << endl;
    }
}
