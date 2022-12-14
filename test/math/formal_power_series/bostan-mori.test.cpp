/*
 * @brief 数学/形式的冪級数/Bostan–Mori のアルゴリズム
 */
#define PROBLEM "https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence"

#include <iostream>

#include "emthrm/math/convolution/number_theoretic_transform.hpp"
#include "emthrm/math/formal_power_series/formal_power_series.hpp"
#include "emthrm/math/formal_power_series/nth_term_of_linear_recurrence_sequence.hpp"
#include "emthrm/math/modint.hpp"

int main() {
  using ModInt = MInt<0>;
  ModInt::set_mod(998244353);
  FormalPowerSeries<ModInt>::set_mult(
      [](const std::vector<ModInt>& a, const std::vector<ModInt>& b)
          -> std::vector<ModInt> {
        static NumberTheoreticTransform<0> ntt;
        return ntt.convolution(a, b);
      });
  int d;
  long long k;
  std::cin >> d >> k;
  FormalPowerSeries<ModInt> a(d - 1), c(d);
  c[0] = 1;
  for (int i = 0; i < d; ++i) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= d; ++i) {
    std::cin >> c[i];
    c[i] = -c[i];
  }
  std::cout << nth_term_of_linear_recurrence_sequence(a, c, k) << '\n';
  return 0;
}
