/*
 * @brief 数学/畳み込み/添え字 gcd での畳み込み
 */
#define PROBLEM "https://atcoder.jp/contests/agc038/tasks/agc038_c"

#include <iostream>
#include <vector>

#include "../../../math/convolution/gcd_convolution.hpp"
#include "../../../math/modint.hpp"

int main() {
  using ModInt = MInt<0>;
  ModInt::set_mod(998244353);
  constexpr int N = 1000000;
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  std::vector<ModInt> b(N + 1, 0);
  for (int i = 0; i < n; ++i) {
    b[a[i]] += a[i];
  }
  std::vector<ModInt> c = gcd_convolution(b, b);
  for (int i = 0; i < n; ++i) {
    c[a[i]] -= static_cast<long long>(a[i]) * a[i];
  }
  for (int i = 1; i <= N; ++i) {
    c[i] /= 2;
  }
  ModInt ans = 0;
  for (int i = 1; i <= N; ++i) {
    ans += c[i] / i;
  }
  std::cout << ans << '\n';
  return 0;
}
