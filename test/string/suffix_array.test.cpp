/*
 * @title 文字列/接尾辞配列
 *
 * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
 */

#include <iostream>
#include <string>

#include "emthrm/string/suffix_array.hpp"

int main() {
  std::string t, p;
  std::cin >> t >> p;
  for (const int ans : emthrm::SuffixArray<>(t).match(&p)) {
    std::cout << ans << '\n';
  }
  return 0;
}
