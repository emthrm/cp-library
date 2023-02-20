/*
 * @brief グラフ/道の検出
 */
#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/past202112-open/tasks/past202112_g"

#include <algorithm>
#include <iostream>
#include <vector>

#include "emthrm/graph/detect_path.hpp"
#include "emthrm/graph/edge.hpp"

int main() {
  int n, q;
  std::cin >> n >> q;
  std::vector<std::vector<emthrm::Edge<bool>>> graph(n);
  while (q--) {
    int type, u, v;
    std::cin >> type >> u >> v;
    --u; --v;
    if (type == 1) {
      const auto adj = std::find_if(
          graph[u].begin(), graph[u].end(),
          [v](const emthrm::Edge<bool>& e) -> bool { return e.dst == v; });
      if (adj != graph[u].end()) {
        graph[u].erase(adj);
        graph[v].erase(std::find_if(
            graph[v].begin(), graph[v].end(),
            [u](const emthrm::Edge<bool>& e) -> bool { return e.dst == u; }));
      } else {
        graph[u].emplace_back(u, v);
        graph[v].emplace_back(v, u);
      }
    } else if (type == 2) {
      std::cout << (emthrm::detect_path(graph, u, v).empty() ?
                    "No\n" : "Yes\n");
    }
  }
  return 0;
}
