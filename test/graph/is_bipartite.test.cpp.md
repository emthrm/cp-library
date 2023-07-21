---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/data_structure/union-find/union-find.hpp
    title: union-find
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':question:'
    path: include/emthrm/graph/is_bipartite.hpp
    title: "\u4E8C\u90E8\u30B0\u30E9\u30D5 (bipartite graph) \u5224\u5B9A"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    IGNORE: ''
    PROBLEM: https://atcoder.jp/contests/arc099/tasks/arc099_c
    document_title: "\u30B0\u30E9\u30D5/\u4E8C\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A"
    links:
    - https://atcoder.jp/contests/arc099/tasks/arc099_c
  bundledCode: "#line 1 \"test/graph/is_bipartite.test.cpp\"\n/*\n * @title \u30B0\
    \u30E9\u30D5/\u4E8C\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A\n *\n * verification-helper:\
    \ IGNORE\n * verification-helper: PROBLEM https://atcoder.jp/contests/arc099/tasks/arc099_c\n\
    \ */\n\n#include <algorithm>\n#include <iostream>\n#include <map>\n#include <vector>\n\
    \n#line 1 \"include/emthrm/data_structure/union-find/union-find.hpp\"\n\n\n\n\
    #include <utility>\n#line 6 \"include/emthrm/data_structure/union-find/union-find.hpp\"\
    \n\nnamespace emthrm {\n\nstruct UnionFind {\n  explicit UnionFind(const int n)\
    \ : data(n, -1) {}\n\n  int root(const int ver) {\n    return data[ver] < 0 ?\
    \ ver : data[ver] = root(data[ver]);\n  }\n\n  bool unite(int u, int v) {\n  \
    \  u = root(u);\n    v = root(v);\n    if (u == v) return false;\n    if (data[u]\
    \ > data[v]) std::swap(u, v);\n    data[u] += data[v];\n    data[v] = u;\n   \
    \ return true;\n  }\n\n  bool is_same(const int u, const int v) { return root(u)\
    \ == root(v); }\n\n  int size(const int ver) { return -data[root(ver)]; }\n\n\
    \ private:\n  std::vector<int> data;\n};\n\n}  // namespace emthrm\n\n\n#line\
    \ 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n\
    #define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\nnamespace emthrm {\n\n\
    template <typename CostType>\nstruct Edge {\n  CostType cost;\n  int src, dst;\n\
    \n  explicit Edge(const int src, const int dst, const CostType cost = 0)\n   \
    \   : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const Edge& x) const\
    \ = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
    #line 1 \"include/emthrm/graph/is_bipartite.hpp\"\n\n\n\n#include <ranges>\n#line\
    \ 6 \"include/emthrm/graph/is_bipartite.hpp\"\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\
    \n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 8 \"include/emthrm/graph/is_bipartite.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstd::vector<int> is_bipartite(\n\
    \    const std::vector<std::vector<Edge<CostType>>>& graph) {\n  const int n =\
    \ graph.size();\n  std::vector<int> color(n, -1);\n  const auto dfs = [&graph,\
    \ &color](auto dfs, const int ver, const int c)\n      -> bool {\n    color[ver]\
    \ = c;\n    for (const int e : graph[ver]\n                     | std::views::transform(&Edge<CostType>::dst))\
    \ {\n      if (color[e] == c || (color[e] == -1 && !dfs(dfs, e, c ^ 1))) {\n \
    \       return false;\n      }\n    }\n    return true;\n  };\n  for (int i =\
    \ 0; i < n; ++i) {\n    if (color[i] == -1 && !dfs(dfs, i, 0)) return std::vector<int>{};\n\
    \  }\n  return color;\n}\n\n}  // namespace emthrm\n\n\n#line 16 \"test/graph/is_bipartite.test.cpp\"\
    \n\nint main() {\n  int n, m;\n  std::cin >> n >> m;\n  int ans = m;\n  std::vector<std::vector<bool>>\
    \ is_adjacent(n, std::vector<bool>(n, false));\n  while (m--) {\n    int a, b;\n\
    \    std::cin >> a >> b;\n    --a; --b;\n    is_adjacent[a][b] = true;\n    is_adjacent[b][a]\
    \ = true;\n  }\n  emthrm::UnionFind union_find(n);\n  std::vector<std::vector<emthrm::Edge<bool>>>\
    \ graph(n);\n  for (int i = 0; i < n; ++i) {\n    for (int j = i + 1; j < n; ++j)\
    \ {\n      if (!is_adjacent[i][j]) {\n        union_find.unite(i, j);\n      \
    \  graph[i].emplace_back(i, j);\n        graph[j].emplace_back(j, i);\n      }\n\
    \    }\n  }\n  const std::vector<int> color = emthrm::is_bipartite(graph);\n \
    \ if (color.empty()) {\n    std::cout << \"-1\\n\";\n    return 0;\n  }\n  std::vector<bool>\
    \ dp(n + 1, false);\n  dp[0] = true;\n  std::map<int, int> mp;\n  for (int i =\
    \ 0; i < n; ++i) {\n    mp[union_find.root(i)] += color[i];\n  }\n  for (const\
    \ auto& [root, size] : mp) {\n    for (int i = n; i >= 0; --i) {\n      if (dp[i])\
    \ {\n        dp[i] = false;\n        if (i + size <= n) dp[i + size] = true;\n\
    \        if (i + union_find.size(root) - size <= n) {\n          dp[i + union_find.size(root)\
    \ - size] = true;\n        }\n      }\n    }\n  }\n  for (int i = 0; i <= n; ++i)\
    \ {\n    if (dp[i]) ans = std::min(ans, i * (i - 1) / 2 + (n - i) * (n - i - 1)\
    \ / 2);\n  }\n  std::cout << ans << '\\n';\n  return 0;\n}\n"
  code: "/*\n * @title \u30B0\u30E9\u30D5/\u4E8C\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A\
    \n *\n * verification-helper: IGNORE\n * verification-helper: PROBLEM https://atcoder.jp/contests/arc099/tasks/arc099_c\n\
    \ */\n\n#include <algorithm>\n#include <iostream>\n#include <map>\n#include <vector>\n\
    \n#include \"emthrm/data_structure/union-find/union-find.hpp\"\n#include \"emthrm/graph/edge.hpp\"\
    \n#include \"emthrm/graph/is_bipartite.hpp\"\n\nint main() {\n  int n, m;\n  std::cin\
    \ >> n >> m;\n  int ans = m;\n  std::vector<std::vector<bool>> is_adjacent(n,\
    \ std::vector<bool>(n, false));\n  while (m--) {\n    int a, b;\n    std::cin\
    \ >> a >> b;\n    --a; --b;\n    is_adjacent[a][b] = true;\n    is_adjacent[b][a]\
    \ = true;\n  }\n  emthrm::UnionFind union_find(n);\n  std::vector<std::vector<emthrm::Edge<bool>>>\
    \ graph(n);\n  for (int i = 0; i < n; ++i) {\n    for (int j = i + 1; j < n; ++j)\
    \ {\n      if (!is_adjacent[i][j]) {\n        union_find.unite(i, j);\n      \
    \  graph[i].emplace_back(i, j);\n        graph[j].emplace_back(j, i);\n      }\n\
    \    }\n  }\n  const std::vector<int> color = emthrm::is_bipartite(graph);\n \
    \ if (color.empty()) {\n    std::cout << \"-1\\n\";\n    return 0;\n  }\n  std::vector<bool>\
    \ dp(n + 1, false);\n  dp[0] = true;\n  std::map<int, int> mp;\n  for (int i =\
    \ 0; i < n; ++i) {\n    mp[union_find.root(i)] += color[i];\n  }\n  for (const\
    \ auto& [root, size] : mp) {\n    for (int i = n; i >= 0; --i) {\n      if (dp[i])\
    \ {\n        dp[i] = false;\n        if (i + size <= n) dp[i + size] = true;\n\
    \        if (i + union_find.size(root) - size <= n) {\n          dp[i + union_find.size(root)\
    \ - size] = true;\n        }\n      }\n    }\n  }\n  for (int i = 0; i <= n; ++i)\
    \ {\n    if (dp[i]) ans = std::min(ans, i * (i - 1) / 2 + (n - i) * (n - i - 1)\
    \ / 2);\n  }\n  std::cout << ans << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/data_structure/union-find/union-find.hpp
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/is_bipartite.hpp
  isVerificationFile: true
  path: test/graph/is_bipartite.test.cpp
  requiredBy: []
  timestamp: '2023-07-21 12:14:05+09:00'
  verificationStatus: TEST_WAITING_JUDGE
  verifiedWith: []
documentation_of: test/graph/is_bipartite.test.cpp
layout: document
redirect_from:
- /verify/test/graph/is_bipartite.test.cpp
- /verify/test/graph/is_bipartite.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u4E8C\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A"
---
