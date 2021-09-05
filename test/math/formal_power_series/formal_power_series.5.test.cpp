/*
 * @brief 数学/形式的冪級数/形式的冪級数 (mod_pow(exponend, md))
 */
#define PROBLEM "https://atcoder.jp/contests/abc135/tasks/abc135_d"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "../../../math/modint.hpp"
#include "../../../math/formal_power_series/formal_power_series.hpp"
#include "../../../math/convolution/mod_convolution.hpp"

int main() {
  using ModInt = MInt<0>;
  ModInt::set_mod(1000000007);
  FormalPowerSeries<ModInt>::set_mul([&](const std::vector<ModInt> &a, const std::vector<ModInt> &b) -> std::vector<ModInt> {
    return mod_convolution(a, b);
  });
  constexpr int D = 6, M = 13;
  std::string s;
  std::cin >> s;
  std::reverse(s.begin(), s.end());
  std::vector<int> cnt(D, 0);
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == '?') {
      ++cnt[i % D];
    }
  }
  std::vector<FormalPowerSeries<ModInt>> f(D, FormalPowerSeries<ModInt>(M));
  FormalPowerSeries<ModInt> md(M);
  md[0] = -1;
  md[M] = 1;
  for (int i = 0; i < D; ++i) {
    int base = 1;
    for (int j = 0; j < i; ++j) {
      base *= 10;
    }
    for (int j = 0; j < 10; ++j) {
      ++f[i][base * j % M];
    }
    f[i] = f[i].mod_pow(cnt[i], md);
  }
  for (int i = 1; i < D; ++i) {
    f[0] *= f[i];
  }
  f[0] %= md;
  int idx = D - 1, w = 1;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] != '?') {
      (idx += M - w * (s[i] - '0') % M) %= M;
    }
    (w *= 10) %= M;
  }
  std::cout << f[0][idx] << '\n';
  return 0;
}
