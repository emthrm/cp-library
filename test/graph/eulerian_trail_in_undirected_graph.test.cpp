/*
 * @brief グラフ/オイラー路 無向グラフ版
 */
#define IGNORE
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0086"

#include <algorithm>
#include <iostream>
#include <vector>
#include "../../graph/eulerian_trail_in_undirected_graph.hpp"

int main() {
  int ai, bi;
  while (std::cin >> ai >> bi) {
    --ai; --bi;
    std::vector<int> a{ai}, b{bi};
    while (true) {
      std::cin >> ai >> bi;
      if (ai == 0 && bi == 0) break;
      --ai; --bi;
      a.emplace_back(ai);
      b.emplace_back(bi);
    }
    int n = std::max(*std::max_element(a.begin(), a.end()), *std::max_element(b.begin(), b.end())) + 1;
    EulerianTrailInUndirectedGraph et(n);
    for (int i = 0; i < a.size(); ++i) et.add_edge(a[i], b[i]);
    std::cout << (et.build(0) && et.trail.back() == 1 ? "OK\n" : "NG\n");
  }
  return 0;
}
