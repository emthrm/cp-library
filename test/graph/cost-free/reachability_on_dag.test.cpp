#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/typical90/tasks/typical90_bg"

#include <iostream>
#include <vector>

#include "../../../graph/cost-free/reachability_on_dag.hpp"

int main() {
  int n, m, q;
  std::cin >> n >> m >> q;
  std::vector<std::vector<int>> graph(n);
  while (m--) {
    int x, y;
    std::cin >> x >> y;
    --x; --y;
    graph[x].emplace_back(y);
  }
  std::vector<int> a(q), b(q);
  for (int i = 0; i < q; ++i) {
    std::cin >> a[i] >> b[i];
    --a[i]; --b[i];
  }
  for (const bool ans : reachability_on_dag(graph, a, b)) {
    std::cout << (ans ? "Yes\n" : "No\n");
  }
  return 0;
}
