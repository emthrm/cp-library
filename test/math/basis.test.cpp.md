---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/basis.hpp
    title: "\u57FA\u5E95 (basis)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2416
    document_title: "\u6570\u5B66/\u57FA\u5E95"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2416
  bundledCode: "#line 1 \"test/math/basis.test.cpp\"\n/*\n * @title \u6570\u5B66/\u57FA\
    \u5E95\n *\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2416\n\
    \ */\n\n#include <bitset>\n#include <iostream>\n#include <vector>\n\n#line 1 \"\
    include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n\
    #define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\nnamespace emthrm {\n\n\
    template <typename CostType>\nstruct Edge {\n  CostType cost;\n  int src, dst;\n\
    \n  explicit Edge(const int src, const int dst, const CostType cost = 0)\n   \
    \   : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const Edge& x) const\
    \ = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
    #line 1 \"include/emthrm/math/basis.hpp\"\n\n\n\n#include <algorithm>\n#line 6\
    \ \"include/emthrm/math/basis.hpp\"\n#include <iterator>\n#line 8 \"include/emthrm/math/basis.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <int D>\nstruct Basis {\n  std::vector<std::bitset<D>>\
    \ v;\n  std::vector<int> msb;\n\n  Basis() = default;\n\n  bool add(std::bitset<D>\
    \ val) {\n    const int n = rank();\n    if (n == D) return false;\n    for (int\
    \ i = 0; i < n; ++i) {\n      if (val[msb[i]]) val ^= v[i];\n    }\n    if (val.none())\
    \ return false;\n    int m = D - 1;\n    while (!val[m]) --m;\n    if (v.empty())\
    \ [[unlikely]] {\n      v.emplace_back(val);\n      msb.emplace_back(m);\n   \
    \   return true;\n    }\n    const int idx = std::distance(std::upper_bound(msb.rbegin(),\
    \ msb.rend(), m),\n                                  msb.rend());\n    v.emplace(std::next(v.begin(),\
    \ idx), val);\n    msb.emplace(std::next(msb.begin(), idx), m);\n    for (int\
    \ i = idx + 1; i <= n; ++i) {\n      if (v[idx][msb[i]]) v[idx] ^= v[i];\n   \
    \ }\n    for (int i = idx - 1; i >= 0; --i) {\n      if (v[i][m]) v[i] ^= v[idx];\n\
    \    }\n    return true;\n  }\n\n  int rank() const { return v.size(); }\n\n \
    \ inline bool operator<(const Basis& x) const {\n    const int n = v.size();\n\
    \    if (n != x.rank()) return n < x.rank();\n    if (n == D) return false;\n\
    \    for (int i = 0; i < n; ++i) {\n      if (msb[i] != x.msb[i]) return msb[i]\
    \ < x.msb[i];\n    }\n    for (int i = 0; i < n; ++i) {\n      for (int j = msb[i]\
    \ - 1; ; --j) {\n        if (v[i][j] != x.v[i][j]) return x.v[i][j];\n      }\n\
    \    }\n    return false;\n  }\n};\n\n}  // namespace emthrm\n\n\n#line 13 \"\
    test/math/basis.test.cpp\"\n\nint main() {\n  constexpr int D = 60;\n  int n,\
    \ m, q;\n  std::cin >> n >> m >> q;\n  std::vector<std::vector<emthrm::Edge<long\
    \ long>>> graph(n);\n  while (m--) {\n    int f, t;\n    long long p;\n    std::cin\
    \ >> f >> t >> p;\n    graph[f].emplace_back(f, t, p);\n    graph[t].emplace_back(t,\
    \ f, p);\n  }\n  std::vector<long long> x(n, -1);\n  x[0] = 0;\n  emthrm::Basis<D>\
    \ basis;\n  const auto dfs = [&graph, &x, &basis](auto dfs, const int par, const\
    \ int ver)\n      -> void {\n    for (const emthrm::Edge<long long>& e : graph[ver])\
    \ {\n      if (e.dst != par) {\n        if (x[e.dst] == -1) {\n          x[e.dst]\
    \ = x[ver] ^ e.cost;\n          dfs(dfs, ver, e.dst);\n        } else {\n    \
    \      basis.add(x[ver] ^ x[e.dst] ^ e.cost);\n        }\n      }\n    }\n  };\n\
    \  dfs(dfs, -1, 0);\n  while (q--) {\n    int a, b;\n    std::cin >> a >> b;\n\
    \    std::bitset<D> ans(x[a] ^ x[b]);\n    for (int i = 0; i < basis.rank(); ++i)\
    \ {\n      if (!ans[basis.msb[i]]) ans ^= basis.v[i];\n    }\n    std::cout <<\
    \ ans.to_ulong() << '\\n';\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u6570\u5B66/\u57FA\u5E95\n *\n * verification-helper: PROBLEM\
    \ http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2416\n */\n\n#include\
    \ <bitset>\n#include <iostream>\n#include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\
    \n#include \"emthrm/math/basis.hpp\"\n\nint main() {\n  constexpr int D = 60;\n\
    \  int n, m, q;\n  std::cin >> n >> m >> q;\n  std::vector<std::vector<emthrm::Edge<long\
    \ long>>> graph(n);\n  while (m--) {\n    int f, t;\n    long long p;\n    std::cin\
    \ >> f >> t >> p;\n    graph[f].emplace_back(f, t, p);\n    graph[t].emplace_back(t,\
    \ f, p);\n  }\n  std::vector<long long> x(n, -1);\n  x[0] = 0;\n  emthrm::Basis<D>\
    \ basis;\n  const auto dfs = [&graph, &x, &basis](auto dfs, const int par, const\
    \ int ver)\n      -> void {\n    for (const emthrm::Edge<long long>& e : graph[ver])\
    \ {\n      if (e.dst != par) {\n        if (x[e.dst] == -1) {\n          x[e.dst]\
    \ = x[ver] ^ e.cost;\n          dfs(dfs, ver, e.dst);\n        } else {\n    \
    \      basis.add(x[ver] ^ x[e.dst] ^ e.cost);\n        }\n      }\n    }\n  };\n\
    \  dfs(dfs, -1, 0);\n  while (q--) {\n    int a, b;\n    std::cin >> a >> b;\n\
    \    std::bitset<D> ans(x[a] ^ x[b]);\n    for (int i = 0; i < basis.rank(); ++i)\
    \ {\n      if (!ans[basis.msb[i]]) ans ^= basis.v[i];\n    }\n    std::cout <<\
    \ ans.to_ulong() << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  - include/emthrm/math/basis.hpp
  isVerificationFile: true
  path: test/math/basis.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 01:48:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/basis.test.cpp
layout: document
redirect_from:
- /verify/test/math/basis.test.cpp
- /verify/test/math/basis.test.cpp.html
title: "\u6570\u5B66/\u57FA\u5E95"
---
