/*
 * @title データ構造/Fenwick tree/Fenwick tree (lower_bound(val))
 */
#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/arc033/tasks/arc033_3"

#include <iostream>

#include "emthrm/data_structure/fenwick_tree/fenwick_tree.hpp"

int main() {
  constexpr int M = 200000;
  emthrm::FenwickTree<int> bit(M + 1);
  int q;
  std::cin >> q;
  while (q--) {
    int t, x;
    std::cin >> t >> x;
    if (t == 1) {
      bit.add(x, 1);
    } else if (t == 2) {
      const int ans = bit.lower_bound(x);
      std::cout << ans << '\n';
      bit.add(ans, -1);
    }
  }
  return 0;
}
