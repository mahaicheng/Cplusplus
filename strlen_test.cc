/*************************************************************************
	> 文件名: strlen_test.cc
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2016年05月24日 星期二 15时34分11秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char a[] = "xyz", b[] = {'x', 'y', 'z'};

    cout << "strlen(a) = " << strlen(a) << endl;
    cout << "strlen(b) = " << strlen(b) << endl;
    if (strlen(a) > strlen(b))
        cout << "a > b" << endl;
    else
        cout << "a <= b" << endl;
}
