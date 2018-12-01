#include <cstdlib>
#include <iostream>
using namespace std;

void constructmatrix(int **a, int N, int start, int &temp) {
  int endX = N - 1 - start;
  int endY = N - 1 - start;
  for (int i = start; i <= endX; i++) {
    a[start][i] = temp++;
  }
  if (start < endY) {
    for (int i = start + 1; i <= endY; ++i) {
      a[i][endX] = temp++;
    }
  }
  if (start < endX && start < endY) {
    for (int i = endX - 1; i >= start; i--) {
      a[endY][i] = temp++;
    }
  }
  if (start < endX && start < endY - 1) {
    for (int i = endY - 1; i >= start + 1; --i) a[i][start] = temp++;
  }
}
int main() {
  int N;
  cin >> N;
  int **a = (int **)malloc(sizeof(int *) * N);
  for (int i = 0; i < N; i++) {
    a[i] = (int *)malloc(sizeof(int) * N);
  }
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) a[i][j] = 0;
  int temp = 1;
  int start = 0;
  while (N > start * 2 && N > start * 2) {
    constructmatrix(a, N, start, temp);
    start++;
  }
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) cout << a[i][j] << " ";
  system("pause");
  return 0;
}
