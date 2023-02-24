/*
 * @title グラフ/Prim 法
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"

#include <iostream>
#include <vector>

#include "emthrm/graph/edge.hpp"
#include "emthrm/graph/prim.hpp"

int main() {
  int v, e;
  std::cin >> v >> e;
  std::vector<std::vector<emthrm::Edge<long long>>> edge(v);
  while (e--) {
    int s, t, w;
    std::cin >> s >> t >> w;
    edge[s].emplace_back(s, t, w);
    edge[t].emplace_back(t, s, w);
  }
  std::cout << emthrm::prim(edge) << '\n';
  return 0;
}
