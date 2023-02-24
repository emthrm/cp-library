/*
 * @title グラフ/オイラー路 有向グラフ版
 *
 * verification-helper: IGNORE
 * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0225
 */

#include <iostream>
#include <string>
#include <vector>

#include "emthrm/graph/edge.hpp"
#include "emthrm/graph/eulerian_trail_in_directed_graph.hpp"

int main() {
  constexpr int SIGMA = 26;
  while (true) {
    int n;
    std::cin >> n;
    if (n == 0) [[unlikely]] break;
    std::vector<std::vector<emthrm::Edge<bool>>> graph(SIGMA);
    while (n--) {
      std::string word;
      std::cin >> word;
      graph[word.front() - 'a'].emplace_back(word.front() - 'a',
                                             word.back() - 'a');
    }
    const std::vector<emthrm::Edge<bool>> trail =
        emthrm::eulerian_trail_in_directed_graph(graph);
    std::cout << (!trail.empty() && trail.front().src == trail.back().dst ?
                  "OK\n" : "NG\n");
  }
  return 0;
}
