/*
 * @brief 数学/最小公倍数
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C"

#include <iostream>

#if __cplusplus >= 201703L
#include <numeric>
#else
#include "emthrm/math/least_common_multiple.hpp"
#endif

int main() {
  int n;
  std::cin >> n;
  int ans = 1;
  while (n--) {
    int a;
    std::cin >> a;
#if __cplusplus >= 201703L
    ans = std::lcm(ans, a);
#else
    ans = emthrm::__lcm(ans, a);
#endif
  }
  std::cout << ans << '\n';
  return 0;
}
