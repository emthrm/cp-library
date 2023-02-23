/*
 * @brief 文字列/Z algorithm
 */
#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "emthrm/string/z_algorithm.hpp"

int main() {
  std::string s;
  std::cin >> s;
  const std::vector<int> ans = emthrm::z_algorithm(s);
  for (int i = 0; std::cmp_less(i, s.length()); ++i) {
    std::cout << ans[i] << " \n"[std::cmp_equal(i + 1, s.length())];
  }
  return 0;
}
