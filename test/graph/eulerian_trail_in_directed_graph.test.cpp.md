---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':question:'
    path: include/emthrm/graph/eulerian_trail_in_directed_graph.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u8DEF (Eulerian trail) \u6709\u5411\u30B0\u30E9\
      \u30D5\u7248"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    IGNORE: ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0225
    document_title: "\u30B0\u30E9\u30D5/\u30AA\u30A4\u30E9\u30FC\u8DEF \u6709\u5411\
      \u30B0\u30E9\u30D5\u7248"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0225
  bundledCode: "#line 1 \"test/graph/eulerian_trail_in_directed_graph.test.cpp\"\n\
    /*\n * @title \u30B0\u30E9\u30D5/\u30AA\u30A4\u30E9\u30FC\u8DEF \u6709\u5411\u30B0\
    \u30E9\u30D5\u7248\n *\n * verification-helper: IGNORE\n * verification-helper:\
    \ PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0225\n */\n\
    \n#include <iostream>\n#include <string>\n#include <vector>\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\
    \n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 1 \"include/emthrm/graph/eulerian_trail_in_directed_graph.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <iterator>\n#include <ranges>\n#include\
    \ <utility>\n#line 9 \"include/emthrm/graph/eulerian_trail_in_directed_graph.hpp\"\
    \n\n#line 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n\
    #ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\
    \nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct Edge {\n  CostType\
    \ cost;\n  int src, dst;\n\n  explicit Edge(const int src, const int dst, const\
    \ CostType cost = 0)\n      : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const\
    \ Edge& x) const = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
    #line 11 \"include/emthrm/graph/eulerian_trail_in_directed_graph.hpp\"\n\nnamespace\
    \ emthrm {\n\ntemplate <typename CostType>\nstd::vector<Edge<CostType>> eulerian_trail_in_directed_graph(\n\
    \    std::vector<std::vector<Edge<CostType>>> graph, int s = -1) {\n  const int\
    \ n = graph.size();\n  int edge_num = 0;\n  std::vector<int> deg(n, 0);\n  for\
    \ (int i = 0; i < n; ++i) {\n    edge_num += graph[i].size();\n    deg[i] += graph[i].size();\n\
    \    for (const int e : graph[i] | std::views::transform(&Edge<CostType>::dst))\
    \ {\n      --deg[e];\n    }\n  }\n  if (edge_num == 0) [[unlikely]] return {};\n\
    \  const int not0 = n - std::count(deg.begin(), deg.end(), 0);\n  if (not0 ==\
    \ 0) {\n    if (s == -1) {\n      s = std::distance(\n          graph.begin(),\n\
    \          std::find_if_not(\n              graph.begin(), graph.end(),\n    \
    \          [](const std::vector<Edge<CostType>>& edges) -> bool {\n          \
    \      return edges.empty();\n              }));\n    }\n  } else if (not0 ==\
    \ 2) {\n    bool t_exists = false;\n    for (int i = 0; i < n; ++i) {\n      if\
    \ (deg[i] == 0) continue;\n      if (deg[i] == 1) {\n        if (s == -1) s =\
    \ i;\n        if (s != i) return {};\n      } else if (deg[i] == -1) {\n     \
    \   if (t_exists) return {};\n        t_exists = true;\n      } else {\n     \
    \   return {};\n      }\n    }\n  } else {\n    return {};\n  }\n  std::vector<Edge<CostType>>\
    \ res;\n  const auto dfs = [&graph, &res](auto dfs, const int ver) -> void {\n\
    \    while (!graph[ver].empty()) {\n      const Edge<CostType> e = graph[ver].back();\n\
    \      graph[ver].pop_back();\n      dfs(dfs, e.dst);\n      res.emplace_back(e);\n\
    \    }\n  };\n  dfs(dfs, s);\n  if (std::cmp_equal(res.size(), edge_num)) {\n\
    \    std::reverse(res.begin(), res.end());\n    return res;\n  }\n  return {};\n\
    }\n\n}  // namespace emthrm\n\n\n#line 14 \"test/graph/eulerian_trail_in_directed_graph.test.cpp\"\
    \n\nint main() {\n  constexpr int SIGMA = 26;\n  while (true) {\n    int n;\n\
    \    std::cin >> n;\n    if (n == 0) [[unlikely]] break;\n    std::vector<std::vector<emthrm::Edge<bool>>>\
    \ graph(SIGMA);\n    while (n--) {\n      std::string word;\n      std::cin >>\
    \ word;\n      graph[word.front() - 'a'].emplace_back(word.front() - 'a',\n  \
    \                                           word.back() - 'a');\n    }\n    const\
    \ std::vector<emthrm::Edge<bool>> trail =\n        emthrm::eulerian_trail_in_directed_graph(graph);\n\
    \    std::cout << (!trail.empty() && trail.front().src == trail.back().dst ?\n\
    \                  \"OK\\n\" : \"NG\\n\");\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u30B0\u30E9\u30D5/\u30AA\u30A4\u30E9\u30FC\u8DEF \u6709\u5411\
    \u30B0\u30E9\u30D5\u7248\n *\n * verification-helper: IGNORE\n * verification-helper:\
    \ PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0225\n */\n\
    \n#include <iostream>\n#include <string>\n#include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\
    \n#include \"emthrm/graph/eulerian_trail_in_directed_graph.hpp\"\n\nint main()\
    \ {\n  constexpr int SIGMA = 26;\n  while (true) {\n    int n;\n    std::cin >>\
    \ n;\n    if (n == 0) [[unlikely]] break;\n    std::vector<std::vector<emthrm::Edge<bool>>>\
    \ graph(SIGMA);\n    while (n--) {\n      std::string word;\n      std::cin >>\
    \ word;\n      graph[word.front() - 'a'].emplace_back(word.front() - 'a',\n  \
    \                                           word.back() - 'a');\n    }\n    const\
    \ std::vector<emthrm::Edge<bool>> trail =\n        emthrm::eulerian_trail_in_directed_graph(graph);\n\
    \    std::cout << (!trail.empty() && trail.front().src == trail.back().dst ?\n\
    \                  \"OK\\n\" : \"NG\\n\");\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/eulerian_trail_in_directed_graph.hpp
  isVerificationFile: true
  path: test/graph/eulerian_trail_in_directed_graph.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: TEST_WAITING_JUDGE
  verifiedWith: []
documentation_of: test/graph/eulerian_trail_in_directed_graph.test.cpp
layout: document
redirect_from:
- /verify/test/graph/eulerian_trail_in_directed_graph.test.cpp
- /verify/test/graph/eulerian_trail_in_directed_graph.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u30AA\u30A4\u30E9\u30FC\u8DEF \u6709\u5411\u30B0\u30E9\
  \u30D5\u7248"
---
