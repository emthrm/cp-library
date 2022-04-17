/*
 * @brief 数学/$i^k \bmod m$ ($0 \leq i \leq n$)
 */
#define PROBLEM "https://yukicoder.me/problems/no/1409"

#include <iostream>
#include <vector>

#include "../../math/enumerate_k-th_power.hpp"

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int v, x;
    std::cin >> v >> x;
    const int p = x * v + 1;
    const std::vector<int> ps = enumerate_kth_power(p - 1, x, p);
    std::vector<int> a;
    a.reserve(x);
    for (int i = 1; i < p; ++i) {
      if (ps[i] == 1) a.emplace_back(i);
    }
    for (int i = 0; i < x; ++i) {
      std::cout << a[i] << " \n"[i + 1 == x];
    }
  }
  return 0;
}
