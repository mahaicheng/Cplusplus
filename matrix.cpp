#include <iostream>
#include <cassert>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

void create(vector<vector<int>> &matrix, int left, int right, int &num)
{
    if (left == right)
        matrix[left][right] = num++;

    else // left < right
    {
        for (int i = left; i < right; ++i)
            matrix[left][i] = num++;

        for (int i = left; i < right; ++i)
            matrix[i][right] = num++;

        for (int i = right; i > left; --i)
            matrix[right][i] = num++;

        for (int i = right; i > left; --i)
            matrix[i][left] = num++;
    }
}

int decWidth(int n)
{
    if (n < 1)
        return -1;

    int b = n * n;

    if (b < 0) //overflow
        return -1;

    int result = 0;
    while (b > 0)
    {
        result++;
        b /= 10;
    }

    return result;
}

int main()
{
    int n;
    cin >> n;
    assert(n > 0);

    vector<vector<int>> matrix(n, vector<int>(n));

    int left = 0, right = n - 1, num = 1;
    while (left <= right)
        create(matrix, left++, right--, num);

    int width = decWidth(n);
    for (const auto &vec : matrix)
    {
        for (int a : vec)
            cout << setw(width) << a << " ";
        cout << endl;
    }
}
