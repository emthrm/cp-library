/*
 * @title 数学/行列/バイナリ行列/バイナリ行列
 *
 * verification-helper: PROBLEM https://judge.yosupo.jp/problem/matrix_product_mod_2
 */

#include <algorithm>
#include <bitset>
#include <iostream>
#include <ranges>
#include <string>

#include "emthrm/math/matrix/binary_matrix/binary_matrix.hpp"

int main() {
  constexpr int N = 4096;
  int n, m, k;
  std::cin >> n >> m >> k;
  emthrm::BinaryMatrix<N> a(n, m), b(m, k);
  for (const int i : std::views::iota(0, n)) {
    std::string s;
    std::cin >> s;
    std::ranges::reverse(s);
    a[i] = std::bitset<N>(s);
  }
  for (const int i : std::views::iota(0, m)) {
    std::string s;
    std::cin >> s;
    std::ranges::reverse(s);
    b[i] = std::bitset<N>(s);
  }
  const emthrm::BinaryMatrix<N> c = a * b;
  for (const int i : std::views::iota(0, n)) {
    for (const int j : std::views::iota(0, k)) {
      std::cout << (c[i].test(j) ? '1' : '0');
    }
    std::cout << '\n';
  }
  return 0;
}
