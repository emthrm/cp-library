/*
 * @title データ構造/sparse table
 *
 * verification-helper: PROBLEM https://judge.yosupo.jp/problem/staticrmq
 */

#include <algorithm>
#include <iostream>
#include <vector>

#include "emthrm/data_structure/sparse_table.hpp"

int main() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  emthrm::SparseTable<int> dst(
      a, [](const int a, const int b) -> int { return std::min(a, b); });
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    std::cout << dst.query(l, r) << '\n';
  }
  return 0;
}
