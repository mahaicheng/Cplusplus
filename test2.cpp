#include<iostream>
#include<string>
#include<sstream>
#include<functional>

using namespace std;

int main()
{
    int a;
    cin >> a;

    stringstream ss;
    ss << a;

    string str;
    ss >> str;

    cout << str << endl;
}
