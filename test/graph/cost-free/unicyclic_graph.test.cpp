#define PROBLEM "https://yukicoder.me/problems/no/1254"

#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

#include "../../../graph/cost-free/unicyclic_graph.hpp"

int main() {
  int n;
  std::cin >> n;
  std::map<std::pair<int, int>, int> edge;
  UnicyclicGraph namori(n);
  for (int i = 0; i < n; ++i) {
    int a, b;
    std::cin >> a >> b;
    --a; --b;
    edge[std::minmax(a, b)] = i;
    namori.add_edge(a, b);
  }
  namori.build();
  std::vector<bool> bridge(n, false);
  const int l = namori.loop.size();
  for (int i = 0; i < l; ++i) {
    bridge[edge[std::minmax(namori.loop[i], namori.loop[(i + 1) % l])]] = true;
  }
  std::vector<int> p;
  for (int i = 0; i < n; ++i) {
    if (bridge[i]) p.emplace_back(i);
  }
  const int k = p.size();
  std::cout << k << '\n';
  for (int i = 0; i < k; ++i) {
    std::cout << p[i] + 1 << " \n"[i + 1 == k];
  }
  return 0;
}
