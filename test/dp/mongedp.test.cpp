/*
 * @brief 動的計画法/MongeDP
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2415"

#include <iostream>
#include <numeric>
#include <vector>
#include "../../dp/mongedp.hpp"

// 二分探索木のコスト: Σa[i] * depth(i) の最小値
int main() {
  constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
  int n;
  std::cin >> n;
  std::vector<long long> w(n);
  for (int i = 0; i < n; ++i) std::cin >> w[i];
  std::vector<long long> sum(n + 1, 0);
  std::partial_sum(w.begin(), w.end(), sum.begin() + 1);
  auto cost = [&sum](int i, int k, int j) -> long long { return sum[j + 1] - sum[i]; };
  std::cout << mongedp(n, cost, LINF) << '\n';
  return 0;
}
