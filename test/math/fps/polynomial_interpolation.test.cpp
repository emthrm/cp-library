/*
 * @brief 数学/形式的冪級数/多項式補間
 */
#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_interpolation"

#include <iostream>
#include <vector>
#include "../../../math/modint.hpp"
#include "../../../math/fps/fps.hpp"
#include "../../../math/convolution/ntt.hpp"
#include "../../../math/fps/polynomial_interpolation.hpp"

int main() {
  using ModInt = MInt<0>;
  ModInt::set_mod(998244353);
  NTT<0> ntt;
  FPS<ModInt>::set_mul([&](const std::vector<ModInt> &a, const std::vector<ModInt> &b) -> std::vector<ModInt> {
    return ntt.convolution(a, b);
  });
  int n;
  std::cin >> n;
  std::vector<ModInt> x(n), y(n);
  for (int i = 0; i < n; ++i) std::cin >> x[i];
  for (int i = 0; i < n; ++i) std::cin >> y[i];
  FPS<ModInt> c = polynomial_interpolation<FPS>(x, y);
  for (int i = 0; i < n; ++i) std::cout << c[i] << " \n"[i + 1 == n];
  return 0;
}
