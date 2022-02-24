/*
 * @brief グラフ/道の検出
 */
#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/past202112-open/tasks/past202112_g"

#include <iostream>
#include <iterator>
#include <vector>

#include "../../graph/detect_path.hpp"
#include "../../graph/edge.hpp"

int main() {
  int n, q;
  std::cin >> n >> q;
  std::vector<std::vector<Edge<bool>>> graph(n);
  while (q--) {
    int type, u, v;
    std::cin >> type >> u >> v;
    --u; --v;
    if (type == 1) {
      bool is_adjacent = false;
      for (auto it = graph[u].begin(); it != graph[u].end();
           it = std::next(it)) {
        if (it->dst == v) {
          graph[u].erase(it);
          is_adjacent = true;
          break;
        }
      }
      if (is_adjacent) {
        for (auto it = graph[v].begin(); it != graph[v].end();
             it = std::next(it)) {
          if (it->dst == u) {
            graph[v].erase(it);
            break;
          }
        }
      } else {
        graph[u].emplace_back(u, v);
        graph[v].emplace_back(v, u);
      }
    } else if (type == 2) {
      std::cout << (detect_path(graph, u, v).empty() ? "No\n" : "Yes\n");
    }
  }
  return 0;
}
