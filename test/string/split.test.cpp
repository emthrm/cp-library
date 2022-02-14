/*
 * @brief 文字列/文字列の分割
 */
#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc033/tasks/abc033_c"

#include <iostream>
#include <string>
#include <vector>

#include "../../string/split.hpp"

int main() {
  std::string s;
  std::cin >> s;
  int ans = 0;
  for (const std::string& terms : split(s, "+")) {
    bool is_0 = false;
    for (int i = 0; i < terms.length(); i += 2) {
      is_0 |= terms[i] == '0';
    }
    ans += !is_0;
  }
  std::cout << ans << '\n';
  return 0;
}
