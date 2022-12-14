/*
 * @brief グラフ/フロー/マッチング/二部グラフの最大マッチング
 */
#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A"

#include <iostream>

#include "emthrm/graph/flow/matching/bipartite_matching.hpp"

int main() {
  int x, y, e;
  std::cin >> x >> y >> e;
  BipartiteMatching bipartite_matching(x + y);
  while (e--) {
    int x_i, y_i;
    std::cin >> x_i >> y_i;
    bipartite_matching.add_edge(x_i, y_i + x);
  }
  std::cout << bipartite_matching.solve() << '\n';
  return 0;
}
