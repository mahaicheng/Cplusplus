#include<iostream>
#include<string>
#include<algorithm>
#include<iterator>

using namespace std;

template<int N>
void print(char (&a)[N])
{
    cout << "has " << N << " chars: " << endl;
    copy(begin(a), end(a), ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main()
{
    char str[]{"mahaicheng"};
    print(str);
}
