/*
 * @title 数学/sum of floor of linear
 */
#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_floor_of_linear"

#include <iostream>

#include "emthrm/math/floor_sum.hpp"

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n, m, a, b;
    std::cin >> n >> m >> a >> b;
    std::cout << emthrm::floor_sum(a, b, m, n) << '\n';
  }
  return 0;
}
