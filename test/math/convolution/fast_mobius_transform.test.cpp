/*
 * @title 数学/畳み込み/高速メビウス変換
 *
 * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2446
 * verification-helper: ERROR 1e-7
 */

#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>

#include "emthrm/math/convolution/fast_mobius_transform.hpp"

int main() {
  int n;
  long long m;
  std::cin >> n >> m;
  std::vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  std::vector<double> p(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> p[i];
    p[i] /= 100;
  }
  std::vector<long long> g(1 << n, 0);
  for (int i = 1; i < (1 << n); ++i) {
    long long l = 1;
    for (int j = 0; j < n; ++j) {
      if (i >> j & 1) {
        l /= std::gcd(l, a[j]);
        if (l > m / a[j]) {
          l = m + 1;
          break;
        }
        l *= a[j];
      }
    }
    g[i] = m / l;
  }
  g = emthrm::fast_mobius_transform<false>(g);
  double ans = 0;
  for (int bit = 0; bit < (1 << n); ++bit) {
    double prob = 1;
    for (int i = 0; i < n; ++i) {
      prob *= (bit >> i & 1 ? p[i] : 1 - p[i]);
    }
    ans += prob * std::abs(g[bit]);
  }
  std::cout << std::fixed << std::setprecision(8) << ans << '\n';
  return 0;
}
