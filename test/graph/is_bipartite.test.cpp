/*
 * @brief グラフ/二部グラフ判定
 */
#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/code-festival-2017-qualb/tasks/code_festival_2017_qualb_c"

#include <iostream>
#include <vector>
#include "../../graph/edge.hpp"
#include "../../graph/is_bipartite.hpp"

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<Edge<bool>>> graph(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    std::cin >> a >> b;
    --a; --b;
    graph[a].emplace_back(a, b);
    graph[b].emplace_back(b, a);
  }
  std::vector<int> color;
  if (is_bipartite(graph, color)) {
    int black = 0, white = 0;
    for (int i = 0; i < n; ++i) ++(color[i] == 1 ? black : white);
    std::cout << static_cast<long long>(black) * white - m << '\n';
  } else {
    std::cout << static_cast<long long>(n) * (n - 1) / 2 - m << '\n';
  }
  return 0;
}
