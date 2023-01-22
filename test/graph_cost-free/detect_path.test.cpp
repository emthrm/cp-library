#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/past202112-open/tasks/past202112_g"

#include <algorithm>
#include <iostream>
#include <vector>

#include "emthrm/graph_cost-free/detect_path.hpp"

int main() {
  int n, q;
  std::cin >> n >> q;
  std::vector<std::vector<int>> graph(n);
  while (q--) {
    int type, u, v;
    std::cin >> type >> u >> v;
    --u; --v;
    if (type == 1) {
      const auto it = std::find(graph[u].begin(), graph[u].end(), v);
      if (it != graph[u].end()) {
        graph[u].erase(it);
        graph[v].erase(std::find(graph[v].begin(), graph[v].end(), u));
      } else {
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
      }
    } else if (type == 2) {
      std::cout << (emthrm::detect_path(graph, u, v).empty() ?
                    "No\n" : "Yes\n");
    }
  }
  return 0;
}
