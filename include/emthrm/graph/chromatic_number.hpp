#ifndef EMTHRM_GRAPH_CHROMATIC_NUMBER_HPP_
#define EMTHRM_GRAPH_CHROMATIC_NUMBER_HPP_

#include <bit>
#include <numeric>
#include <ranges>
#include <vector>

#include "emthrm/graph/edge.hpp"

namespace emthrm {

template <typename CostType>
int chromatic_number(const std::vector<std::vector<Edge<CostType>>>& graph) {
  const int n = graph.size();
  std::vector<int> adj(n, 0);
  for (int i = 0; i < n; ++i) {
    for (const int e : graph[i] | std::views::transform(&Edge<CostType>::dst)) {
      adj[i] |= 1 << e;
    }
  }
  std::vector<int> indep(1 << n);
  indep[0] = 1;
  for (unsigned int i = 1; i < (1 << n); ++i) {
    const int v = std::countr_zero(i);
    indep[i] = indep[i ^ (1 << v)] + indep[(i ^ (1 << v)) & ~adj[v]];
  }
  int res = n;
  for (const int mod : std::vector<int>{1000000007, 1000000011}) {
    std::vector<long long> f(1 << n);
    for (unsigned int i = 0; i < (1 << n); ++i) {
      f[i] = ((n - std::popcount(i)) & 1 ? mod - 1 : 1);
    }
    for (int c = 1; c < res; ++c) {
      for (int i = 0; i < (1 << n); ++i) {
        f[i] = (f[i] * indep[i]) % mod;
      }
#if __cplusplus >= 201703L
      if (std::reduce(f.begin(), f.end(), 0LL) % mod > 0) {
        res = c;
        break;
      }
#else
      if (std::accumulate(f.begin(), f.end(), 0LL) % mod > 0) {
        res = c;
        break;
      }
#endif  // __cplusplus >= 201703L
    }
  }
  return res;
}

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_CHROMATIC_NUMBER_HPP_
