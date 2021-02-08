#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include <iostream>
#include <vector>
#include "../../../graph/light/scc.hpp"

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> graph(n);
  while (m--) {
    int a, b;
    std::cin >> a >> b;
    graph[a].emplace_back(b);
  }
  SCC scc(graph, true);
  int k = scc.vertices.size();
  std::cout << k << '\n';
  for (int i = 0; i < k; ++i) {
    int l = scc.vertices[i].size();
    std::cout << l << ' ';
    for (int j = 0; j < l; ++j) std::cout << scc.vertices[i][j] << " \n"[j + 1 == l];
  }
  return 0;
}
