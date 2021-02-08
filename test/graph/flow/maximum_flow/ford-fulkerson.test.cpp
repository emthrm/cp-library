/*
 * @brief グラフ/フロー/最大流/Ford-Fulkerson 法
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"

#include <iostream>
#include <limits>
#include "../../../../graph/flow/maximum_flow/ford-fulkerson.hpp"

int main() {
  int v, e;
  std::cin >> v >> e;
  FordFulkerson<long long> ff(v);
  while (e--) {
    int ui, vi, ci;
    std::cin >> ui >> vi >> ci;
    ff.add_edge(ui, vi, ci);
  }
  std::cout << ff.maximum_flow(0, v - 1, std::numeric_limits<long long>::max()) << '\n';
  return 0;
}
