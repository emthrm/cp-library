/*
 * @brief 数学/畳み込み/添え字 lcm での畳み込み
 */
#define PROBLEM "https://judge.yosupo.jp/problem/lcm_convolution"

#include <iostream>
#include <vector>

#include "emthrm/math/convolution/lcm_convolution.hpp"
#include "emthrm/math/modint.hpp"

int main() {
  using ModInt = emthrm::MInt<998244353>;
  int n;
  std::cin >> n;
  std::vector<ModInt> a(n + 1, 0), b(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    std::cin >> b[i];
  }
  const std::vector<ModInt> c = emthrm::lcm_convolution(a, b, n);
  for (int i = 1; i <= n; ++i) {
    std::cout << c[i] << " \n"[i == n];
  }
  return 0;
}
