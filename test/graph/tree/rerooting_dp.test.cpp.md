---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/tree/rerooting_dp.hpp
    title: "\u5168\u65B9\u4F4D\u6728 DP"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A
    document_title: "\u30B0\u30E9\u30D5/\u6728/\u5168\u65B9\u4F4D\u6728 DP"
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A
  bundledCode: "#line 1 \"test/graph/tree/rerooting_dp.test.cpp\"\n/*\n * @title \u30B0\
    \u30E9\u30D5/\u6728/\u5168\u65B9\u4F4D\u6728 DP\n *\n * verification-helper: PROBLEM\
    \ https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A\n */\n\n#include\
    \ <algorithm>\n#include <functional>\n#include <iostream>\n#include <utility>\n\
    #include <vector>\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title\
    \ \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 1 \"include/emthrm/graph/tree/rerooting_dp.hpp\"\
    \n\n\n\n#line 6 \"include/emthrm/graph/tree/rerooting_dp.hpp\"\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\
    \n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 8 \"include/emthrm/graph/tree/rerooting_dp.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType, typename CommutativeSemigroup,\n\
    \          typename E, typename F, typename G>\nstd::vector<CommutativeSemigroup>\
    \ rerooting_dp(\n    const std::vector<std::vector<Edge<CostType>>>& graph,\n\
    \    const std::vector<CommutativeSemigroup>& def,\n    const E merge, const F\
    \ f, const G g) {\n  const int n = graph.size();\n  if (n == 0) [[unlikely]] return\
    \ {};\n  if (n == 1) [[unlikely]] return {g(def[0], 0)};\n  std::vector<std::vector<CommutativeSemigroup>>\
    \ children(n);\n  const auto dfs1 = [&graph, &def, merge, f, g, &children](\n\
    \      auto dfs1, const int par, const int ver) -> CommutativeSemigroup {\n  \
    \  children[ver].reserve(graph[ver].size());\n    CommutativeSemigroup dp = def[ver];\n\
    \    for (const Edge<CostType>& e : graph[ver]) {\n      if (e.dst == par) {\n\
    \        children[ver].emplace_back();\n      } else {\n        children[ver].emplace_back(f(dfs1(dfs1,\
    \ ver, e.dst), e));\n        dp = merge(dp, children[ver].back());\n      }\n\
    \    }\n    return g(dp, ver);\n  };\n  dfs1(dfs1, -1, 0);\n  std::vector<CommutativeSemigroup>\
    \ dp = def;\n  const auto dfs2 = [&graph, &def, merge, f, g, &children, &dp](\n\
    \      auto dfs2, const int par, const int ver, const CommutativeSemigroup& m)\n\
    \          -> void {\n    const int c = graph[ver].size();\n    for (int i = 0;\
    \ i < c; ++i) {\n      if (graph[ver][i].dst == par) {\n        children[ver][i]\
    \ = f(m, graph[ver][i]);\n        break;\n      }\n    }\n    std::vector<CommutativeSemigroup>\
    \ left{def[ver]}, right;\n    left.reserve(c);\n    for (int i = 0; i < c - 1;\
    \ ++i) {\n      left.emplace_back(merge(left[i], children[ver][i]));\n    }\n\
    \    dp[ver] = g(merge(left.back(), children[ver].back()), ver);\n    if (c >=\
    \ 2) {\n      right.reserve(c - 1);\n      right.emplace_back(children[ver].back());\n\
    \      for (int i = c - 2; i > 0; --i) {\n        right.emplace_back(merge(children[ver][i],\
    \ right[c - 2 - i]));\n      }\n      std::reverse(right.begin(), right.end());\n\
    \    }\n    for (int i = 0; i < c; ++i) {\n      if (graph[ver][i].dst != par)\
    \ {\n        dfs2(dfs2, ver, graph[ver][i].dst,\n             g(i + 1 == c ? left[i]\
    \ : merge(left[i], right[i]), ver));\n      }\n    }\n  };\n  dfs2(dfs2, -1, 0,\
    \ CommutativeSemigroup());\n  return dp;\n}\n\n}  // namespace emthrm\n\n\n#line\
    \ 15 \"test/graph/tree/rerooting_dp.test.cpp\"\n\nint main() {\n  int n;\n  std::cin\
    \ >> n;\n  std::vector<std::vector<emthrm::Edge<int>>> graph(n);\n  for (int i\
    \ = 0; i < n - 1; ++i) {\n    int s, t, w;\n    std::cin >> s >> t >> w;\n   \
    \ graph[s].emplace_back(s, t, w);\n    graph[t].emplace_back(t, s, w);\n  }\n\
    \  const std::vector<std::pair<int, int>> ans = emthrm::rerooting_dp(\n      graph,\
    \ std::vector<std::pair<int, int>>(n, {0, 0}),\n      [](const std::pair<int,\
    \ int>& x, const std::pair<int, int>& y)\n          -> std::pair<int, int> {\n\
    \        int tmp[]{x.first, x.second, y.first, y.second};\n        std::sort(tmp,\
    \ tmp + 4, std::greater<int>());\n        return {tmp[0], tmp[1]};\n      },\n\
    \      [](const std::pair<int, int>& x, const emthrm::Edge<int>& e)\n        \
    \  -> std::pair<int, int> { return {x.first + e.cost, 0}; },\n      [](const std::pair<int,\
    \ int>& x, const int) -> std::pair<int, int> {\n        return x;\n      });\n\
    \  int diameter = 0;\n  for (int i = 0; i < n; ++i) {\n    diameter = std::max(diameter,\
    \ ans[i].first + ans[i].second);\n  }\n  std::cout << diameter << '\\n';\n  return\
    \ 0;\n}\n"
  code: "/*\n * @title \u30B0\u30E9\u30D5/\u6728/\u5168\u65B9\u4F4D\u6728 DP\n *\n\
    \ * verification-helper: PROBLEM https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A\n\
    \ */\n\n#include <algorithm>\n#include <functional>\n#include <iostream>\n#include\
    \ <utility>\n#include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\n#include\
    \ \"emthrm/graph/tree/rerooting_dp.hpp\"\n\nint main() {\n  int n;\n  std::cin\
    \ >> n;\n  std::vector<std::vector<emthrm::Edge<int>>> graph(n);\n  for (int i\
    \ = 0; i < n - 1; ++i) {\n    int s, t, w;\n    std::cin >> s >> t >> w;\n   \
    \ graph[s].emplace_back(s, t, w);\n    graph[t].emplace_back(t, s, w);\n  }\n\
    \  const std::vector<std::pair<int, int>> ans = emthrm::rerooting_dp(\n      graph,\
    \ std::vector<std::pair<int, int>>(n, {0, 0}),\n      [](const std::pair<int,\
    \ int>& x, const std::pair<int, int>& y)\n          -> std::pair<int, int> {\n\
    \        int tmp[]{x.first, x.second, y.first, y.second};\n        std::sort(tmp,\
    \ tmp + 4, std::greater<int>());\n        return {tmp[0], tmp[1]};\n      },\n\
    \      [](const std::pair<int, int>& x, const emthrm::Edge<int>& e)\n        \
    \  -> std::pair<int, int> { return {x.first + e.cost, 0}; },\n      [](const std::pair<int,\
    \ int>& x, const int) -> std::pair<int, int> {\n        return x;\n      });\n\
    \  int diameter = 0;\n  for (int i = 0; i < n; ++i) {\n    diameter = std::max(diameter,\
    \ ans[i].first + ans[i].second);\n  }\n  std::cout << diameter << '\\n';\n  return\
    \ 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/tree/rerooting_dp.hpp
  isVerificationFile: true
  path: test/graph/tree/rerooting_dp.test.cpp
  requiredBy: []
  timestamp: '2023-05-12 15:57:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/tree/rerooting_dp.test.cpp
layout: document
redirect_from:
- /verify/test/graph/tree/rerooting_dp.test.cpp
- /verify/test/graph/tree/rerooting_dp.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u6728/\u5168\u65B9\u4F4D\u6728 DP"
---
