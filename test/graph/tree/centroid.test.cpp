/*
 * @brief グラフ/木/重心
 */
#define PROBLEM "https://atcoder.jp/contests/arc087/tasks/arc087_f"
// #define PROBLEM "https://atcoder.jp/contests/arc087/tasks/arc087_d"

#include <functional>
#include <iostream>
#include <vector>

#include "../../../graph/edge.hpp"
#include "../../../graph/tree/centroid.hpp"
#include "../../../math/modint.hpp"

int main() {
  using ModInt = MInt<0>;
  ModInt::set_mod(1000000007);
  int n;
  std::cin >> n;
  std::vector<std::vector<Edge<bool>>> graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    std::cin >> x >> y;
    --x; --y;
    graph[x].emplace_back(x, y);
    graph[y].emplace_back(y, x);
  }
  const std::vector<int> centroids = centroid(graph);
  if (centroids.size() == 2) {
    std::cout << ModInt::fact(n / 2) * ModInt::fact(n / 2) << '\n';
  } else {
    std::vector<int> subtree(n, 1);
    const std::function<void(int, int)> dfs =
        [&graph, &subtree, &dfs](const int par, const int ver) -> void {
          for (const Edge<bool>& e : graph[ver]) {
            if (e.dst != par) {
              dfs(ver, e.dst);
              subtree[ver] += subtree[e.dst];
            }
          }
        };
    dfs(-1, centroids.front());
    std::vector<int> nums;
    for (const Edge<bool>& e : graph[centroids.front()]) {
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
