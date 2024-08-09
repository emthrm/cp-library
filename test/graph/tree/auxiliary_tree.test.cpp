/*
 * @title グラフ/木/指定された頂点たちの最小共通祖先関係を保って木を圧縮してできる補助的な木
 *
 * verification-helper: IGNORE
 * verification-helper: PROBLEM https://atcoder.jp/contests/typical90/tasks/typical90_ai
 */

#include <iostream>
#include <ranges>
#include <vector>

#include "emthrm/graph/edge.hpp"
#include "emthrm/graph/tree/auxiliary_tree.hpp"

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<emthrm::Edge<int>>> graph(n);
  for (const int i : std::views::iota(0, n - 1)) {
    int a, b;
    std::cin >> a >> b;
    --a; --b;
    graph[a].emplace_back(a, b, 1);
    graph[b].emplace_back(b, a, 1);
  }
  const emthrm::AuxiliaryTree<int> auxiliary_tree(graph);
  int q;
  std::cin >> q;
  while (q--) {
    int k;
    std::cin >> k;
    std::vector<int> v(k);
    for (int& v_i : v) std::cin >> v_i, --v_i;
    int ans = 0;
    for (const std::vector<emthrm::Edge<int>>& edges
         : auxiliary_tree.query(v).first) {
      for (const emthrm::Edge<int>& e : edges) ans += e.cost;
    }
    std::cout << ans / 2 << '\n';
  }
  return 0;
}
