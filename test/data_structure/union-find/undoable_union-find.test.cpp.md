---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data_structure/union-find/undoable_union-find.hpp
    title: "undo \u53EF\u80FD union-find"
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
    document_title: "\u30C7\u30FC\u30BF\u69CB\u9020/union-find/undo \u53EF\u80FD union-find"
    links:
    - https://atcoder.jp/contests/joi2022yo2/tasks/joi2022_yo2_e
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data_structure/union-find/undoable_union-find.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/*\n * @brief \u30C7\u30FC\u30BF\u69CB\u9020/union-find/undo \u53EF\u80FD\
    \ union-find\n */\n#define IGNORE\n#define PROBLEM \"https://atcoder.jp/contests/joi2022yo2/tasks/joi2022_yo2_e\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <map>\n#include <utility>\n\
    #include <vector>\n\n#include \"../../../data_structure/union-find/undoable_union-find.hpp\"\
    \n\nint main() {\n  int n, m, k;\n  std::cin >> n >> m >> k;\n  std::vector<int>\
    \ u(m), v(m), s(n);\n  for (int i = 0; i < m; ++i) {\n    std::cin >> u[i] >>\
    \ v[i];\n    --u[i]; --v[i];\n  }\n  for (int i = 0; i < n; ++i) {\n    std::cin\
    \ >> s[i];\n    --s[i];\n  }\n  UndoableUnionFind union_find(n);\n  std::map<std::pair<int,\
    \ int>, std::vector<int>> edges;\n  for (int i = 0; i < m; ++i) {\n    if (s[u[i]]\
    \ == s[v[i]]) {\n      union_find.unite(u[i], v[i]);\n    } else {\n      edges[std::minmax(s[u[i]],\
    \ s[v[i]])].emplace_back(i);\n    }\n  }\n  union_find.snapshot();\n  int q;\n\
    \  std::cin >> q;\n  std::map<std::pair<int, int>, std::vector<int>> queries;\n\
    \  std::vector<int> a(q), b(q);\n  for (int i = 0; i < q; ++i) {\n    std::cin\
    \ >> a[i] >> b[i];\n    --a[i]; --b[i];\n    queries[std::minmax(s[a[i]], s[b[i]])].emplace_back(i);\n\
    \  }\n  std::vector<int> ans(q);\n  for (const auto& sasb_query : queries) {\n\
    \    if (edges.count(sasb_query.first)) {\n      for (const int id : edges[sasb_query.first])\
    \ {\n        union_find.unite(u[id], v[id]);\n      }\n    }\n    for (const int\
    \ id : sasb_query.second) {\n      ans[id] = union_find.is_same(a[id], b[id]);\n\
    \    }\n    union_find.rollback();\n  }\n  for (int i = 0; i < q; ++i) {\n   \
    \ std::cout << ans[i] << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - data_structure/union-find/undoable_union-find.hpp
  isVerificationFile: true
  path: test/data_structure/union-find/undoable_union-find.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/data_structure/union-find/undoable_union-find.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/union-find/undoable_union-find.test.cpp
- /verify/test/data_structure/union-find/undoable_union-find.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/union-find/undo \u53EF\u80FD union-find"
---
