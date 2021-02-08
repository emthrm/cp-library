/*
 * @brief グラフ/フロー/マッチング/二部グラフの最大マッチング
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0334"

#include <iostream>
#include "../../../../graph/flow/matching/bipartite_matching.hpp"

int main() {
  int n;
  std::cin >> n;
  --n;
  BipartiteMatching bm(n << 1);
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
    int b;
    std::cin >> b;
    if (b == 1) bm.add_edge(j, n + i);
  }
  if (bm.solve() == n) {
    std::cout << "yes\n";
  } else {
    std::cout << "no\n";
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    std::cout << bm.push_back(i) - n + 1 << '\n';
    bm.fix(i);
  }
  return 0;
}
