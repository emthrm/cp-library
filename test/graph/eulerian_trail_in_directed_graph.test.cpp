/*
 * @brief グラフ/オイラー路 有向グラフ版
 */
#define IGNORE
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0225"

#include <iostream>
#include <string>
#include <vector>
#include "../../graph/edge.hpp"
#include "../../graph/eulerian_trail_in_directed_graph.hpp"

int main() {
  while (true) {
    int n;
    std::cin >> n;
    if (n == 0) break;
    std::vector<std::vector<Edge<bool>>> graph(26);
    while (n--) {
      std::string word;
      std::cin >> word;
      graph[word.front() - 'a'].emplace_back(word.front() - 'a', word.back() - 'a');
    }
    std::vector<int> trail = eulerian_trail_in_directed_graph(graph);
    std::cout << (!trail.empty() && trail.front() == trail.back() ? "OK\n" : "NG\n");
  }
  return 0;
}
