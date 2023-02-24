/*
 * @title グラフ/フロー/マッチング/二部グラフの重み付き最大マッチング
 */
#define IGNORE
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2429"

#include <iostream>
#include <string>
#include <vector>

#include "emthrm/graph/flow/matching/weighted_bipartite_matching.hpp"

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> w(n, std::vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std:: cin >> w[i][j];
    }
  }
  std::vector<std::vector<int>> e(n, std::vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std:: cin >> e[i][j];
    }
  }
  std::vector<std::string> f(n);
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> f[i];
    for (int j = 0; j < n; ++j) {
      if (f[i][j] == 'o') ans += e[i][j];
    }
  }
  emthrm::WeightedBipartiteMatching<long long>
      weighted_bipartite_matching(n, n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      weighted_bipartite_matching.add_edge(i, j,
                                           f[i][j] == 'o' ? e[i][j] : -w[i][j]);
    }
  }
  std::cout << ans - weighted_bipartite_matching.solve() << '\n';
  std::vector<std::string> taro(n, std::string(n, '.'));
  const std::vector<int> matching = weighted_bipartite_matching.matching();
  for (int i = 0; i < n; ++i) {
    taro[i][matching[i]] = 'o';
  }
  std::vector<int> r, c;
  std::vector<std::string> operate;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (f[i][j] != taro[i][j]) {
        r.emplace_back(i);
        c.emplace_back(j);
        operate.emplace_back(f[i][j] == 'o' ? "erase" : "write");
      }
    }
  }
  const int cnt = r.size();
  std::cout << cnt << '\n';
  for (int i = 0; i < cnt; ++i) {
    std::cout << r[i] + 1 << ' ' << c[i] + 1 << ' ' << operate[i] << '\n';
  }
  return 0;
}
