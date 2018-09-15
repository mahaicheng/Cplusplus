/*************************************************************************
	> 文件名: nodefaultCtor.cpp
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2016年04月27日 星期三 16时11分47秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <iterator>
#include <initializer_list>

using namespace std;

class Int
{
  public:
    Int(int val) : m_val(val) {}

    operator int()
    {
        return m_val;
    }

  private:
  private:
    int m_val;
};

int main()
{

    for (int i = 0; i < 10; ++i)
    {
        cout << iArray[i] << " ";
    }
    cout << endl;
}
