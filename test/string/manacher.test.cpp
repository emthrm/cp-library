/*
 * @brief 文字列/Manacher
 */
#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"

#include <iostream>
#include <string>

#include "emthrm/string/manacher.hpp"

int main() {
  std::string s;
  std::cin >> s;
  const int n = s.length();
  emthrm::Manacher manacher(s);
  for (int i = 0; i < n; ++i) {
    std::cout << (manacher.odd(i) - 1) * 2 + 1;
    if (i + 1 == n) [[unlikely]] {
      std::cout << '\n';
    } else {
      std::cout << ' ' << manacher.even(i) * 2 << ' ';
    }
  }
  return 0;
}
