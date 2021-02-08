#pragma once
#include <vector>

int chromatic_number(const std::vector<std::vector<int>> &graph) {
  int n = graph.size();
  std::vector<int> adj(n, 0);
  for (int i = 0; i < n; ++i) for (int e : graph[i]) adj[i] |= 1 << e;
  std::vector<int> indep(1 << n);
  indep[0] = 1;
  for (int i = 1; i < (1 << n); ++i) {
    int ver = __builtin_ctz(i);
    indep[i] = indep[i ^ (1 << ver)] + indep[(i ^ (1 << ver)) & ~adj[ver]];
  }
  int res = n;
  // This implement is too slow.
  // for (int md : vector<int>{1000000007, 1000000011}) {
  //   std::vector<long long> f(1 << n);
  //   for (int i = 0; i < (1 << n); ++i) f[i] = (n - __builtin_popcount(i)) & 1 ? md - 1 : 1;
  //   for (int c = 1; c < res; ++c) {
  //     long long pat = 0;
  //     for (int i = 0; i < (1 << n); ++i) {
  //       (f[i] *= indep[i]) %= md;
  //       pat += f[i];
  //     }
  //     if (pat % md > 0) {
  //       res = c;
  //       break;
  //     }
  //   }
  // }
  constexpr int MOD1 = 1000000007, MOD2 = 1000000011;
  std::vector<long long> f1(1 << n);
  for (int i = 0; i < (1 << n); ++i) f1[i] = (n - __builtin_popcount(i)) & 1 ? MOD1 - 1 : 1;
  for (int c = 1; c < res; ++c) {
    long long pat = 0;
    for (int i = 0; i < (1 << n); ++i) {
      (f1[i] *= indep[i]) %= MOD1;
      pat += f1[i];
    }
    if (pat % MOD1 > 0) {
      res = c;
      break;
    }
  }
  std::vector<long long> f2(1 << n);
  for (int i = 0; i < (1 << n); ++i) f2[i] = (n - __builtin_popcount(i)) & 1 ? MOD2 - 1 : 1;
  for (int c = 1; c < res; ++c) {
    long long pat = 0;
    for (int i = 0; i < (1 << n); ++i) {
      (f2[i] *= indep[i]) %= MOD2;
      pat += f2[i];
    }
    if (pat % MOD2 > 0) {
      res = c;
      break;
    }
  }
  return res;
}
