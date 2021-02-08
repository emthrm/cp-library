/*
 * @brief データ構造/BIT/binary indexed tree (sum(left, right))
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include <iostream>
#include "../../../data_structure/bit/bit.hpp"

int main() {
  int n, q;
  std::cin >> n >> q;
  BIT<long long> bit(n);
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
