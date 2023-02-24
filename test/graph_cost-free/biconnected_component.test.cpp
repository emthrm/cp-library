/*
 * verification-helper: IGNORE
 * verification-helper: PROBLEM https://atcoder.jp/contests/nadafes2022_day2/tasks/nadafes2022_day2_h
 */

#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <set>
#include <utility>
#include <vector>

#include "emthrm/graph_cost-free/biconnected_component.hpp"

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> graph(n);
  while (m--) {
    int a, b;
    std::cin >> a >> b;
    --a; --b;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }
  emthrm::BiconnectedComponent<true> biconnected_component(graph);
  const int x = biconnected_component.articulation_points.size();
  const int y = biconnected_component.vertices.size();
  std::sort(biconnected_component.articulation_points.begin(),
            biconnected_component.articulation_points.end());
  std::vector<std::vector<int>> block_cut_tree(x + y);
  std::vector<int> weight(x + y, 0);
  for (int i = 0; i < n; ++i) {
    if (biconnected_component.id[i] == -1) {
      const int index =
          std::distance(biconnected_component.articulation_points.begin(),
                        std::lower_bound(
                            biconnected_component.articulation_points.begin(),
                            biconnected_component.articulation_points.end(),
                            i));
      for (const int block : biconnected_component.cutpoint[i]) {
        block_cut_tree[index].emplace_back(block + x);
        block_cut_tree[block + x].emplace_back(index);
      }
      ++weight[index];
    } else {
      ++weight[biconnected_component.id[i] + x];
    }
  }
  for (int i = 0; i < x + y; ++i) {
    std::sort(block_cut_tree[i].begin(), block_cut_tree[i].end());
    block_cut_tree[i].erase(
        std::unique(block_cut_tree[i].begin(), block_cut_tree[i].end()),
        block_cut_tree[i].end());
  }
  long long ans = static_cast<long long>(n) * (n - 1) / 2 * x;
  const auto dfs = [n, x, &block_cut_tree, &weight, &ans](
      auto dfs, const int par, const int ver) -> int {
    int subtree = weight[ver];
    if (ver < x) {
      for (const int e : block_cut_tree[ver]) {
        if (e != par) [[likely]] {
          const int child = dfs(dfs, ver, e);
          ans -= static_cast<long long>(child) * (child - 1) / 2 + child;
          subtree += child;
        }
      }
      ans -= static_cast<long long>(n - subtree) * (n - subtree - 1) / 2
              + (n - subtree);
    } else {
      for (const int e : block_cut_tree[ver]) {
        if (e != par) [[likely]] subtree += dfs(dfs, ver, e);
      }
    }
    return subtree;
  };
  assert(dfs(dfs, -1, 0) == n);
  std::cout << ans << '\n';
  return 0;
}
