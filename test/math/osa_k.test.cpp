/*
 * @brief 数学/osa_k 法
 */
#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc177/tasks/abc177_e"

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include "../../math/osa_k.hpp"

int main() {
  constexpr int A = 1000000;
  osa_k osa(A);
  int n;
  std::cin >> n;
  std::vector<int> prime_factor(A + 1, 0);
  for (int i = 0; i < n; ++i) {
    int a;
    std::cin >> a;
    for (const std::pair<int, int> &pr : osa.query(a)) ++prime_factor[pr.first];
  }
  int mx = *std::max_element(prime_factor.begin(), prime_factor.end());
  if (mx <= 1) {
    std::cout << "pairwise coprime\n";
  } else if (mx == n) {
    std::cout << "not coprime\n";
  } else {
    std::cout << "setwise coprime\n";
  }
  return 0;
}
