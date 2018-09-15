#include <iostream>
#include <string>
#include <iterator>

using namespace std;

namespace mhc
{
template <typename T, size_t N>
ostream &operator<<(ostream &os, T (&a)[N])
{
    os << string("This array has ") << N << ((N == 1) ? " element" : " elements ") << endl;
    os << string("The content is ") << endl;
    copy(begin(a), end(a), ostream_iterator<T>(os, " "));
    cout << endl;
}
} // namespace mhc

int main()
{
    int a[12]{1, 2, 4, 5, 6, 7, 8, 9, 2, 3, 4};
    char str[20] = "hello, mahaicheng";

    cout << a << endl;
}
