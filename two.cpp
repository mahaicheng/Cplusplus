#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

vector<int> getPartition(const vector<vector<int>> &land, int n, int m)
{
    if (land.empty() || land.front().empty() || n < 1 || m < 1)
        return vector<int>();

    vector<int> A(n + 1), B(n + 1), sum(n + 1);

    int numOfZero = 0, numOfOne = 0;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (land[i][j] == 0)
                numOfZero++;
            else
                numOfOne++;
        }
    }

    A[0] = 0;
    A[n] = numOfOne;
    B[0] = numOfZero;
    B[n] = 0;

    sum[0] = A[0] + B[0];
    sum[n] = A[n] + B[n];

    for (int i = 0; i < n - 1; ++i)
    {
        int zeroNum = 0, oneNum = 0;
        for (int j = 0; j < m; ++j)
        {
            if (land[j][i] == 0)
                zeroNum++;
            else
                oneNum++;
        }

        A[i + 1] = A[i] + oneNum;
        B[i + 1] = B[i] - zeroNum;
        sum[i + 1] = A[i + 1] + B[i + 1];
    }

    int min = n;
    for (int i = n - 1; i >= 0; --i)
    {
        if (sum[i] <= sum[min])
        {
            min = i;
        }
    }

    return vector<int>{min, min + 1};
}

int main()
{
    vector<vector<int>> land;
    land.push_back({1, 1, 1, 1});
    land.push_back({0, 0, 0, 0});
    land.push_back({1, 0, 1, 1});

    vector<int> result = getPartition(land, 4, 3);

    for (auto i : result)
    {
        cout << i << endl;
    }
}
