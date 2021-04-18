/*
 * @brief グラフ/unicyclic graph
 */
#define PROBLEM "https://yukicoder.me/problems/no/1254"

#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include "../../graph/edge.hpp"
#include "../../graph/unicyclic_graph.hpp"

int main() {
  int n;
  std::cin >> n;
  std::map<std::pair<int, int>, int> edge;
  UnicyclicGraph<bool> namori(n);
  for (int i = 0; i < n; ++i) {
    int a, b;
    std::cin >> a >> b;
    --a; --b;
    if (a > b) std::swap(a, b);
    edge[{a, b}] = i;
    namori.add_edge(a, b, false);
  }
  namori.build();
  std::vector<bool> bridge(n, false);
  for (const Edge<bool> &e : namori.loop) {
    int a = e.src, b = e.dst;
    if (a > b) std::swap(a, b);
    bridge[edge[{a, b}]] = true;
  }
  std::vector<int> p;
  for (int i = 0; i < n; ++i) {
    if (bridge[i]) p.emplace_back(i);
  }
  int k = p.size();
  std::cout << k << '\n';
  for (int i = 0; i < k; ++i) std::cout << p[i] + 1 << " \n"[i + 1 == k];
  return 0;
}
