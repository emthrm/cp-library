/*
 * @brief 数学/きたまさ法
 */
#define PROBLEM "https://yukicoder.me/problems/no/194"

#include <iostream>
#include <numeric>
#include <vector>

#include "../../math/kita_masa.hpp"
#include "../../math/modint.hpp"

int main() {
  using ModInt = MInt<0>;
  ModInt::set_mod(1000000007);
  int n;
  long long k;
  std::cin >> n >> k;
  --k;
  std::vector<ModInt> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  ModInt sum = std::accumulate(a.begin(), a.end(), ModInt(0));
  if (2 <= n && n <= 10000 && n < k && k < 1000000) {
    a.resize(k + 1);
    for (int i = n; i <= k; ++i) {
      a[i] = sum;
      sum = sum + a[i] - a[i - n];
    }
    std::cout << a[k] << ' '
              << std::accumulate(a.begin(), a.end(), ModInt(0)) << '\n';
  } else {
    std::cout << kita_masa(std::vector<ModInt>(n, 1), a, k) << ' ';
    std::vector<ModInt> c(n + 1, 0);
    c[0] = -1;
    c[n] = 2;
    a.emplace_back(sum);
    for (int i = 1; i < n + 1; ++i) {
      a[i] += a[i - 1];
    }
    std::cout << kita_masa(c, a, k) << '\n';
  }
  return 0;
}
