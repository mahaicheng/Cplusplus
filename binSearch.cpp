/*************************************************************************
	> 文件名: binSearch.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2016年03月27日 星期日 18时12分01秒
 ************************************************************************/

#include<iostream>
using namespace std;

int search(int A[], int n, int target)
{
    int first = 0, last = n;
    while(first != last)
    {
        const int mid = (first + last) / 2;

        if(A[mid] == target)
            return mid;

        if(A[first] <= A[mid])
        {
            if(A[first] <= target && target < A[mid])
                last = mid;
            else
                first = mid + 1;
        }
        else
        {
            if(A[mid] < target && target <= A[last-1])
                first = mid + 1;
            else
                last = mid;
        }
    }

    return -1;
}

//test
int main()
{
    int A[]{5,6,7,8,9,1,2,3,4};

    for(int i = 0; i < 11; ++i)
    {
        int pos = search(A, sizeof(A)/sizeof(A[0]), i);
        cout << pos << " ";
    }
}
