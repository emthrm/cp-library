/*
 * @brief 数学/多倍長整数
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2679"

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "emthrm/graph/flow/matching/weighted_bipartite_matching.hpp"
#include "emthrm/math/bigint.hpp"

namespace std {

template <int LogB, int B>
struct numeric_limits<emthrm::BigInt<LogB, B>> {
  static constexpr emthrm::BigInt<LogB, B> max() {
    return static_cast<std::string>(
        "453152254949043485887196599220742984693877551020408163265306122448979591836734693877551");
  }
};

};  // namespace std

int main() {
  using bigint = emthrm::BigInt<>;
  constexpr int SIGMA = 26;
  int n;
  std::cin >> n;
  std::map<char, bigint> cost;
  bigint cur = 0;
  for (int i = SIGMA - 1; i >= 0; --i) {
    cost['a' + i] = cur;
    cur = cur * SIGMA * 2 + 1;
  }
  for (int i = SIGMA - 1; i >= 0; --i) {
    cost['A' + i] = cur;
    cur = cur * SIGMA * 2 + 1;
  }
  std::vector<std::string> c(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> c[i];
  }
  emthrm::WeightedBipartiteMatching<bigint> weighted_bipartite_matching(n, n);
  for (int i = 0; i < n; ++i) {
    std::cin >> c[i];
    for (int j = 0; j < n; ++j) {
      weighted_bipartite_matching.add_edge(i, j, cost[c[i][j]]);
    }
  }
  weighted_bipartite_matching.solve();
  std::string ans = "";
  const std::vector<int> matching = weighted_bipartite_matching.matching();
  for (int i = 0; i < n; ++i) {
    ans += c[i][matching[i]];
  }
  std::sort(ans.begin(), ans.end());
  std::cout << ans << '\n';
  return 0;
}
