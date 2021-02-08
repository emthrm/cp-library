/*
 * @brief 数学/連立線形合同式
 */
#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/ddcc2019-qual/tasks/ddcc2018_qual_d"

#include <iostream>
#include <tuple>
#include <vector>
#include "../../math/linear_congruence.hpp"

int main() {
  constexpr int N = 29;
  std::vector<long long> a(N), m(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> a[i];
    m[i] = i + 1;
  }
  long long ans, mod; std::tie(ans, mod) = linear_congruence(std::vector<long long>(N, 1), a, m);
  if (mod == -1 || ans > 1000000000000) {
    std::cout << "invalid\n";
    return 0;
  }
  for (int i = 0; i < N; ++i) {
    int cnt = 0;
    long long tmp = ans;
    while (tmp > 0) {
      cnt += tmp % (i + 2);
      tmp /= i + 2;
    }
    if (cnt != a[i]) {
      std::cout << "invalid\n";
      return 0;
    }
  }
  std::cout << ans << "\n";
  return 0;
}
