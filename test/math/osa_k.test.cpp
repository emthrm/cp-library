/*
 * @brief 数学/osa_k 法
 */
#define PROBLEM "https://atcoder.jp/contests/abc177/tasks/abc177_e"

#include <algorithm>
#include <iostream>
#include <vector>

#include "emthrm/math/osa_k.hpp"

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  const int max_a = *std::max_element(a.begin(), a.end());
  const emthrm::OsaK osa_k(max_a);
  std::vector<int> prime_factor(max_a + 1, 0);
  for (const int a_i : a) {
    for (const auto& [prime, _] : osa_k.query(a_i)) {
      ++prime_factor[prime];
    }
  }
  const int maximum =
      *std::max_element(prime_factor.begin(), prime_factor.end());
  if (maximum <= 1) {
    std::cout << "pairwise coprime\n";
  } else if (maximum == n) {
    std::cout << "not coprime\n";
  } else {
    std::cout << "setwise coprime\n";
  }
  return 0;
}
