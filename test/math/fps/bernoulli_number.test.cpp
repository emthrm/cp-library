/*
 * @brief 数学/形式的冪級数/ベルヌーイ数
 */
#define PROBLEM "https://judge.yosupo.jp/problem/bernoulli_number"

#include <iostream>
#include <vector>
#include "../../../math/modint.hpp"
#include "../../../math/convolution/ntt.hpp"
#include "../../../math/fps/fps.hpp"
#include "../../../math/fps/bernoulli_number.hpp"

int main() {
  using ModInt = MInt<0>;
  ModInt::set_mod(998244353);
  NTT<0> ntt;
  FPS<ModInt>::set_mul([&](const std::vector<ModInt> &a, const std::vector<ModInt> &b) -> std::vector<ModInt> {
    return ntt.convolution(a, b);
  });
  int n;
  std::cin >> n;
  std::vector<ModInt> b = bernoulli_number<ModInt>(n);
  for (int i = 0; i <= n; ++i) std::cout << b[i] << " \n"[i == n];
  return 0;
}
