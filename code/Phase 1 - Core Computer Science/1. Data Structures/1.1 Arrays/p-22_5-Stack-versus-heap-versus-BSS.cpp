#include <bits/stdc++.h>
using namespace std;

void stackArr() { int *arr[1000]; }

void heapArr() {
  int *arr = new int[1000];
  delete[] arr;
}

void bssArr() { static int *arr[1000]; }

int main() {
  std::size_t loop = 1000000;

  // row first
  auto start = std::chrono::steady_clock::now();
  for (std::size_t i = 0; i < loop; ++i)
    stackArr();
  auto end = std::chrono::steady_clock::now();

  auto stack_time =
      std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

  start = std::chrono::steady_clock::now();
  for (std::size_t i = 0; i < loop; ++i)
    heapArr();
  end = std::chrono::steady_clock::now();

  auto heap_time =
      std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

  start = std::chrono::steady_clock::now();
  for (std::size_t i = 0; i < loop; ++i)
    bssArr();
  end = std::chrono::steady_clock::now();

  auto static_time =
      std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

  // output
  cout << "Stack array time = " << static_cast<double>(stack_time) / loop
       << "\n";
  cout << "Heap array time = " << static_cast<double>(heap_time) / loop << "\n";
  cout << "Static array time = " << static_cast<double>(static_time) / loop
       << "\n";
}