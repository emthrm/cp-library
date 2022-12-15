#ifndef EMTHRM_GRAPH_CHROMATIC_NUMBER_HPP_
#define EMTHRM_GRAPH_CHROMATIC_NUMBER_HPP_

#include <vector>

#include "emthrm/graph/edge.hpp"

namespace emthrm {

template <typename CostType>
int chromatic_number(const std::vector<std::vector<Edge<CostType>>>& graph) {
  const int n = graph.size();
  std::vector<int> adj(n, 0);
  for (int i = 0; i < n; ++i) {
    for (const Edge<CostType>& e : graph[i]) adj[i] |= 1 << e.dst;
  }
  std::vector<int> indep(1 << n);
  indep[0] = 1;
  for (int i = 1; i < (1 << n); ++i) {
    const int v = __builtin_ctz(i);
    indep[i] = indep[i ^ (1 << v)] + indep[(i ^ (1 << v)) & ~adj[v]];
  }
  int res = n;
  for (const int mod : std::vector<int>{1000000007, 1000000011}) {
    std::vector<long long> f(1 << n);
    for (int i = 0; i < (1 << n); ++i) {
      f[i] = ((n - __builtin_popcount(i)) & 1 ? mod - 1 : 1);
    }
    for (int c = 1; c < res; ++c) {
      long long pat = 0;
      for (int i = 0; i < (1 << n); ++i) {
        f[i] = (f[i] * indep[i]) % mod;
        pat += f[i];
      }
      if (pat % mod > 0) {
        res = c;
        break;
      }
    }
  }
  return res;
}

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_CHROMATIC_NUMBER_HPP_
