/*
 * @title グラフ/木/重心
 *
 * verification-helper: PROBLEM https://atcoder.jp/contests/arc087/tasks/arc087_f
 * Link: "https://atcoder.jp/contests/arc087/tasks/arc087_d"
 */

#include <iostream>
#include <vector>

#include "emthrm/graph/edge.hpp"
#include "emthrm/graph/tree/centroid.hpp"
#include "emthrm/math/modint.hpp"

int main() {
  using ModInt = emthrm::MInt<1000000007>;
  int n;
  std::cin >> n;
  std::vector<std::vector<emthrm::Edge<bool>>> graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    std::cin >> x >> y;
    --x; --y;
    graph[x].emplace_back(x, y);
    graph[y].emplace_back(y, x);
  }
  const std::vector<int> centroids = emthrm::centroid(graph);
  if (centroids.size() == 2) {
    std::cout << ModInt::fact(n / 2) * ModInt::fact(n / 2) << '\n';
  } else {
    std::vector<int> subtree(n, 1);
    const auto dfs = [&graph, &subtree](auto dfs, const int par, const int ver)
        -> void {
      for (const emthrm::Edge<bool>& e : graph[ver]) {
        if (e.dst != par) {
          dfs(dfs, ver, e.dst);
          subtree[ver] += subtree[e.dst];
        }
      }
    };
    dfs(dfs, -1, centroids.front());
    std::vector<int> nums;
    for (const emthrm::Edge<bool>& e : graph[centroids.front()]) {
      nums.emplace_back(subtree[e.dst]);
    }
    const int m = nums.size();
    std::vector<std::vector<ModInt>> dp(m + 1, std::vector<ModInt>(n + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j <= n; ++j) {
        for (int k = 0; k <= nums[i] && j + k <= n; ++k) {
          dp[i + 1][j + k] += dp[i][j] * ModInt::nCk(nums[i], k)
                              * ModInt::nCk(nums[i], k) * ModInt::fact(k);
        }
      }
    }
    ModInt ans = 0;
    for (int j = 0; j <= n; ++j) {
      ans += (j & 1 ? -dp[m][j] : dp[m][j]) * ModInt::fact(n - j);
    }
    std::cout << ans << '\n';
  }
  return 0;
}
