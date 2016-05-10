/*************************************************************************
	> 文件名: arrayOrPointer.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2016年05月10日 星期二 19时13分06秒
 ************************************************************************/

#include<iostream>
using namespace std;

template<size_t N>
void print(const char (&array)[N])
{
    cout << "using void(const char (&array)[N]) version" << endl;
    cout << array << endl;
}

void print(const char *array)
{
    cout << "using void(const char *) version" << endl;
    cout << array << endl;
}

int main()
{
    char arrayName[] = "Ma Haicheng";
    print(arrayName);

    const char *pointerName = "Ma Haicheng";
    print(pointerName);
}
