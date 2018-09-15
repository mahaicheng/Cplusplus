#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

vector<string> grayCoder(int n)
{
    if (n <= 0)
        return vector<string>();

    vector<string> result(1 << n);

    if (n == 1)
    {
        result[0] = "0";
        result[1] = "1";
        return result;
    }

    auto lastResult = grayCoder(n - 1);

    for (size_t i = 0; i < lastResult.size(); ++i)
    {
        result[i] = string("0") + lastResult[i];
        result[result.size() - 1 - i] = string("1") + lastResult[i];
    }

    return result;
}

int main()
{
    int n;
    cin >> n;
    {
        vector<string> result = grayCoder(n);

        ofstream out("result.txt");

        for (auto str : result)
        {
            out << str << endl;
        }
        out << endl;
    }
}
