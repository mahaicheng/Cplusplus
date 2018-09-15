#include <iostream>
#include <string>
#include <cstring>

using std::cout;
using std::endl;
using std::string;

namespace mhc
{
template <typename T1, typename T2>
inline decltype(T1() + T2()) min(const T1 &lhs, const T2 &rhs)
{
    return (lhs < rhs) ? lhs : rhs;
}

template <typename T, size_t N, size_t M>
inline const T *min(const T (&a)[N], const T (&b)[M])
{
    return strcmp(a, b) <= 0 ? a : b;
}

template <typename T1, typename T2>
inline auto max(const T1 &lhs, const T2 &rhs) -> decltype(lhs + rhs)
{
    return (rhs < lhs) ? lhs : rhs;
}

template <typename T, size_t N, size_t M>
inline const T *max(const T (&a)[N], const T (&b)[M])
{
    return strcmp(a, b) > 0 ? a : b;
}
}; // namespace mhc
int main()
{
    cout << mhc::min(1, 9) << endl;
    cout << mhc::max(1, 9) << endl;

    cout << mhc::min(1.4, 2) << endl;
    cout << mhc::max(1.4, 2) << endl;

    cout << mhc::min(3.5, 1.8) << endl;
    cout << mhc::max(3.5, 1.8) << endl;

    cout << mhc::min(string("mhc"), string("libo")) << endl;
    cout << mhc::max(string("mhc"), string("libo")) << endl;

    cout << mhc::min("mhc", "libo") << endl;
    cout << mhc::max("mhc", "libo") << endl;
}
