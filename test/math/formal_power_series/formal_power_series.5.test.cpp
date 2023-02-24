/*
 * @title 数学/形式的冪級数/形式的冪級数 (mod_pow(exponend, md))
 */
#define PROBLEM "https://atcoder.jp/contests/abc135/tasks/abc135_d"

#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "emthrm/math/convolution/mod_convolution.hpp"
#include "emthrm/math/formal_power_series/formal_power_series.hpp"
#include "emthrm/math/modint.hpp"

int main() {
  using ModInt = emthrm::MInt<1000000007>;
  emthrm::FormalPowerSeries<ModInt>::set_mult(
      [](const std::vector<ModInt>& a, const std::vector<ModInt>& b)
          -> std::vector<ModInt> {
        return emthrm::mod_convolution(a, b);
      });
  constexpr int D = 6, M = 13;
  std::string s;
  std::cin >> s;
  std::reverse(s.begin(), s.end());
  int q[D]{};
  for (int i = 0; std::cmp_less(i, s.length()); ++i) {
    if (s[i] == '?') ++q[i % D];
  }
  std::vector<emthrm::FormalPowerSeries<ModInt>> f(
      D, emthrm::FormalPowerSeries<ModInt>(M));
  emthrm::FormalPowerSeries<ModInt> md(M);
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
    f[i] = f[i].mod_pow(q[i], md);
  }
  for (int i = 1; i < D; ++i) {
    f.front() *= f[i];
  }
  f.front() %= md;
  int idx = D - 1, w = 1;
  for (int i = 0; std::cmp_less(i, s.length()); ++i) {
    if (s[i] != '?') {
      idx = (idx - w * (s[i] - '0')) % M;
      if (idx < 0) idx += M;
    }
    w = w * 10 % M;
  }
  std::cout << f.front()[idx] << '\n';
  return 0;
}
