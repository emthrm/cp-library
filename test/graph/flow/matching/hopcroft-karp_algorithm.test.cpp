/*
 * @brief グラフ/フロー/マッチング/Hopcroft-Karp algorithm
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A"

#include <iostream>
#include "../../../../graph/flow/matching/hopcroft-karp_algorithm.hpp"

int main() {
  int x, y, e;
  std::cin >> x >> y >> e;
  HopcroftKarp hk(x, y);
  while (e--) {
    int xi, yi;
    std::cin >> xi >> yi;
    hk.add_edge(xi, yi);
  }
  std::cout << hk.solve() << '\n';
  return 0;
}
