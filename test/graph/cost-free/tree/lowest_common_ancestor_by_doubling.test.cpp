#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"

#include <iostream>
#include <vector>

#include "emthrm/graph/cost-free/tree/lowest_common_ancestor_by_doubling.hpp"

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> graph(n);
  for (int i = 0; i < n; ++i) {
    int k;
    std::cin >> k;
    while (k--) {
      int c;
      std::cin >> c;
      graph[i].emplace_back(c);
      graph[c].emplace_back(i);
    }
  }
  emthrm::LowestCommonAncestorByDoubling lowest_common_ancestor(graph);
  lowest_common_ancestor.build(0);
  int q;
  std::cin >> q;
  while (q--) {
    int u, v;
    std::cin >> u >> v;
    std::cout << lowest_common_ancestor.query(u, v) << '\n';
  }
  return 0;
}
