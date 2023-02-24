/*
 * @title グラフ/木/重心分解
 *
 * verification-helper: PROBLEM https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
 */

#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

#include "emthrm/graph/edge.hpp"
#include "emthrm/graph/tree/centroid_decomposition.hpp"
#include "emthrm/math/convolution/fast_fourier_transform.hpp"

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<emthrm::Edge<bool>>> graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    std::cin >> a >> b;
    graph[a].emplace_back(a, b);
    graph[b].emplace_back(b, a);
  }
  emthrm::CentroidDecomposition<bool> centroid_decomposition(graph);
  std::vector<bool> is_visited(n, false);
  std::vector<long long> x(n, 0);
  const auto f = [n, &graph, &centroid_decomposition, &is_visited, &x](
      auto f, const int root) -> void {
    is_visited[root] = true;
    std::vector<int> nums{1};
    for (const emthrm::Edge<bool>& child : graph[root]) {
      if (is_visited[child.dst]) continue;
      std::vector<int> nums_sub{0};
      const auto dfs = [&graph, &is_visited, &nums, &nums_sub](
          auto dfs, const int par, const int ver, const int dist) -> void {
        if (std::cmp_less_equal(nums.size(), dist)) nums.resize(dist + 1, 0);
        ++nums[dist];
        if (std::cmp_less_equal(nums_sub.size(), dist)) {
          nums_sub.resize(dist + 1, 0);
        }
        ++nums_sub[dist];
        for (const emthrm::Edge<bool>& e : graph[ver]) {
          if (!is_visited[e.dst] && e.dst != par) {
            dfs(dfs, ver, e.dst, dist + 1);
          }
        }
      };
      dfs(dfs, root, child.dst, 1);
      const std::vector<emthrm::fast_fourier_transform::Real> fft =
          emthrm::fast_fourier_transform::convolution(nums_sub, nums_sub);
      for (int i = 0; std::cmp_less(i, fft.size()) && i < n; ++i) {
        x[i] -= std::round(fft[i]);
      }
    }
    const std::vector<emthrm::fast_fourier_transform::Real> fft =
        emthrm::fast_fourier_transform::convolution(nums, nums);
    for (int i = 0; std::cmp_less(i, fft.size()) && i < n; ++i) {
      x[i] += std::round(fft[i]);
    }
    for (const int e : centroid_decomposition.g[root]) f(f, e);
  };
  f(f, centroid_decomposition.root);
  for (int i = 1; i < n; ++i) {
    std::cout << x[i] / 2 << " \n"[i + 1 == n];
  }
  return 0;
}
