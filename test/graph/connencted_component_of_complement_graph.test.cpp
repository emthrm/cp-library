/*
 * @brief グラフ/補グラフの連結成分分解
 */
#define IGNORE
#define PROBLEM "https://codeforces.com/problemset/problem/1242/B"

#include <iostream>
#include <vector>

#include "emthrm/graph/connencted_component_of_complement_graph.hpp"

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<Edge<bool>>> graph(n);
  while (m--) {
    int a, b;
    std::cin >> a >> b;
    --a; --b;
    graph[a].emplace_back(a, b);
    graph[b].emplace_back(b, a);
  }
  UnionFind union_find = connencted_component_of_complement_graph(graph);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += union_find.root(i) == i;
  }
  std::cout << ans - 1 << '\n';
  return 0;
}
