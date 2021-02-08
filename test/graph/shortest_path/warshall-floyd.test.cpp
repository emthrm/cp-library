/*
 * @brief グラフ/最短路問題/Warshall-Floyd 法
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0526"

#include <iostream>
#include <limits>
#include <vector>
#include "../../../graph/shortest_path/warshall-floyd.hpp"

int main() {
  constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
  while (true) {
    int n, k;
    std::cin >> n >> k;
    if (n == 0 && k == 0) break;
    std::vector<std::vector<long long>> graph(n, std::vector<long long>(n, LINF));
    for (int i = 0; i < n; ++i) graph[i][i] = 0;
    WarshallFloyd<long long> wf(graph, LINF);
    while (k--) {
      int flag;
      std::cin >> flag;
      if (flag == 0) {
        int a, b;
        std::cin >> a >> b;
        --a; --b;
        std::cout << (wf.dist[a][b] == LINF ? -1 : wf.dist[a][b]) << '\n';
      } else {
        int c, d;
        long long e;
        std::cin >> c >> d >> e;
        --c; --d;
        wf.add(c, d, e);
        wf.add(d, c, e);
        wf.calc();
      }
    }
  }
  return 0;
}
