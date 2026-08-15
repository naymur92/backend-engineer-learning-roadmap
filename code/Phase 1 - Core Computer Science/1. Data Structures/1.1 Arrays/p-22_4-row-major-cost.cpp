#include <bits/stdc++.h>
using namespace std;

constexpr std::size_t N = 4096;

long long rowMajorSum(const int *matrix) {
  long long sum = 0;

  for (std::size_t i = 0; i < N; ++i)
    for (std::size_t j = 0; j < N; ++j)
      sum += matrix[(i * N + j)];

  return sum;
}

long long columnMajorSum(const int *matrix) {
  long long sum = 0;

  for (std::size_t j = 0; j < N; ++j)
    for (std::size_t i = 0; i < N; ++i)
      sum += matrix[(i * N + j)];

  return sum;
}

int main() {
  const std::size_t total = N * N;

  int *matrix = new int[total];

  // initialize
  for (int i = 0; i < total; ++i)
    matrix[i] = 1;

  // row first
  auto start = std::chrono::steady_clock::now();
  long long row_sum = rowMajorSum(matrix);
  auto end = std::chrono::steady_clock::now();

  auto row_time =
      std::chrono::duration_cast<std::chrono::microseconds>(end - start)
          .count();

  // column first
  start = std::chrono::steady_clock::now();
  long long col_sum = columnMajorSum(matrix);
  end = std::chrono::steady_clock::now();

  auto col_time =
      std::chrono::duration_cast<std::chrono::microseconds>(end - start)
          .count();

  // output
  cout << "Row first sum = " << row_sum << "\n";
  cout << "Column first sum = " << col_sum << "\n\n";

  cout << "Row first time = " << row_time << "\n";
  cout << "Column first time = " << col_time << "\n\n";

  delete[] matrix;
}