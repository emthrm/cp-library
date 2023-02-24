/*
 * @title その他/転倒数
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D"

#include <iostream>
#include <vector>

#include "emthrm/misc/inversion_number.hpp"

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  std::cout << emthrm::inversion_number(a) << '\n';
  return 0;
}
