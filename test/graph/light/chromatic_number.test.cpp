#define PROBLEM "https://judge.yosupo.jp/problem/chromatic_number"

#include <iostream>
#include <vector>

#include "../../../graph/light/chromatic_number.hpp"

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> graph(n);
  while (m--) {
    int u, v;
    std::cin >> u >> v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  std::cout << chromatic_number(graph) << '\n';
  return 0;
}
