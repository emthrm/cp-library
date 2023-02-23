---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/data_structure/union-find/union-find.hpp
    title: union-find
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':x:'
    path: include/emthrm/graph/matrix_tree_theorem.hpp
    title: "\u884C\u5217\u6728\u5B9A\u7406"
  - icon: ':question:'
    path: include/emthrm/math/matrix/determinant.hpp
    title: "\u884C\u5217\u5F0F (determinant)"
  - icon: ':question:'
    path: include/emthrm/math/matrix/matrix.hpp
    title: "\u884C\u5217 (matrix)"
  - icon: ':question:'
    path: include/emthrm/math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_GCC: ''
    document_title: "\u30B0\u30E9\u30D5/\u884C\u5217\u6728\u5B9A\u7406"
    links:
    - https://atcoder.jp/contests/jsc2021/tasks/jsc2021_g
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/data_structure/union-find/union-find.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u30B0\u30E9\u30D5/\u884C\u5217\u6728\u5B9A\u7406\n */\n#define\
    \ IGNORE\n#define PROBLEM \"https://atcoder.jp/contests/jsc2021/tasks/jsc2021_g\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <iterator>\n#include <vector>\n\
    \n#include \"emthrm/data_structure/union-find/union-find.hpp\"\n#include \"emthrm/graph/edge.hpp\"\
    \n#include \"emthrm/graph/matrix_tree_theorem.hpp\"\n#include \"emthrm/math/modint.hpp\"\
    \n\nint main() {\n  using ModInt = emthrm::MInt<1000000007>;\n  int n;\n  std::cin\
    \ >> n;\n  std::vector<std::vector<int>> a(n, std::vector<int>(n));\n  for (int\
    \ i = 0; i < n; ++i) {\n    for (int j = 0; j < n; ++j) {\n      std::cin >> a[i][j];\n\
    \    }\n  }\n  emthrm::UnionFind union_find(n);\n  for (int i = 0; i < n; ++i)\
    \ {\n    for (int j = i + 1; j < n; ++j) {\n      if (a[i][j] == 1 && !union_find.unite(i,\
    \ j)) {\n        std::cout << 0 << '\\n';\n        return 0;\n      }\n    }\n\
    \  }\n  std::vector<int> root;\n  for (int i = 0; i < n; ++i) {\n    if (union_find.root(i)\
    \ == i) root.emplace_back(i);\n  }\n  std::vector<int> id(n);\n  for (int i =\
    \ 0; i < n; ++i) {\n    id[i] = std::distance(\n        root.begin(),\n      \
    \  std::lower_bound(root.begin(), root.end(), union_find.root(i)));\n  }\n  const\
    \ int m = root.size();\n  std::vector<std::vector<emthrm::Edge<bool>>> graph(m);\n\
    \  for (int i = 0; i < n; ++i) {\n    for (int j = i + 1; j < n; ++j) {\n    \
    \  if (a[i][j] == -1) {\n        graph[id[i]].emplace_back(id[i], id[j]);\n  \
    \      graph[id[j]].emplace_back(id[j], id[i]);\n      }\n    }\n  }\n  std::cout\
    \ << emthrm::matrix_tree_theorem(graph, ModInt(0)) << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/data_structure/union-find/union-find.hpp
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/matrix_tree_theorem.hpp
  - include/emthrm/math/matrix/determinant.hpp
  - include/emthrm/math/matrix/matrix.hpp
  - include/emthrm/math/modint.hpp
  isVerificationFile: true
  path: test/graph/matrix_tree_theorem.test.cpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/matrix_tree_theorem.test.cpp
layout: document
redirect_from:
- /verify/test/graph/matrix_tree_theorem.test.cpp
- /verify/test/graph/matrix_tree_theorem.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u884C\u5217\u6728\u5B9A\u7406"
---
