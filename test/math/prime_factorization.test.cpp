/*
 * @brief 数学/素因数分解
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A"

#include <iostream>
#include <utility>
#include <vector>

#include "emthrm/math/prime_factorization.hpp"

int main() {
  int n;
  std::cin >> n;
  const std::vector<std::pair<int, int>> ans = emthrm::prime_factorization(n);
  std::cout << n << ": ";
  for (int i = 0; i < static_cast<int>(ans.size()); ++i) {
    for (int j = 0; j < ans[i].second; ++j) {
      std::cout << ans[i].first
                << " \n"[i + 1 == static_cast<int>(ans.size()) &&
                         j + 1 == ans[i].second];
    }
  }
  return 0;
}
