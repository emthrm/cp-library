---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/2-edge-connected_components_by_imos.hpp
    title: "\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3 \u3044\u3082\u3059\
      \u6CD5\u7248"
  - icon: ':x:'
    path: graph/2-edge-connected_components_by_lowlink.hpp
    title: "\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3 lowlink \u7248"
  - icon: ':x:'
    path: graph/biconnected_component.hpp
    title: "\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206 (biconnected component)\
      \ \u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: graph/chromatic_number.hpp
    title: "\u5F69\u8272\u6570 (chromatic number)"
  - icon: ':x:'
    path: graph/connencted_component_of_complement_graph.hpp
    title: "\u88DC\u30B0\u30E9\u30D5\u306E\u9023\u7D50\u6210\u5206\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: graph/detect_directed_cycle.hpp
    title: "\u6709\u5411\u9589\u8DEF\u306E\u691C\u51FA"
  - icon: ':x:'
    path: graph/detect_path.hpp
    title: "\u9053\u306E\u691C\u51FA"
  - icon: ':heavy_check_mark:'
    path: graph/enumerate_bridges.hpp
    title: "\u6A4B\u306E\u691C\u51FA"
  - icon: ':x:'
    path: graph/eulerian_trail_in_directed_graph.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u8DEF \u6709\u5411\u30B0\u30E9\u30D5\u7248"
  - icon: ':heavy_check_mark:'
    path: graph/girth_in_directed_graph.hpp
    title: "\u5185\u5468 \u6709\u5411\u30B0\u30E9\u30D5\u7248"
  - icon: ':heavy_check_mark:'
    path: graph/girth_in_undirected_graph.hpp
    title: "\u5185\u5468 \u7121\u5411\u30B0\u30E9\u30D5\u7248"
  - icon: ':heavy_check_mark:'
    path: graph/is_bipartite.hpp
    title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: graph/kruskal.hpp
    title: "Kruskal \u6CD5"
  - icon: ':question:'
    path: graph/lowlink.hpp
    title: lowlink
  - icon: ':x:'
    path: graph/matrix_tree_theorem.hpp
    title: "\u884C\u5217\u6728\u5B9A\u7406"
  - icon: ':x:'
    path: graph/noshi_graph.hpp
    title: "\u533A\u9593\u306B\u8FBA\u3092\u5F35\u308B\u30C6\u30AF"
  - icon: ':heavy_check_mark:'
    path: graph/prim.hpp
    title: "Prim \u6CD5"
  - icon: ':x:'
    path: graph/reachability_on_dag.hpp
    title: "\u6709\u5411\u975E\u5DE1\u56DE\u30B0\u30E9\u30D5\u4E0A\u306E\u5230\u9054\
      \u53EF\u80FD\u6027\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: graph/shortest_path/bellman-ford.hpp
    title: "Bellman\u2013Ford \u6CD5"
  - icon: ':question:'
    path: graph/shortest_path/dijkstra.hpp
    title: "Dijkstra \u6CD5"
  - icon: ':heavy_check_mark:'
    path: graph/strongly_connected_components.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206 (strongly connected components) \u5206\u89E3"
  - icon: ':x:'
    path: graph/topological_sort.hpp
    title: "\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8 (topological sort)"
  - icon: ':heavy_check_mark:'
    path: graph/traveling_salesman_problem.hpp
    title: "\u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\u30F3\u554F\u984C (traveling\
      \ salesman problem)"
  - icon: ':heavy_check_mark:'
    path: graph/tree/centroid.hpp
    title: "\u91CD\u5FC3 (centroid)"
  - icon: ':heavy_check_mark:'
    path: graph/tree/centroid_decomposition.hpp
    title: "\u91CD\u5FC3\u5206\u89E3 (centroid decompositon)"
  - icon: ':heavy_check_mark:'
    path: graph/tree/double_sweep.hpp
    title: double sweep
  - icon: ':heavy_check_mark:'
    path: graph/tree/euler_tour.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC (Euler tour)"
  - icon: ':heavy_check_mark:'
    path: graph/tree/heavy-light_decomposition.hpp
    title: "HL \u5206\u89E3 (heavy-light decomposition)"
  - icon: ':question:'
    path: graph/tree/lowest_common_ancestor_by_doubling.hpp
    title: "\u6700\u5C0F\u5171\u901A\u7956\u5148 \u30C0\u30D6\u30EA\u30F3\u30B0\u7248"
  - icon: ':heavy_check_mark:'
    path: graph/tree/lowest_common_ancestor_by_euler_tour.hpp
    title: "\u6700\u5C0F\u5171\u901A\u7956\u5148 \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\
      \u30FC\u7248"
  - icon: ':heavy_check_mark:'
    path: graph/tree/rerooting_dp.hpp
    title: "\u5168\u65B9\u4F4D\u6728 DP"
  - icon: ':heavy_check_mark:'
    path: graph/unicyclic_graph.hpp
    title: unicyclic graph / 1-tree
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/2-edge-connected_components_by_imos.test.cpp
    title: "\u30B0\u30E9\u30D5/\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\
      \ \u3044\u3082\u3059\u6CD5\u7248"
  - icon: ':x:'
    path: test/graph/2-edge-connected_components_by_lowlink.test.cpp
    title: "\u30B0\u30E9\u30D5/\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\
      \ lowlink \u7248"
  - icon: ':x:'
    path: test/graph/biconnected_component.test.cpp
    title: "\u30B0\u30E9\u30D5/\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u5206\
      \u89E3"
  - icon: ':heavy_check_mark:'
    path: test/graph/chromatic_number.test.cpp
    title: "\u30B0\u30E9\u30D5/\u5F69\u8272\u6570"
  - icon: ':x:'
    path: test/graph/connencted_component_of_complement_graph.test.cpp
    title: "\u30B0\u30E9\u30D5/\u88DC\u30B0\u30E9\u30D5\u306E\u9023\u7D50\u6210\u5206\
      \u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: test/graph/detect_directed_cycle.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6709\u5411\u9589\u8DEF\u306E\u691C\u51FA"
  - icon: ':x:'
    path: test/graph/detect_path.test.cpp
    title: "\u30B0\u30E9\u30D5/\u9053\u306E\u691C\u51FA"
  - icon: ':heavy_check_mark:'
    path: test/graph/enumerate_bridges.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6A4B\u306E\u5217\u6319"
  - icon: ':x:'
    path: test/graph/eulerian_trail_in_directed_graph.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30AA\u30A4\u30E9\u30FC\u8DEF \u6709\u5411\u30B0\u30E9\
      \u30D5\u7248"
  - icon: ':heavy_check_mark:'
    path: test/graph/flow/minimum_cost_flow/minimum_cost_flow_with_lower_bound_constraint.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5C0F\u8CBB\u7528\u6D41/\u6700\
      \u5C0F\u6D41\u91CF\u5236\u7D04\u4ED8\u304D\u6700\u5C0F\u8CBB\u7528\u6D41"
  - icon: ':heavy_check_mark:'
    path: test/graph/girth.test.cpp
    title: "\u30B0\u30E9\u30D5/\u5185\u5468"
  - icon: ':heavy_check_mark:'
    path: test/graph/is_bipartite.test.cpp
    title: "\u30B0\u30E9\u30D5/\u4E8C\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: test/graph/kruskal.test.cpp
    title: "\u30B0\u30E9\u30D5/Kruskal \u6CD5"
  - icon: ':heavy_check_mark:'
    path: test/graph/lowlink.1.test.cpp
    title: "\u30B0\u30E9\u30D5/lowlink (\u6A4B)"
  - icon: ':heavy_check_mark:'
    path: test/graph/lowlink.2.test.cpp
    title: "\u30B0\u30E9\u30D5/lowlink (\u95A2\u7BC0\u70B9)"
  - icon: ':x:'
    path: test/graph/matrix_tree_theorem.test.cpp
    title: "\u30B0\u30E9\u30D5/\u884C\u5217\u6728\u5B9A\u7406"
  - icon: ':x:'
    path: test/graph/noshi_graph.test.cpp
    title: "\u30B0\u30E9\u30D5/\u533A\u9593\u306B\u8FBA\u3092\u5F35\u308B\u30C6\u30AF"
  - icon: ':heavy_check_mark:'
    path: test/graph/prim.test.cpp
    title: "\u30B0\u30E9\u30D5/Prim \u6CD5"
  - icon: ':x:'
    path: test/graph/reachability_on_dag.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6709\u5411\u975E\u5DE1\u56DE\u30B0\u30E9\u30D5\u4E0A\
      \u306E\u5230\u9054\u53EF\u80FD\u6027\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: test/graph/shortest_path/bellman-ford.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6700\u77ED\u8DEF\u554F\u984C/Bellman\u2013Ford \u6CD5"
  - icon: ':heavy_check_mark:'
    path: test/graph/shortest_path/dijkstra.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6700\u77ED\u8DEF\u554F\u984C/Dijkstra \u6CD5"
  - icon: ':heavy_check_mark:'
    path: test/graph/strongly_connected_components.test.cpp
    title: "\u30B0\u30E9\u30D5/\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
  - icon: ':x:'
    path: test/graph/topological_sort.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: test/graph/traveling_salesman_problem.test.cpp
    title: "\u30B0\u30E9\u30D5/\u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\u30F3\u554F\
      \u984C"
  - icon: ':heavy_check_mark:'
    path: test/graph/tree/centroid.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6728/\u91CD\u5FC3"
  - icon: ':heavy_check_mark:'
    path: test/graph/tree/centroid_decomposition.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6728/\u91CD\u5FC3\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: test/graph/tree/double_sweep.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6728/double sweep"
  - icon: ':heavy_check_mark:'
    path: test/graph/tree/heavy-light_decomposition.1.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6728/HL \u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: test/graph/tree/heavy-light_decomposition.2.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6728/HL \u5206\u89E3 (\u6700\u5C0F\u5171\u901A\u7956\
      \u5148)"
  - icon: ':heavy_check_mark:'
    path: test/graph/tree/lowest_common_ancestor_by_doubling.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6728/\u6700\u5C0F\u5171\u901A\u7956\u5148 \u30C0\u30D6\
      \u30EA\u30F3\u30B0\u7248"
  - icon: ':heavy_check_mark:'
    path: test/graph/tree/lowest_common_ancestor_by_euler_tour.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6728/\u6700\u5C0F\u5171\u901A\u7956\u5148 \u30AA\u30A4\
      \u30E9\u30FC\u30C4\u30A2\u30FC\u7248"
  - icon: ':heavy_check_mark:'
    path: test/graph/tree/rerooting_dp.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6728/\u5168\u65B9\u4F4D\u6728 DP"
  - icon: ':heavy_check_mark:'
    path: test/graph/unicyclic_graph.test.cpp
    title: "\u30B0\u30E9\u30D5/unicyclic graph"
  - icon: ':heavy_check_mark:'
    path: test/math/basis.test.cpp
    title: "\u6570\u5B66/\u57FA\u5E95"
  - icon: ':heavy_check_mark:'
    path: test/math/matrix/linear_equation.test.cpp
    title: "\u6570\u5B66/\u884C\u5217/\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "\u8FBA"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/**\n * @brief \u8FBA\n */\n\n#pragma once\n\ntemplate <typename CostType>\n\
    struct Edge {\n  int src, dst;\n  CostType cost;\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : src(src), dst(dst), cost(cost)\
    \ {}\n  inline bool operator<(const Edge& x) const {\n    if (cost != x.cost)\
    \ return cost < x.cost;\n    return src != x.src ? src < x.src : dst < x.dst;\n\
    \  }\n  inline bool operator<=(const Edge& x) const { return !(x < *this); }\n\
    \  inline bool operator>(const Edge& x) const { return x < *this; }\n  inline\
    \ bool operator>=(const Edge& x) const { return !(*this < x); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/edge.hpp
  requiredBy:
  - graph/girth_in_directed_graph.hpp
  - graph/topological_sort.hpp
  - graph/noshi_graph.hpp
  - graph/traveling_salesman_problem.hpp
  - graph/tree/centroid.hpp
  - graph/tree/lowest_common_ancestor_by_doubling.hpp
  - graph/tree/euler_tour.hpp
  - graph/tree/heavy-light_decomposition.hpp
  - graph/tree/lowest_common_ancestor_by_euler_tour.hpp
  - graph/tree/centroid_decomposition.hpp
  - graph/tree/double_sweep.hpp
  - graph/tree/rerooting_dp.hpp
  - graph/reachability_on_dag.hpp
  - graph/unicyclic_graph.hpp
  - graph/chromatic_number.hpp
  - graph/lowlink.hpp
  - graph/connencted_component_of_complement_graph.hpp
  - graph/girth_in_undirected_graph.hpp
  - graph/strongly_connected_components.hpp
  - graph/detect_path.hpp
  - graph/eulerian_trail_in_directed_graph.hpp
  - graph/is_bipartite.hpp
  - graph/2-edge-connected_components_by_imos.hpp
  - graph/detect_directed_cycle.hpp
  - graph/2-edge-connected_components_by_lowlink.hpp
  - graph/enumerate_bridges.hpp
  - graph/shortest_path/bellman-ford.hpp
  - graph/shortest_path/dijkstra.hpp
  - graph/matrix_tree_theorem.hpp
  - graph/prim.hpp
  - graph/kruskal.hpp
  - graph/biconnected_component.hpp
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/math/basis.test.cpp
  - test/math/matrix/linear_equation.test.cpp
  - test/graph/flow/minimum_cost_flow/minimum_cost_flow_with_lower_bound_constraint.test.cpp
  - test/graph/biconnected_component.test.cpp
  - test/graph/is_bipartite.test.cpp
  - test/graph/unicyclic_graph.test.cpp
  - test/graph/tree/heavy-light_decomposition.2.test.cpp
  - test/graph/tree/centroid_decomposition.test.cpp
  - test/graph/tree/double_sweep.test.cpp
  - test/graph/tree/lowest_common_ancestor_by_doubling.test.cpp
  - test/graph/tree/lowest_common_ancestor_by_euler_tour.test.cpp
  - test/graph/tree/centroid.test.cpp
  - test/graph/tree/heavy-light_decomposition.1.test.cpp
  - test/graph/tree/rerooting_dp.test.cpp
  - test/graph/detect_path.test.cpp
  - test/graph/reachability_on_dag.test.cpp
  - test/graph/chromatic_number.test.cpp
  - test/graph/strongly_connected_components.test.cpp
  - test/graph/connencted_component_of_complement_graph.test.cpp
  - test/graph/girth.test.cpp
  - test/graph/2-edge-connected_components_by_lowlink.test.cpp
  - test/graph/lowlink.2.test.cpp
  - test/graph/traveling_salesman_problem.test.cpp
  - test/graph/2-edge-connected_components_by_imos.test.cpp
  - test/graph/kruskal.test.cpp
  - test/graph/prim.test.cpp
  - test/graph/eulerian_trail_in_directed_graph.test.cpp
  - test/graph/matrix_tree_theorem.test.cpp
  - test/graph/detect_directed_cycle.test.cpp
  - test/graph/enumerate_bridges.test.cpp
  - test/graph/shortest_path/bellman-ford.test.cpp
  - test/graph/shortest_path/dijkstra.test.cpp
  - test/graph/noshi_graph.test.cpp
  - test/graph/topological_sort.test.cpp
  - test/graph/lowlink.1.test.cpp
documentation_of: graph/edge.hpp
layout: document
redirect_from:
- /library/graph/edge.hpp
- /library/graph/edge.hpp.html
title: "\u8FBA"
---
