/*
 * @brief 数学/形式的冪級数/形式的冪級数 (平方根)
 */
#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_of_formal_power_series"

#include <iostream>
#include <vector>
#include "../../../math/modint.hpp"
#include "../../../math/fps/fps.hpp"
#include "../../../math/convolution/ntt.hpp"
#include "../../../math/mod_sqrt.hpp"

int main() {
  using ModInt = MInt<0>;
  ModInt::set_mod(998244353);
  NTT<0> ntt;
  FPS<ModInt>::set_mul([&](const std::vector<ModInt> &a, const std::vector<ModInt> &b) -> std::vector<ModInt> {
    return ntt.convolution(a, b);
  });
  FPS<ModInt>::set_sqr([&](const ModInt &a, ModInt &res) -> bool {
    long long ans = mod_sqrt(a.val, ModInt::get_mod());
    if (ans == -1) {
      return false;
    } else {
      res = ans;
      return true;
    }
  });
  int n;
  std::cin >> n;
  FPS<ModInt> fps(n - 1);
  for (int i = 0; i < n; ++i) std::cin >> fps[i];
  fps = fps.sqrt(n - 1);
  if (fps.co.empty()) {
    std::cout << "-1\n";
  } else {
    for (int i = 0; i < n; ++i) std::cout << fps[i] << " \n"[i + 1 == n];
  }
  return 0;
}
