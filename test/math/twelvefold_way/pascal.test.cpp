/*
 * @title 数学/写像12相/パスカルの三角形
 *
 * verification-helper: PROBLEM https://atcoder.jp/contests/abc254/tasks/abc254_b
 */

#include <iostream>
#include <vector>

#include "emthrm/math/twelvefold_way/pascal.hpp"

int main() {
  int n;
  std::cin >> n;
  const std::vector<std::vector<int>> ans = emthrm::pascal<int>(n - 1);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      std::cout << ans[i][j] << " \n"[j == i];
    }
  }
  return 0;
}
