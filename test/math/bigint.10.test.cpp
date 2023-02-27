/*
 * @title 数学/多倍長整数（桁数）
 *
 * verification-helper: IGNORE
 * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0015
 */

#include <iostream>

#include "emthrm/math/bigint.hpp"

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    emthrm::BigInt<> a, b;
    std::cin >> a >> b;
    emthrm::BigInt<> ans = a + b;
    if (ans.length() > 80) {
      std::cout << "overflow\n";
    } else {
      std::cout << ans << '\n';
    }
  }
  return 0;
}
