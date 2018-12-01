/*************************************************************************
        > 文件名: setTest.cpp
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2016年05月16日 星期一 09时38分33秒
 ************************************************************************/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>

using namespace std;

int main() {
  set<int> iSet{8, 7, 9, 3, 1, 2, 6, 5, 4, 0};
  copy(iSet.begin(), iSet.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  auto iter = lower_bound(iSet.begin(), iSet.end(), 4);

  int tmpseqno = -1;
  if (iter != iSet.end()) {
    iSet.erase(iSet.begin(), iter);
    tmpseqno = *iter;
  }
  copy(iSet.begin(), iSet.end(), ostream_iterator<int>(cout, " "));
  cout << "\ntmpseqno = " << tmpseqno << endl;
}
