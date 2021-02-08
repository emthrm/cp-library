/*
 * @brief 文字列/Manacher
 */
#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"

#include <iostream>
#include <string>
#include "../../string/manacher.hpp"

int main() {
  std::string s;
  std::cin >> s;
  int n = s.length();
  Manacher manacher(s);
  for (int i = 0; i < n; ++i) {
    std::cout << (manacher.odd(i) - 1) * 2 + 1;
    if (i + 1 == n) {
      std::cout << '\n';
    } else {
      std::cout << ' ' << manacher.even(i) * 2 << ' ';
    }
  }
  return 0;
}
