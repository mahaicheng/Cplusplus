#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, T, M;
  cin >> N >> T >> M;

  vector<int> object(N);
  for (int i = 0; i < N; ++i) {
    cin >> object[i];
  }

  int m = 0, result = 0, currVal = 0;
  for (int i = 0; i < N; ++i) {
    if (m > M)
      break;
    else {
      if (T - currVal >= object[i]) {
        currVal += object[i];
        result++;
      } else {
        m++;
        currVal = 0;
      }
    }
  }

  cout << result << endl;
}
