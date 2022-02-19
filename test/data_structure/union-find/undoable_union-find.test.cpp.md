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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data_structure/union-find/undoable_union-find.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/*\r\n * @brief \u30C7\u30FC\u30BF\u69CB\u9020/union-find/undo \u53EF\u80FD\
    \ union-find\r\n */\r\n#define IGNORE\r\n#define PROBLEM \"https://atcoder.jp/contests/joi2022yo2/tasks/joi2022_yo2_e\"\
    \r\n\r\n#include <algorithm>\r\n#include <iostream>\r\n#include <map>\r\n#include\
    \ <utility>\r\n#include <vector>\r\n\r\n#include \"../../../data_structure/union-find/undoable_union-find.hpp\"\
    \r\n\r\nint main() {\r\n  int n, m, k;\r\n  std::cin >> n >> m >> k;\r\n  std::vector<int>\
    \ u(m), v(m), s(n);\r\n  for (int i = 0; i < m; ++i) {\r\n    std::cin >> u[i]\
    \ >> v[i];\r\n    --u[i]; --v[i];\r\n  }\r\n  for (int i = 0; i < n; ++i) {\r\n\
    \    std::cin >> s[i];\r\n    --s[i];\r\n  }\r\n  UndoableUnionFind union_find(n);\r\
    \n  std::map<std::pair<int, int>, std::vector<int>> edges;\r\n  for (int i = 0;\
    \ i < m; ++i) {\r\n    if (s[u[i]] == s[v[i]]) {\r\n      union_find.unite(u[i],\
    \ v[i]);\r\n    } else {\r\n      edges[std::minmax(s[u[i]], s[v[i]])].emplace_back(i);\r\
    \n    }\r\n  }\r\n  union_find.snapshot();\r\n  int q;\r\n  std::cin >> q;\r\n\
    \  std::map<std::pair<int, int>, std::vector<int>> queries;\r\n  std::vector<int>\
    \ a(q), b(q);\r\n  for (int i = 0; i < q; ++i) {\r\n    std::cin >> a[i] >> b[i];\r\
    \n    --a[i]; --b[i];\r\n    queries[std::minmax(s[a[i]], s[b[i]])].emplace_back(i);\r\
    \n  }\r\n  std::vector<int> ans(q);\r\n  for (const auto& sasb_query : queries)\
    \ {\r\n    if (edges.count(sasb_query.first)) {\r\n      for (const int id : edges[sasb_query.first])\
    \ {\r\n        union_find.unite(u[id], v[id]);\r\n      }\r\n    }\r\n    for\
    \ (const int id : sasb_query.second) {\r\n      ans[id] = union_find.is_same(a[id],\
    \ b[id]);\r\n    }\r\n    union_find.rollback();\r\n  }\r\n  for (int i = 0; i\
    \ < q; ++i) {\r\n    std::cout << ans[i] << '\\n';\r\n  }\r\n  return 0;\r\n}\r\
    \n"
  dependsOn:
  - data_structure/union-find/undoable_union-find.hpp
  isVerificationFile: true
  path: test/data_structure/union-find/undoable_union-find.test.cpp
  requiredBy: []
  timestamp: '2022-02-16 15:47:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/data_structure/union-find/undoable_union-find.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/union-find/undoable_union-find.test.cpp
- /verify/test/data_structure/union-find/undoable_union-find.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/union-find/undo \u53EF\u80FD union-find"
---
