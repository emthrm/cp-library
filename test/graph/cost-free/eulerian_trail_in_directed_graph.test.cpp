#define IGNORE
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0225"

#include <iostream>
#include <string>
#include <vector>

#include "emthrm/graph/cost-free/eulerian_trail_in_directed_graph.hpp"

int main() {
  constexpr int SIGMA = 26;
  while (true) {
    int n;
    std::cin >> n;
    if (n == 0) break;
    std::vector<std::vector<int>> graph(SIGMA);
    while (n--) {
      std::string word;
      std::cin >> word;
      graph[word.front() - 'a'].emplace_back(word.back() - 'a');
    }
    const std::vector<int> trail =
        emthrm::eulerian_trail_in_directed_graph(graph);
    std::cout << (!trail.empty() && trail.front() == trail.back() ?
                  "OK\n" : "NG\n");
  }
  return 0;
}
