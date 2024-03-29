/*
 * @title グラフ/フロー/マッチング/Hopcroft–Karp algorithm
 *
 * verification-helper: PROBLEM https://judge.yosupo.jp/problem/bipartitematching
 */

#include <iostream>

#include "emthrm/graph/flow/matching/hopcroft-karp_algorithm.hpp"

int main() {
  int l, r, m;
  std::cin >> l >> r >> m;
  emthrm::HopcroftKarp hopcroft_karp(l, r);
  while (m--) {
    int a, b;
    std::cin >> a >> b;
    hopcroft_karp.add_edge(a, b);
  }
  std::cout << hopcroft_karp.solve() << '\n';
  for (int i = 0; i < l; ++i) {
    if (hopcroft_karp.match[i] != -1) {
      std::cout << i << ' ' << hopcroft_karp.match[i] - l << '\n';
    }
  }
  return 0;
}
