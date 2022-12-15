/*
 * @brief 数学/形式的冪級数/ファウルハーバーの公式 形式的冪級数版
 */
#define PROBLEM "https://yukicoder.me/problems/no/665"

#include <iostream>
#include <vector>

#include "emthrm/math/convolution/mod_convolution.hpp"
#include "emthrm/math/formal_power_series/faulhaber_by_fps.hpp"
#include "emthrm/math/formal_power_series/formal_power_series.hpp"
#include "emthrm/math/modint.hpp"

int main() {
  using ModInt = emthrm::MInt<0>;
  ModInt::set_mod(1000000007);
  emthrm::FormalPowerSeries<ModInt>::set_mult(
      [](const std::vector<ModInt>& a, const std::vector<ModInt>& b)
          -> std::vector<ModInt> {
        return emthrm::mod_convolution(a, b);
      });
  long long n;
  int k;
  std::cin >> n >> k;
  std::cout << emthrm::faulhaber_by_fps<0>(n + 1, k) << '\n';
  return 0;
}
