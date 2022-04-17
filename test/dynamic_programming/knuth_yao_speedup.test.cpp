/*
 * @brief 動的計画法/Knuth–Yao speedup
 */
#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2415"

#include <iostream>
#include <numeric>
#include <vector>

#include "../../dynamic_programming/knuth_yao_speedup.hpp"

// 二分探索木のコスト \sum_{i = 1}^N w_i * depth(i) の最小値
int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<long long>> w(n, std::vector<long long>(n));
  for (int j = 0; j < n; ++j) {
    std::cin >> w.front()[j];
    if (j > 0) w.front()[j] += w.front()[j - 1];
  }
  for (int i = 1; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      w[i][j] = w.front()[j] - w.front()[i - 1];
    }
  }
  std::cout << knuth_yao_speedup(
                   w, std::numeric_limits<long long>::max())[0][n - 1]
            << '\n';
  return 0;
}
