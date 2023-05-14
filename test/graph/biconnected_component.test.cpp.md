---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/biconnected_component.hpp
    title: "\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206 (biconnected component)\
      \ \u5206\u89E3"
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':question:'
    path: include/emthrm/graph/lowlink.hpp
    title: lowlink
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    IGNORE: ''
    PROBLEM: https://atcoder.jp/contests/nadafes2022_day2/tasks/nadafes2022_day2_h
    document_title: "\u30B0\u30E9\u30D5/\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\
      \u5206\u5206\u89E3"
    links:
    - https://atcoder.jp/contests/nadafes2022_day2/tasks/nadafes2022_day2_h
  bundledCode: "#line 1 \"test/graph/biconnected_component.test.cpp\"\n/*\n * @title\
    \ \u30B0\u30E9\u30D5/\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u5206\u89E3\
    \n *\n * verification-helper: IGNORE\n * verification-helper: PROBLEM https://atcoder.jp/contests/nadafes2022_day2/tasks/nadafes2022_day2_h\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include\
    \ <iterator>\n#include <set>\n#include <utility>\n#include <vector>\n\n#line 1\
    \ \"include/emthrm/graph/biconnected_component.hpp\"\n\n\n\n// #include <algorithm>\n\
    #line 8 \"include/emthrm/graph/biconnected_component.hpp\"\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\
    \n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 1 \"include/emthrm/graph/lowlink.hpp\"\
    \n\n\n\n#line 6 \"include/emthrm/graph/lowlink.hpp\"\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\
    \n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 8 \"include/emthrm/graph/lowlink.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct Lowlink {\n  std::vector<int>\
    \ order, lowlink, articulation_points;\n  std::vector<Edge<CostType>> bridges;\n\
    \  const std::vector<std::vector<Edge<CostType>>> graph;\n\n  explicit Lowlink(const\
    \ std::vector<std::vector<Edge<CostType>>>& graph)\n      : graph(graph) {\n \
    \   const int n = graph.size();\n    order.assign(n, -1);\n    lowlink.resize(n);\n\
    \    int t = 0;\n    for (int i = 0; i < n; ++i) {\n      if (order[i] == -1)\
    \ dfs(-1, i, &t);\n    }\n  }\n\n private:\n  void dfs(const int par, const int\
    \ ver, int* t) {\n    order[ver] = lowlink[ver] = (*t)++;\n    int num = 0;\n\
    \    bool is_articulation_point = false;\n    for (const Edge<CostType>& e : graph[ver])\
    \ {\n      if (order[e.dst] == -1) {\n        ++num;\n        dfs(ver, e.dst,\
    \ t);\n        lowlink[ver] = std::min(lowlink[ver], lowlink[e.dst]);\n      \
    \  if (order[ver] <= lowlink[e.dst]) {\n          is_articulation_point = true;\n\
    \          if (order[ver] < lowlink[e.dst]) {\n            bridges.emplace_back(std::min(ver,\
    \ e.dst), std::max(ver, e.dst),\n                                 e.cost);\n \
    \         }\n        }\n      } else if (e.dst != par) {\n        lowlink[ver]\
    \ = std::min(lowlink[ver], order[e.dst]);\n      }\n    }\n    if ((par == -1\
    \ && num >= 2) || (par != -1 && is_articulation_point)) {\n      articulation_points.emplace_back(ver);\n\
    \    }\n  }\n};\n\n}  // namespace emthrm\n\n\n#line 11 \"include/emthrm/graph/biconnected_component.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType, bool IS_FULL_VER = false>\n\
    struct BiconnectedComponent : Lowlink<CostType> {\n  std::vector<int> id;\n  std::vector<std::vector<int>>\
    \ vertices, cutpoint;\n  std::vector<std::vector<Edge<CostType>>> block;\n\n \
    \ explicit BiconnectedComponent(\n      const std::vector<std::vector<Edge<CostType>>>&\
    \ graph)\n      : Lowlink<CostType>(graph) {\n    const int n = graph.size();\n\
    \    id.assign(n, -2);\n    if constexpr (IS_FULL_VER) {\n      cutpoint.resize(n);\n\
    \      is_articulation_point.assign(n, false);\n      for (const int articulation_point\
    \ : this->articulation_points) {\n        is_articulation_point[articulation_point]\
    \ = true;\n      }\n    }\n    for (int i = 0; i < n; ++i) {\n      if (id[i]\
    \ == -2) dfs(-1, i);\n    }\n    // const int m = vertices.size();\n    // for\
    \ (int i = 0; i < m; ++i) {\n    //   std::sort(block[i].begin(), block[i].end());\n\
    \    // }\n    // if constexpr (IS_FULL_VER) {\n    //   for (int i = 0; i < m;\
    \ ++i) {\n    //     std::sort(vertices[i].begin(), vertices[i].end());\n    //\
    \   }\n    //   for (int i = 0; i < n; ++i) {\n    //     std::sort(cutpoint[i].begin(),\
    \ cutpoint[i].end());\n    //   }\n    // }\n  }\n\n private:\n  std::vector<bool>\
    \ is_articulation_point;\n  std::vector<Edge<CostType>> tmp;\n\n  void dfs(const\
    \ int par, const int ver) {\n    id[ver] = -1;\n    for (const Edge<CostType>&\
    \ e : this->graph[ver]) {\n      if (e.dst == par) continue;\n      int src =\
    \ ver, dst = e.dst;\n      if (src > dst) std::swap(src, dst);\n      if (id[e.dst]\
    \ == -2 || this->order[e.dst] < this->order[ver]) {\n        tmp.emplace_back(src,\
    \ dst, e.cost);\n      }\n      if (id[e.dst] == -2) {\n        dfs(ver, e.dst);\n\
    \        if (this->lowlink[e.dst] >= this->order[ver]) {\n          const int\
    \ idx = block.size();\n          block.emplace_back();\n          std::set<int>\
    \ st;\n          while (true) {\n            const Edge<CostType> edge = tmp.back();\n\
    \            tmp.pop_back();\n            block.back().emplace_back(edge);\n \
    \           if constexpr (IS_FULL_VER) {\n              st.emplace(edge.src);\n\
    \              st.emplace(edge.dst);\n            }\n            if (edge.src\
    \ == src && edge.dst == dst) break;\n          }\n          if constexpr (IS_FULL_VER)\
    \ {\n            vertices.emplace_back();\n            for (const int el : st)\
    \ {\n              vertices.back().emplace_back(el);\n              if (is_articulation_point[el])\
    \ {\n                cutpoint[el].emplace_back(idx);\n              } else {\n\
    \                id[el] = idx;\n              }\n            }\n          }\n\
    \        }\n      }\n    }\n  }\n};\n\n}  // namespace emthrm\n\n\n#line 1 \"\
    include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n\
    #define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\nnamespace emthrm {\n\n\
    template <typename CostType>\nstruct Edge {\n  CostType cost;\n  int src, dst;\n\
    \n  explicit Edge(const int src, const int dst, const CostType cost = 0)\n   \
    \   : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const Edge& x) const\
    \ = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
    #line 18 \"test/graph/biconnected_component.test.cpp\"\n\nint main() {\n  int\
    \ n, m;\n  std::cin >> n >> m;\n  std::vector<std::vector<emthrm::Edge<bool>>>\
    \ graph(n);\n  while (m--) {\n    int a, b;\n    std::cin >> a >> b;\n    --a;\
    \ --b;\n    graph[a].emplace_back(a, b);\n    graph[b].emplace_back(b, a);\n \
    \ }\n  emthrm::BiconnectedComponent<bool, true> biconnected_component(graph);\n\
    \  const int x = biconnected_component.articulation_points.size();\n  const int\
    \ y = biconnected_component.vertices.size();\n  std::sort(biconnected_component.articulation_points.begin(),\n\
    \            biconnected_component.articulation_points.end());\n  std::vector<std::vector<int>>\
    \ block_cut_tree(x + y);\n  std::vector<int> weight(x + y, 0);\n  for (int i =\
    \ 0; i < n; ++i) {\n    if (biconnected_component.id[i] == -1) {\n      const\
    \ int index =\n          std::distance(biconnected_component.articulation_points.begin(),\n\
    \                        std::lower_bound(\n                            biconnected_component.articulation_points.begin(),\n\
    \                            biconnected_component.articulation_points.end(),\n\
    \                            i));\n      for (const int block : biconnected_component.cutpoint[i])\
    \ {\n        block_cut_tree[index].emplace_back(block + x);\n        block_cut_tree[block\
    \ + x].emplace_back(index);\n      }\n      ++weight[index];\n    } else {\n \
    \     ++weight[biconnected_component.id[i] + x];\n    }\n  }\n  for (int i = 0;\
    \ i < x + y; ++i) {\n    std::sort(block_cut_tree[i].begin(), block_cut_tree[i].end());\n\
    \    block_cut_tree[i].erase(\n        std::unique(block_cut_tree[i].begin(),\
    \ block_cut_tree[i].end()),\n        block_cut_tree[i].end());\n  }\n  long long\
    \ ans = static_cast<long long>(n) * (n - 1) / 2 * x;\n  const auto dfs = [n, x,\
    \ &block_cut_tree, &weight, &ans](\n      auto dfs, const int par, const int ver)\
    \ -> int {\n    int subtree = weight[ver];\n    if (ver < x) {\n      for (const\
    \ int e : block_cut_tree[ver]) {\n        if (e != par) {\n          const int\
    \ child = dfs(dfs, ver, e);\n          ans -= static_cast<long long>(child) *\
    \ (child - 1) / 2 + child;\n          subtree += child;\n        }\n      }\n\
    \      ans -= static_cast<long long>(n - subtree) * (n - subtree - 1) / 2\n  \
    \           + (n - subtree);\n    } else {\n      for (const int e : block_cut_tree[ver])\
    \ {\n        if (e != par) subtree += dfs(dfs, ver, e);\n      }\n    }\n    return\
    \ subtree;\n  };\n  assert(dfs(dfs, -1, 0) == n);\n  std::cout << ans << '\\n';\n\
    \  return 0;\n}\n"
  code: "/*\n * @title \u30B0\u30E9\u30D5/\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\
    \u5206\u5206\u89E3\n *\n * verification-helper: IGNORE\n * verification-helper:\
    \ PROBLEM https://atcoder.jp/contests/nadafes2022_day2/tasks/nadafes2022_day2_h\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include\
    \ <iterator>\n#include <set>\n#include <utility>\n#include <vector>\n\n#include\
    \ \"emthrm/graph/biconnected_component.hpp\"\n#include \"emthrm/graph/edge.hpp\"\
    \n\nint main() {\n  int n, m;\n  std::cin >> n >> m;\n  std::vector<std::vector<emthrm::Edge<bool>>>\
    \ graph(n);\n  while (m--) {\n    int a, b;\n    std::cin >> a >> b;\n    --a;\
    \ --b;\n    graph[a].emplace_back(a, b);\n    graph[b].emplace_back(b, a);\n \
    \ }\n  emthrm::BiconnectedComponent<bool, true> biconnected_component(graph);\n\
    \  const int x = biconnected_component.articulation_points.size();\n  const int\
    \ y = biconnected_component.vertices.size();\n  std::sort(biconnected_component.articulation_points.begin(),\n\
    \            biconnected_component.articulation_points.end());\n  std::vector<std::vector<int>>\
    \ block_cut_tree(x + y);\n  std::vector<int> weight(x + y, 0);\n  for (int i =\
    \ 0; i < n; ++i) {\n    if (biconnected_component.id[i] == -1) {\n      const\
    \ int index =\n          std::distance(biconnected_component.articulation_points.begin(),\n\
    \                        std::lower_bound(\n                            biconnected_component.articulation_points.begin(),\n\
    \                            biconnected_component.articulation_points.end(),\n\
    \                            i));\n      for (const int block : biconnected_component.cutpoint[i])\
    \ {\n        block_cut_tree[index].emplace_back(block + x);\n        block_cut_tree[block\
    \ + x].emplace_back(index);\n      }\n      ++weight[index];\n    } else {\n \
    \     ++weight[biconnected_component.id[i] + x];\n    }\n  }\n  for (int i = 0;\
    \ i < x + y; ++i) {\n    std::sort(block_cut_tree[i].begin(), block_cut_tree[i].end());\n\
    \    block_cut_tree[i].erase(\n        std::unique(block_cut_tree[i].begin(),\
    \ block_cut_tree[i].end()),\n        block_cut_tree[i].end());\n  }\n  long long\
    \ ans = static_cast<long long>(n) * (n - 1) / 2 * x;\n  const auto dfs = [n, x,\
    \ &block_cut_tree, &weight, &ans](\n      auto dfs, const int par, const int ver)\
    \ -> int {\n    int subtree = weight[ver];\n    if (ver < x) {\n      for (const\
    \ int e : block_cut_tree[ver]) {\n        if (e != par) {\n          const int\
    \ child = dfs(dfs, ver, e);\n          ans -= static_cast<long long>(child) *\
    \ (child - 1) / 2 + child;\n          subtree += child;\n        }\n      }\n\
    \      ans -= static_cast<long long>(n - subtree) * (n - subtree - 1) / 2\n  \
    \           + (n - subtree);\n    } else {\n      for (const int e : block_cut_tree[ver])\
    \ {\n        if (e != par) subtree += dfs(dfs, ver, e);\n      }\n    }\n    return\
    \ subtree;\n  };\n  assert(dfs(dfs, -1, 0) == n);\n  std::cout << ans << '\\n';\n\
    \  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/biconnected_component.hpp
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/lowlink.hpp
  isVerificationFile: true
  path: test/graph/biconnected_component.test.cpp
  requiredBy: []
  timestamp: '2023-05-12 15:57:02+09:00'
  verificationStatus: TEST_WAITING_JUDGE
  verifiedWith: []
documentation_of: test/graph/biconnected_component.test.cpp
layout: document
redirect_from:
- /verify/test/graph/biconnected_component.test.cpp
- /verify/test/graph/biconnected_component.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u5206\u89E3"
---
