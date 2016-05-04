#include<iostream>
#include<cstring>
#include<string>

using namespace std;

template<typename T>
inline T const & max(T const &lhs, const T &rhs)
{
    return lhs < rhs ? rhs : lhs;
}

template<typename T>
inline T* const max(T *const lhs, T *const rhs)
{
    return *lhs < *rhs ? rhs : lhs;
}

inline char const * const& max(const char *const &lhs, const char *const &rhs)
{
    return strcmp(lhs, rhs) < 0 ? rhs : lhs;
}

int main()
{
    int a = 7, b = 42;
    cout << ::max(a, b) << endl;

    string s("hey"), t("you");
    cout << ::max(s, t) << endl;

    int *pa = &a;
    int *pb = &b;
    cout << *::max(pa, pb) << endl;

    const char *s1 = "David";
    const char *s2 = "Nico";
    cout << ::max(s1, s2) << endl;
}
