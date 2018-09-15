#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    int a, b;
    stringstream ss;

    while (cin >> a >> b)
    {
        string bStr;
        ss.clear();
        ss << b;
        ss >> bStr;

        while (true)
        {
            ss.clear();
            string aStr;
            ss << a;
            ss >> aStr;

            if (aStr.find(bStr) != string::npos)
            {
                cout << a << endl;
                break;
            }
            else
                a += 1;
        }
    }
}
