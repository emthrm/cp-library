---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/union-find/union-find.hpp
    title: union-find
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
    - https://atcoder.jp/contests/jsc2021/tasks/jsc2021_g
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data_structure/union-find/union-find.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u884C\u5217\u6728\u5B9A\u7406\r\n */\r\
    \n#define IGNORE\r\n#define PROBLEM \"https://atcoder.jp/contests/jsc2021/tasks/jsc2021_g\"\
    \r\n\r\n#include <algorithm>\r\n#include <iostream>\r\n#include <iterator>\r\n\
    #include <vector>\r\n#include \"../../math/modint.hpp\"\r\n#include \"../../data_structure/union-find/union-find.hpp\"\
    \r\n#include \"../../graph/edge.hpp\"\r\n#include \"../../graph/matrix_tree_theorem.hpp\"\
    \r\n\r\nint main() {\r\n  using ModInt = MInt<0>;\r\n  ModInt::set_mod(1000000007);\r\
    \n  int n;\r\n  std::cin >> n;\r\n  std::vector<std::vector<int>> a(n, std::vector<int>(n));\r\
    \n  for (int i = 0; i < n; ++i) {\r\n    for (int j = 0; j < n; ++j) {\r\n   \
    \   std::cin >> a[i][j];\r\n    }\r\n  }\r\n  UnionFind uf(n);\r\n  for (int i\
    \ = 0; i < n; ++i) {\r\n    for (int j = i + 1; j < n; ++j) {\r\n      if (a[i][j]\
    \ == 1 && !uf.unite(i, j)) {\r\n        std::cout << 0 << '\\n';\r\n        return\
    \ 0;\r\n      }\r\n    }\r\n  }\r\n  std::vector<int> root;\r\n  for (int i =\
    \ 0; i < n; ++i) {\r\n    if (uf.root(i) == i) {\r\n      root.emplace_back(i);\r\
    \n    }\r\n  }\r\n  std::vector<int> id(n);\r\n  for (int i = 0; i < n; ++i) {\r\
    \n    id[i] = std::distance(root.begin(), std::lower_bound(root.begin(), root.end(),\
    \ uf.root(i)));\r\n  }\r\n  const int m = root.size();\r\n  std::vector<std::vector<Edge<bool>>>\
    \ graph(m);\r\n  for (int i = 0; i < n; ++i) {\r\n    for (int j = i + 1; j <\
    \ n; ++j) {\r\n      if (a[i][j] == -1) {\r\n        graph[id[i]].emplace_back(id[i],\
    \ id[j]);\r\n        graph[id[j]].emplace_back(id[j], id[i]);\r\n      }\r\n \
    \   }\r\n  }\r\n  std::cout << matrix_tree_theorem(graph, ModInt(0)) << '\\n';\r\
    \n  return 0;\r\n}\r\n"
  dependsOn:
  - math/modint.hpp
  - data_structure/union-find/union-find.hpp
  - graph/edge.hpp
  - graph/matrix_tree_theorem.hpp
  - math/matrix/matrix.hpp
  - math/matrix/determinant.hpp
  isVerificationFile: true
  path: test/graph/matrix_tree_theorem.test.cpp
  requiredBy: []
  timestamp: '2021-09-24 01:25:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/matrix_tree_theorem.test.cpp
layout: document
redirect_from:
- /verify/test/graph/matrix_tree_theorem.test.cpp
- /verify/test/graph/matrix_tree_theorem.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u884C\u5217\u6728\u5B9A\u7406"
---
