---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/union-find/union-find.hpp
    title: "union-find \u6728"
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  - icon: ':x:'
    path: graph/matrix_tree_theorem.hpp
    title: "\u884C\u5217\u6728\u5B9A\u7406"
  - icon: ':question:'
    path: math/matrix/determinant.hpp
    title: "\u884C\u5217\u5F0F (determinant)"
  - icon: ':question:'
    path: math/matrix/matrix.hpp
    title: "\u884C\u5217 (matrix)"
  - icon: ':question:'
    path: math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
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
    document_title: "\u30B0\u30E9\u30D5/\u884C\u5217\u6728\u5B9A\u7406"
    links:
    - https://atcoder.jp/contests/arc018/tasks/arc018_4
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u884C\u5217\u6728\u5B9A\u7406\r\n */\r\
    \n#define IGNORE\r\n#define PROBLEM \"https://atcoder.jp/contests/arc018/tasks/arc018_4\"\
    \r\n\r\n#include <algorithm>\r\n#include <iostream>\r\n#include <iterator>\r\n\
    #include <vector>\r\n#include \"../../math/modint.hpp\"\r\n#include \"../../graph/edge.hpp\"\
    \r\n#include \"../../data_structure/union-find/union-find.hpp\"\r\n#include \"\
    ../../graph/matrix_tree_theorem.hpp\"\r\n\r\nint main() {\r\n  using ModInt =\
    \ MInt<0>;\r\n  ModInt::set_mod(1000000007);\r\n  int n, m;\r\n  std::cin >> n\
    \ >> m;\r\n  std::vector<int> costs;\r\n  std::vector<Edge<int>> edges;\r\n  for\
    \ (int i = 0; i < m; ++i) {\r\n    int a, b, c;\r\n    std::cin >> a >> b >> c;\r\
    \n    --a; --b;\r\n    edges.emplace_back(a, b, c);\r\n    costs.emplace_back(c);\r\
    \n  }\r\n  std::sort(costs.begin(), costs.end());\r\n  costs.erase(std::unique(costs.begin(),\
    \ costs.end()), costs.end());\r\n  std::vector<std::vector<Edge<int>>> divided(costs.size());\r\
    \n  for (int i = 0; i < m; ++i) {\r\n    divided[std::distance(costs.begin(),\
    \ std::lower_bound(costs.begin(), costs.end(), edges[i].cost))].emplace_back(edges[i]);\r\
    \n  }\r\n  UnionFind uf(n);\r\n  long long cost = 0;\r\n  ModInt way = 1;\r\n\
    \  for (int i = 0; i < costs.size(); ++i) {\r\n    std::vector<int> vers;\r\n\
    \    for (Edge<int> &e : divided[i]) {\r\n      e.src = uf.root(e.src);\r\n  \
    \    e.dst = uf.root(e.dst);\r\n      if (e.src != e.dst) {\r\n        vers.emplace_back(e.src);\r\
    \n        vers.emplace_back(e.dst);\r\n      }\r\n    }\r\n    if (vers.empty())\
    \ continue;\r\n    for (const Edge<int> &e : divided[i]) {\r\n      if (uf.unite(e.src,\
    \ e.dst)) cost += e.cost;\r\n    }\r\n    std::sort(vers.begin(), vers.end());\r\
    \n    vers.erase(std::unique(vers.begin(), vers.end()), vers.end());\r\n    int\
    \ sz = vers.size();\r\n    UnionFind span(sz);\r\n    for (Edge<int> &e : divided[i])\
    \ {\r\n      if (e.src != e.dst) {\r\n        e.src = std::distance(vers.begin(),\
    \ std::lower_bound(vers.begin(), vers.end(), e.src));\r\n        e.dst = std::distance(vers.begin(),\
    \ std::lower_bound(vers.begin(), vers.end(), e.dst));\r\n        span.unite(e.src,\
    \ e.dst);\r\n      }\r\n    }\r\n    std::vector<std::vector<Edge<int>>> divided2(sz);\r\
    \n    for (const Edge<int> &e : divided[i]) {\r\n      if (e.src != e.dst) divided2[span.root(e.src)].emplace_back(e);\r\
    \n    }\r\n    for (int j = 0; j < sz; ++j) {\r\n      if (divided2[j].size()\
    \ > 0) {\r\n        std::vector<int> comp;\r\n        for (const Edge<int> &e\
    \ : divided2[j]) {\r\n          comp.emplace_back(e.src);\r\n          comp.emplace_back(e.dst);\r\
    \n        }\r\n        std::sort(comp.begin(), comp.end());\r\n        comp.erase(std::unique(comp.begin(),\
    \ comp.end()), comp.end());\r\n        std::vector<std::vector<Edge<int>>> graph(comp.size());\r\
    \n        for (Edge<int> &e : divided2[j]) {\r\n          e.src = std::distance(comp.begin(),\
    \ std::lower_bound(comp.begin(), comp.end(), e.src));\r\n          e.dst = std::distance(comp.begin(),\
    \ std::lower_bound(comp.begin(), comp.end(), e.dst));\r\n          graph[e.src].emplace_back(e.src,\
    \ e.dst, e.cost);\r\n          graph[e.dst].emplace_back(e.dst, e.src, e.cost);\r\
    \n        }\r\n        way *= matrix_tree_theorem(graph, ModInt(0));\r\n     \
    \ }\r\n    }\r\n  }\r\n  std::cout << cost << ' ' << way << '\\n';\r\n  return\
    \ 0;\r\n}\r\n"
  dependsOn:
  - math/modint.hpp
  - graph/edge.hpp
  - data_structure/union-find/union-find.hpp
  - graph/matrix_tree_theorem.hpp
  - math/matrix/matrix.hpp
  - math/matrix/determinant.hpp
  isVerificationFile: true
  path: test/graph/matrix_tree_theorem.test.cpp
  requiredBy: []
  timestamp: '2021-02-15 03:05:11+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/matrix_tree_theorem.test.cpp
layout: document
redirect_from:
- /verify/test/graph/matrix_tree_theorem.test.cpp
- /verify/test/graph/matrix_tree_theorem.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u884C\u5217\u6728\u5B9A\u7406"
---
