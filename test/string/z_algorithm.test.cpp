/*
 * @brief 文字列/Z algorithm
 */
#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include <iostream>
#include <string>
#include <vector>

#include "../../string/z_algorithm.hpp"

int main() {
  std::string s;
  std::cin >> s;
  const std::vector<int> ans = z_algorithm(s);
  for (int i = 0; i < s.length(); ++i) {
    std::cout << ans[i] << " \n"[i + 1 == s.length()];
  }
  return 0;
}
