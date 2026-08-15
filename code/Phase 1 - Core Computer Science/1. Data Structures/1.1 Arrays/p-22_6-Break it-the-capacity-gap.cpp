#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> v;
  v.reserve(16);

  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  cout << v[7] << "\n";

  if (v.at(7))
    cout << "exist";
}