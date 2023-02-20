#ifndef EMTHRM_GRAPH_COST_FREE_CHROMATIC_NUMBER_HPP_
#define EMTHRM_GRAPH_COST_FREE_CHROMATIC_NUMBER_HPP_

#include <numeric>
#include <vector>

#if !defined(__GNUC__) && \
    (!defined(__has_builtin) || !__has_builtin(__builtin_ctz) \
                             || !__has_builtin(__builtin_popcount))
# error "GCC built-in functions are required."
#endif

namespace emthrm {

int chromatic_number(const std::vector<std::vector<int>>& graph) {
  const int n = graph.size();
  std::vector<int> adj(n, 0);
  for (int i = 0; i < n; ++i) {
    for (const int e : graph[i]) adj[i] |= 1 << e;
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

#endif  // EMTHRM_GRAPH_COST_FREE_CHROMATIC_NUMBER_HPP_
