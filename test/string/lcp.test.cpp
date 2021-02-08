/*
 * @brief 文字列/longest common prefix
 */
#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"

#include <iostream>
#include <string>
#include "../../string/lcp.hpp"

int main() {
  std::string s;
  std::cin >> s;
  int n = s.length();
  LCP<> lcp(s);
  long long ans = static_cast<long long>(n) * (n + 1) / 2;
  for (int e : LCP<>(s).lcp_array) ans -= e;
  std::cout << ans << '\n';
  return 0;
}
