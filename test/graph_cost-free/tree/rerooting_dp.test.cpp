/*
 * verification-helper: IGNORE
 * verification-helper: PROBLEM https://atcoder.jp/contests/dp/tasks/dp_v
 */

#include <functional>
#include <iostream>
#include <vector>

#include "emthrm/graph_cost-free/tree/rerooting_dp.hpp"
#define ARBITRARY_MODINT
#include "emthrm/math/modint.hpp"

int main() {
  using ModInt = emthrm::MInt<0>;
  int n, m;
  std::cin >> n >> m;
  ModInt::set_mod(m);
  std::vector<std::vector<int>> graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    std::cin >> x >> y;
    --x; --y;
    graph[x].emplace_back(y);
    graph[y].emplace_back(x);
  }
  for (const ModInt ans
       : emthrm::rerooting_dp(
             graph, std::vector<ModInt>(n, 1), std::multiplies<ModInt>(),
             [](const ModInt& x, const int, const int) -> ModInt {
               return x + 1;
             },
             [](const ModInt& x, const int) -> ModInt { return x; })) {
    std::cout << ans << '\n';
  }
  return 0;
}
