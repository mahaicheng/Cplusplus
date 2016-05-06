#include<iostream>
#include<string>
#include<cstring>

using namespace std;

namespace mhc
{
template<typename T>
const T& max(const T &lhs, const T &rhs)
{
    return lhs < rhs ? rhs : lhs;
}

template<typename T>
const T * max(const T *lhs, const T *rhs)
{
    return strcmp(lhs, rhs) < 0 ? rhs : lhs;
}
}


int main()
{
    string s;
    cout << mhc::max("apple", "peach") << endl;
    cout << mhc::max("apple", "tomato") << endl;
    cout << mhc::max("apple", "s") << endl;
}
