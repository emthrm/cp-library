/*
 * @brief データ構造/Fenwick tree/区間加算クエリ対応 Fenwick tree
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"

#include <iostream>
#include "../../../data_structure/fenwick_tree/fenwick_tree_supporting_range_add_query.hpp"

int main() {
  int n, q;
  std::cin >> n >> q;
  FenwickTreeSupportingRangeAddQuery<long long> bit(n);
  while (q--) {
    int kind, s, t;
    std::cin >> kind >> s >> t;
    --s; --t;
    if (kind == 0) {
      int x;
      std::cin >> x;
      bit.add(s, t + 1, x);
    } else if (kind == 1) {
      std::cout << bit.sum(s, t + 1) << '\n';
    }
  }
  return 0;
}
