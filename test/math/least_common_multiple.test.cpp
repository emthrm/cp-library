/*
 * @brief 数学/最小公倍数
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C"

#include <algorithm>
#include <iostream>
#include "../../math/least_common_multiple.hpp"

int main() {
  int n;
  std::cin >> n;
  int ans = 1;
  while (n--) {
    int a;
    std::cin >> a;
    ans = __lcm(ans, a);
  }
  std::cout << ans << '\n';
  return 0;
}
