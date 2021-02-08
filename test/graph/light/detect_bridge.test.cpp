#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B"

#include <algorithm>
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>
#include "../../../graph/light/detect_bridge.hpp"

int main() {
  int v, e;
  std::cin >> v >> e;
  std::vector<std::vector<int>> graph(v);
  while (e--) {
    int s, t;
    std::cin >> s >> t;
    graph[s].emplace_back(t);
    graph[t].emplace_back(s);
  }
  std::vector<std::pair<int, int>> bridges = detect_bridge(graph);
  std::sort(bridges.begin(), bridges.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b) -> bool {
    int as, ad; std::tie(as, ad) = a;
    int bs, bd; std::tie(bs, bd) = b;
    return as != bs ? as < bs : ad < bd;
  });
  for (const std::pair<int, int> &e : bridges) std::cout << e.first << ' ' << e.second << '\n';
  return 0;
}
