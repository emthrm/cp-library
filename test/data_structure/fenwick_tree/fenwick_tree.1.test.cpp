/*
 * @brief データ構造/Fenwick tree/Fenwick tree (sum(left, right))
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include <iostream>

#include "emthrm/data_structure/fenwick_tree/fenwick_tree.hpp"

int main() {
  int n, q;
  std::cin >> n >> q;
  emthrm::FenwickTree<long long> bit(n);
  while (q--) {
    int com, x, y;
    std::cin >> com >> x >> y;
    --x;
    if (com == 0) {
      bit.add(x, y);
    } else if (com == 1) {
      --y;
      std::cout << bit.sum(x, y + 1) << '\n';
    }
  }
  return 0;
}
