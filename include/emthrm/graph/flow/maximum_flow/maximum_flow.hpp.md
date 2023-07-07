---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/flow/maximum_flow/maximum_flow_with_lower_bound_constraint.hpp
    title: "\u6700\u5C0F\u6D41\u91CF\u5236\u7D04\u4ED8\u304D\u6700\u5927\u6D41"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/flow/maximum_flow/project_selection_problem.hpp
    title: project selection problem
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/flow/maximum_flow/maximum_flow_with_lower_bound_constraint.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5927\u6D41/\u6700\u5C0F\u6D41\
      \u91CF\u5236\u7D04\u4ED8\u304D\u6700\u5927\u6D41"
  - icon: ':heavy_check_mark:'
    path: test/graph/flow/maximum_flow/project_selection_problem.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5927\u6D41/project selection\
      \ problem"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6700\u5927\u6D41\u30B3\u30F3\u30BB\u30D7\u30C8"
    links: []
  bundledCode: "#line 1 \"include/emthrm/graph/flow/maximum_flow/maximum_flow.hpp\"\
    \n/**\n * @title \u6700\u5927\u6D41\u30B3\u30F3\u30BB\u30D7\u30C8\n */\n\n#ifndef\
    \ EMTHRM_GRAPH_FLOW_MAXIMUM_FLOW_MAXIMUM_FLOW_HPP_\n#define EMTHRM_GRAPH_FLOW_MAXIMUM_FLOW_MAXIMUM_FLOW_HPP_\n\
    \n#include <concepts>\n#include <utility>\n\nnamespace emthrm {\n\ntemplate <template\
    \ <typename> class C, typename T>\nconcept MaximumFlow = requires (C<T> mf) {\n\
    \  {mf.add_edge(std::declval<int>(), std::declval<int>(), std::declval<T>())}\n\
    \      -> std::same_as<void>;\n  {mf.maximum_flow(std::declval<int>(), std::declval<int>())}\n\
    \      -> std::same_as<T>;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_FLOW_MAXIMUM_FLOW_MAXIMUM_FLOW_HPP_\n"
  code: "/**\n * @title \u6700\u5927\u6D41\u30B3\u30F3\u30BB\u30D7\u30C8\n */\n\n\
    #ifndef EMTHRM_GRAPH_FLOW_MAXIMUM_FLOW_MAXIMUM_FLOW_HPP_\n#define EMTHRM_GRAPH_FLOW_MAXIMUM_FLOW_MAXIMUM_FLOW_HPP_\n\
    \n#include <concepts>\n#include <utility>\n\nnamespace emthrm {\n\ntemplate <template\
    \ <typename> class C, typename T>\nconcept MaximumFlow = requires (C<T> mf) {\n\
    \  {mf.add_edge(std::declval<int>(), std::declval<int>(), std::declval<T>())}\n\
    \      -> std::same_as<void>;\n  {mf.maximum_flow(std::declval<int>(), std::declval<int>())}\n\
    \      -> std::same_as<T>;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_FLOW_MAXIMUM_FLOW_MAXIMUM_FLOW_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/graph/flow/maximum_flow/maximum_flow.hpp
  requiredBy:
  - include/emthrm/graph/flow/maximum_flow/maximum_flow_with_lower_bound_constraint.hpp
  - include/emthrm/graph/flow/maximum_flow/project_selection_problem.hpp
  timestamp: '2023-02-24 21:17:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/flow/maximum_flow/maximum_flow_with_lower_bound_constraint.test.cpp
  - test/graph/flow/maximum_flow/project_selection_problem.test.cpp
documentation_of: include/emthrm/graph/flow/maximum_flow/maximum_flow.hpp
layout: document
redirect_from:
- /library/include/emthrm/graph/flow/maximum_flow/maximum_flow.hpp
- /library/include/emthrm/graph/flow/maximum_flow/maximum_flow.hpp.html
title: "\u6700\u5927\u6D41\u30B3\u30F3\u30BB\u30D7\u30C8"
---
