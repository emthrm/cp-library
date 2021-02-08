/*
 * @brief 数学/osa_k 法
 */
#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc052/tasks/arc067_a"

#include <iostream>
#include <map>
#include <utility>
#include "../../math/modint.hpp"
#include "../../math/osa_k.hpp"

int main() {
  ModInt::set_mod(1000000007);
  int n;
  std::cin >> n;
  osa_k osa(n);
  std::map<int, int> mp;
  for (int i = 2; i <= n; ++i) {
    for (const std::pair<int, int> &pr : osa.query(i)) mp[pr.first] += pr.second;
  }
  ModInt ans = 1;
  for (const std::pair<int, int> &pr : mp) ans *= pr.second + 1;
  std::cout << ans << '\n';
  return 0;
}
