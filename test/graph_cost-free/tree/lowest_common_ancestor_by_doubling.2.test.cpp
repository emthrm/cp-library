/*
 * verification-helper: PROBLEM https://judge.yosupo.jp/problem/jump_on_tree
 */

#include <iostream>
#include <vector>

#include "emthrm/graph_cost-free/tree/lowest_common_ancestor_by_doubling.hpp"

int main() {
  int n, q;
  std::cin >> n >> q;
  std::vector<std::vector<int>> tree(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    std::cin >> a >> b;
    tree[a].emplace_back(b);
    tree[b].emplace_back(a);
  }
  emthrm::LowestCommonAncestorByDoubling lowest_common_ancestor(tree);
  lowest_common_ancestor.build();
  while (q--) {
    int s, t, i;
    std::cin >> s >> t >> i;
    std::cout << lowest_common_ancestor.jump(s, t, i) << '\n';
  }
  return 0;
}
