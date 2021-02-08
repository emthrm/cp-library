/*
 * @brief 数学/きたまさ法
 */
#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/tdpc/tasks/tdpc_fibonacci"

#include <iostream>
#include <vector>
#include "../../math/modint.hpp"
#include "../../math/kita_masa.hpp"

int main() {
  ModInt::set_mod(1000000007);
  int k, n;
  std::cin >> k >> n;
  std::vector<ModInt> c(k, 1), a(k, 1);
  std::cout << kita_masa(c, a, n - 1) << '\n';
  return 0;
}
