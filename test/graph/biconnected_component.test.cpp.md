---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/biconnected_component.hpp
    title: "\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206 (biconnected component)\
      \ \u5206\u89E3"
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  - icon: ':question:'
    path: graph/lowlink.hpp
    title: lowlink
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_CLANG: ''
    IGNORE_IF_GCC: ''
    document_title: "\u30B0\u30E9\u30D5/\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\
      \u5206\u5206\u89E3"
    links:
    - https://atcoder.jp/contests/nadafes2022_day2/tasks/nadafes2022_day2_h
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\n * @brief \u30B0\u30E9\u30D5/\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\
    \u5206\u5206\u89E3\n */\n#define IGNORE\n#define PROBLEM \"https://atcoder.jp/contests/nadafes2022_day2/tasks/nadafes2022_day2_h\"\
    \n\n#include <algorithm>\n#include <cassert>\n#include <functional>\n#include\
    \ <iostream>\n#include <iterator>\n#include <set>\n#include <utility>\n#include\
    \ <vector>\n\n#include \"../../graph/biconnected_component.hpp\"\n#include \"\
    ../../graph/edge.hpp\"\n\nint main() {\n  int n, m;\n  std::cin >> n >> m;\n \
    \ std::vector<std::vector<Edge<bool>>> graph(n);\n  while (m--) {\n    int a,\
    \ b;\n    std::cin >> a >> b;\n    --a; --b;\n    graph[a].emplace_back(a, b);\n\
    \    graph[b].emplace_back(b, a);\n  }\n  BiconnectedComponent<bool> biconnected_component(graph,\
    \ true);\n  const int x = biconnected_component.articulation_points.size();\n\
    \  const int y = biconnected_component.vertices.size();\n  std::sort(biconnected_component.articulation_points.begin(),\n\
    \            biconnected_component.articulation_points.end());\n  std::vector<std::vector<int>>\
    \ block_cut_tree(x + y);\n  std::vector<int> weight(x + y, 0);\n  for (int i =\
    \ 0; i < n; ++i) {\n    if (biconnected_component.id[i] == -1) {\n      const\
    \ int index =\n          std::distance(biconnected_component.articulation_points.begin(),\n\
    \                        std::lower_bound(\n                            biconnected_component.articulation_points.begin(),\
    \ biconnected_component.articulation_points.end(),\n                         \
    \   i));\n      for (const int block : biconnected_component.cutpoint[i]) {\n\
    \        block_cut_tree[index].emplace_back(block + x);\n        block_cut_tree[block\
    \ + x].emplace_back(index);\n      }\n      ++weight[index];\n    } else {\n \
    \     ++weight[biconnected_component.id[i] + x];\n    }\n  }\n  for (int i = 0;\
    \ i < x + y; ++i) {\n    std::sort(block_cut_tree[i].begin(), block_cut_tree[i].end());\n\
    \    block_cut_tree[i].erase(\n        std::unique(block_cut_tree[i].begin(),\
    \ block_cut_tree[i].end()),\n        block_cut_tree[i].end());\n  }\n  long long\
    \ ans = static_cast<long long>(n) * (n - 1) / 2 * x;\n  const std::function<int(int,\
    \ int)> dfs =\n      [n, x, &block_cut_tree, &weight, &ans, &dfs](\n         \
    \ const int par, const int ver) -> int {\n        int subtree = weight[ver];\n\
    \        if (ver < x) {\n          for (const int e : block_cut_tree[ver]) {\n\
    \            if (e != par) {\n              const int child = dfs(ver, e);\n \
    \             ans -= static_cast<long long>(child) * (child - 1) / 2 + child;\n\
    \              subtree += child;\n            }\n          }\n          ans -=\
    \ static_cast<long long>(n - subtree) * (n - subtree - 1) / 2\n              \
    \   + (n - subtree);\n        } else {\n          for (const int e : block_cut_tree[ver])\
    \ {\n            if (e != par) subtree += dfs(ver, e);\n          }\n        }\n\
    \        return subtree;\n      };\n  assert(dfs(-1, 0) == n);\n  std::cout <<\
    \ ans << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - graph/biconnected_component.hpp
  - graph/edge.hpp
  - graph/lowlink.hpp
  isVerificationFile: true
  path: test/graph/biconnected_component.test.cpp
  requiredBy: []
  timestamp: '2022-05-23 03:48:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/biconnected_component.test.cpp
layout: document
redirect_from:
- /verify/test/graph/biconnected_component.test.cpp
- /verify/test/graph/biconnected_component.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u5206\u89E3"
---
