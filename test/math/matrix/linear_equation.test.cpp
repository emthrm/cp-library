/*
 * @brief 数学/行列/連立一次方程式
 */
#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2171"
#define ERROR "1e-8"

#include <iomanip>
#include <iostream>
#include <vector>
#include "../../../graph/edge.hpp"
#include "../../../graph/shortest_path/dijkstra.hpp"
#include "../../../math/matrix/matrix.hpp"
#include "../../../math/matrix/linear_equation.hpp"

int main() {
  while (true) {
    int n, s, t;
    std::cin >> n >> s >> t;
    if (n == 0 && s == 0 && t == 0) break;
    --s; --t;
    std::vector<int> q(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> q[i];
    }
    std::vector<std::vector<Edge<int>>> graph(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int a;
        std::cin >> a;
        if (a > 0) {
          graph[i].emplace_back(i, j, a);
        }
      }
    }
    Dijkstra<int> dijkstra(graph);
    std::vector<int> dist = dijkstra.build(t);
    if (dist[s] == dijkstra.inf) {
      std::cout << "impossible\n";
      continue;
    }
    Matrix<int> a(n, n, 0);
    std::vector<int> b(n, 0);
    for (int i = 0; i < n; ++i) {
      if (i == t) {
        a[i][i] = 1;
      } else {
        std::vector<Edge<int>> edge;
        if (q[i] == 0) {
          edge = graph[i];
        } else if (q[i] == 1) {
          for (const Edge<int> &e : graph[i]) {
            if (dist[e.dst] + e.cost == dist[i]) {
              edge.emplace_back(e);
            }
          }
        }
        a[i][i] = -edge.size();
        for (const Edge<int> &e : edge) {
          ++a[i][e.dst];
          b[i] -= e.cost;
        }
      }
    }
    std::cout << std::fixed << std::setprecision(8) << linear_equation(a, b)[s] << '\n';
  }
  return 0;
}
