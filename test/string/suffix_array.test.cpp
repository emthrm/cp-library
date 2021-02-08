/*
 * @brief 文字列/接尾辞配列
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include <iostream>
#include <string>
#include "../../string/suffix_array.hpp"

int main() {
  std::string t, p;
  std::cin >> t >> p;
  for (int ans : SuffixArray<>(t).match(p)) std::cout << ans << '\n';
  return 0;
}
