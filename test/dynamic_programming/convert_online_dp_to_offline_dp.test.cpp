/*
 * @title 動的計画法/オフライン・オンライン変換
 *
 * verification-helper: PROBLEM https://atcoder.jp/contests/abc213/tasks/abc213_h
 */

#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>

#include "emthrm/dynamic_programming/convert_online_dp_to_offline_dp.hpp"
#include "emthrm/math/convolution/number_theoretic_transform.hpp"
#include "emthrm/math/modint.hpp"

int main() {
  constexpr int MOD = 998244353;
  using ModInt = emthrm::MInt<MOD>;
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
  std::vector<std::vector<ModInt>> dp(n, std::vector<ModInt>(t + 1, 0));
  dp[0][0] = 1;
  const std::function<void(int, int, int)> induce =
      [m, &a, &b, &p, &dp](const int l, const int mid, const int r) -> void {
        static emthrm::NumberTheoreticTransform<MOD> ntt;
        for (int id = 0; id < m; ++id) {
          std::vector<ModInt> dp_id(mid - l), p_id(r - l);
          std::copy(std::next(dp[a[id]].begin(), l),
                    std::next(dp[a[id]].begin(), mid), dp_id.begin());
          std::copy(p[id].begin(), std::next(p[id].begin(), r - l),
                    p_id.begin());
          std::vector<ModInt> c = ntt.convolution(dp_id, p_id);
          for (int i = mid; i < r; ++i) {
            dp[b[id]][i] += c[i - l];
          }
          std::copy(std::next(dp[b[id]].begin(), l),
                    std::next(dp[b[id]].begin(), mid), dp_id.begin());
          c = ntt.convolution(dp_id, p_id);
          for (int i = mid; i < r; ++i) {
            dp[a[id]][i] += c[i - l];
          }
        }
      };
  emthrm::convert_online_dp_to_offline_dp(t + 1, induce);
  std::cout << dp[0][t] << '\n';
  return 0;
}
