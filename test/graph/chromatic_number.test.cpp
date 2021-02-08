/*
 * @brief グラフ/彩色数
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2136"

#include <iostream>
#include <vector>
#include "../../geometry/geometry.hpp"
#include "../../graph/edge.hpp"
#include "../../graph/chromatic_number.hpp"

int main() {
  while (true) {
    int n;
    std::cin >> n;
    if (n == 0) break;
    std::vector<std::vector<geometry::Segment>> line(n);
    for (int i = 0; i < n; ++i) {
      int s;
      std::cin >> s;
      std::vector<int> x(s), y(s);
      for (int j = 0; j < s; ++j) std::cin >> x[j] >> y[j];
      for (int j = 1; j < s; ++j) line[i].emplace_back(geometry::Point(x[j - 1], y[j - 1]), geometry::Point(x[j], y[j]));
    }
    std::vector<std::vector<Edge<bool>>> graph(n);
    for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) {
      bool is_crossing = false;
      for (int k = 0; k < line[i].size(); ++k) for (int l = 0; l < line[j].size(); ++l) {
        is_crossing |= geometry::has_intersected(line[i][k], line[j][l]);
      }
      if (is_crossing) {
        graph[i].emplace_back(i, j);
        graph[j].emplace_back(j, i);
      }
    }
    std::cout << chromatic_number(graph) << '\n';
  }
  return 0;
}
