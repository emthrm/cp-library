/*
 * @title 文字列/longest common prefix
 *
 * verification-helper: PROBLEM https://judge.yosupo.jp/problem/longest_common_substring
 */

#include <iostream>
#include <string>
#include <utility>

#include "emthrm/string/longest_common_prefix.hpp"

int main() {
  std::string s, t;
  std::cin >> s >> t;
  const int s_len = s.length(), t_len = t.length();
  const std::string u = s + '$' + t;
  const emthrm::LongestCommonPrefix lcp(u);
  int ans = 0, a = -1, c = -1;
  for (int i = 2; i < s_len + 1 + t_len; ++i) {
    if ((lcp.sa[i] < s_len) != (lcp.sa[i + 1] < s_len) &&
        ans < lcp.lcp_array[i]) {
      ans = lcp.lcp_array[i];
      a = lcp.sa[i];
      c = lcp.sa[i + 1];
    }
  }
  if (ans == 0) {
    std::cout << "0 0 0 0\n";
  } else {
    if (a > c) std::swap(a, c);
    c -= s_len + 1;
    std::cout << a << ' ' << a + ans << ' ' << c << ' ' << c + ans << '\n';
  }
  return 0;
}
