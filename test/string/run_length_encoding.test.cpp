/*
 * @title 文字列/ランレングス圧縮
 *
 * verification-helper: IGNORE
 * verification-helper: PROBLEM https://atcoder.jp/contests/abc143/tasks/abc143_c
 */

#include <iostream>
#include <string>

#include "emthrm/string/run_length_encoding.hpp"

int main() {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  std::cout << emthrm::run_length_encoding(s).size() << '\n';
  return 0;
}
