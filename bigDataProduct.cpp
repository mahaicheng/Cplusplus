#include <iostream>
#include <string>

using namespace std;

bool valid(const string &str)
{
    if (str.empty())
        return false;

    for (auto c : str)
    {
        if (c < '0' || c > '9')
            return false;
    }

    int pos = str.find_first_not_of('0', 0);
    if (pos != 0)
        return false;
    else
        return true;
}

deque<int> cal(int i, int e, const string &str)
{
}

int main()
{
    string lhs, rhs;
    cin >> lhs >> rhs;

    if (!valid(lhs) || !valid(rhs))
    {
        cerr << "input invalid!" << endl;
        return 0;
    }

    int size = rhs.size();
    vector<deque<int>> cache(size);

    for (size_t i = 0; i < rhs.size(); ++i)
    {
        deque<int> tmp = cal(i, rhs[i] - '0', lhs);
        cache.push_back(tmp);
    }

    deque<int> result = calDeque(cache);

    for (auto i : result)
    {
        cout << i;
    }
    cout << endl;
}
