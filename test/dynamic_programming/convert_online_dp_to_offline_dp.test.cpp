/*
 * @brief 動的計画法/オフライン・オンライン変換
 */
#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc213/tasks/abc213_h"

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include "../../math/modint.hpp"
#include "../../math/convolution/number_theoretic_transform.hpp"
#include "../../dynamic_programming/convert_online_dp_to_offline_dp.hpp"

int main() {
  using ModInt = MInt<0>;
  ModInt::set_mod(998244353);
  int n, m, t;
  std::cin >> n >> m >> t;
  std::vector<int> a(m), b(m);
  std::vector<std::vector<ModInt>> p(m, std::vector<ModInt>(t + 1, 0));
  for (int i = 0; i < m; ++i) {
    std::cin >> a[i] >> b[i];
    --a[i]; --b[i];
    for (int j = 1; j <= t; ++j) {
      std::cin >> p[i][j];
    }
  }
  std::vector<std::vector<ModInt>> dp(n, std::vector(t + 1, ModInt(0)));
  dp[0][0] = 1;
  NumberTheoreticTransform<0> ntt;
  std::function<void(int, int, int)> induce = [m, &dp, &a, &b, &p, &ntt](int l, int mid, int r) -> void {
    for (int id = 0; id < m; ++id) {
      std::vector<ModInt> dp_id(mid - l), p_id(r - l);
      std::copy(dp[a[id]].begin() + l, dp[a[id]].begin() + mid, dp_id.begin());
      std::copy(p[id].begin(), p[id].begin() + (r - l), p_id.begin());
      std::vector<ModInt> c = ntt.convolution(dp_id, p_id);
      for (int i = mid; i < r; ++i) {
        dp[b[id]][i] += c[i - l];
      }
      std::copy(dp[b[id]].begin() + l, dp[b[id]].begin() + mid, dp_id.begin());
      c = ntt.convolution(dp_id, p_id);
      for (int i = mid; i < r; ++i) {
        dp[a[id]][i] += c[i - l];
      }
    }
  };
  convert_online_dp_to_offline_dp(t + 1, induce);
  std::cout << dp[0][t] << '\n';
  return 0;
}
