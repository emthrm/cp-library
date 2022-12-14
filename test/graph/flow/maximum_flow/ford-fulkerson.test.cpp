/*
 * @brief グラフ/フロー/最大流/Ford–Fulkerson 法
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"

#include <iostream>

#include "emthrm/graph/flow/maximum_flow/ford-fulkerson.hpp"

int main() {
  int v, e;
  std::cin >> v >> e;
  FordFulkerson<long long> ford_fulkerson(v);
  while (e--) {
    int u_i, v_i, c_i;
    std::cin >> u_i >> v_i >> c_i;
    ford_fulkerson.add_edge(u_i, v_i, c_i);
  }
  std::cout << ford_fulkerson.maximum_flow(0, v - 1) << '\n';
  return 0;
}
