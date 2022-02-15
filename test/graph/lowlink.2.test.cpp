/*
 * @brief グラフ/lowlink (関節点)
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A"

#include <algorithm>
#include <iostream>
#include <vector>

#include "../../graph/edge.hpp"
#include "../../graph/lowlink.hpp"

int main() {
  int v, e;
  std::cin >> v >> e;
  std::vector<std::vector<Edge<bool>>> graph(v);
  while (e--) {
    int s, t;
    std::cin >> s >> t;
    graph[s].emplace_back(s, t);
    graph[t].emplace_back(t, s);
  }
  std::vector<int> articulation_points =
      Lowlink<bool>(graph).articulation_points;
  std::sort(articulation_points.begin(), articulation_points.end());
  for (const int articulation_point : articulation_points) {
    std::cout << articulation_point << '\n';
  }
  return 0;
}
