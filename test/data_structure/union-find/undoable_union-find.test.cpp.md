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
    - https://codeforces.com/contest/1444/problem/C
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data_structure/union-find/undoable_union-find.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/*\r\n * @brief \u30C7\u30FC\u30BF\u69CB\u9020/union-find/undo \u53EF\u80FD\
    \ union-find\r\n */\r\n#define IGNORE\r\n#define PROBLEM \"https://codeforces.com/contest/1444/problem/C\"\
    \r\n\r\n#include <algorithm>\r\n#include <iostream>\r\n#include <map>\r\n#include\
    \ <tuple>\r\n#include <utility>\r\n#include <vector>\r\n#include \"../../../data_structure/union-find/undoable_union-find.hpp\"\
    \r\n\r\nint main() {\r\n  int n, m, k;\r\n  std::cin >> n >> m >> k;\r\n  std::vector<int>\
    \ c(n);\r\n  for (int i = 0; i < n; ++i) {\r\n    std::cin >> c[i];\r\n    --c[i];\r\
    \n  }\r\n  UndoableUnionFind union_find(n * 2);\r\n  std::map<std::pair<int, int>,\
    \ std::vector<std::pair<int, int>>> edge;\r\n  while (m--) {\r\n    int a, b;\r\
    \n    std::cin >> a >> b;\r\n    --a; --b;\r\n    if (c[a] == c[b]) {\r\n    \
    \  union_find.unite(a, b + n);\r\n      union_find.unite(b, a + n);\r\n    } else\
    \ {\r\n      if (c[a] > c[b]) {\r\n        std::swap(a, b);\r\n      }\r\n   \
    \   edge[{c[a], c[b]}].emplace_back(a, b);\r\n    }\r\n  }\r\n  std::vector<int>\
    \ is_bad(k, false);\r\n  for (int i = 0; i < n; ++i) {\r\n    if (union_find.is_same(i,\
    \ i + n)) {\r\n      is_bad[c[i]] = true;\r\n    }\r\n  }\r\n  const int good_group_num\
    \ = std::count(is_bad.begin(), is_bad.end(), false);\r\n  long long ans = static_cast<long\
    \ long>(good_group_num) * (good_group_num - 1) / 2;\r\n  union_find.snapshot();\r\
    \n  for (const std::pair<std::pair<int, int>, std::vector<std::pair<int, int>>>\
    \ &p : edge) {\r\n    if (is_bad[p.first.first] || is_bad[p.first.second]) continue;\r\
    \n    bool is_bad = false;\r\n    for (const std::pair<int, int> &e : p.second)\
    \ {\r\n      int a, b;\r\n      std::tie(a, b) = e;\r\n      union_find.unite(a,\
    \ b + n);\r\n      union_find.unite(b, a + n);\r\n      is_bad |= union_find.is_same(a,\
    \ a + n) || union_find.is_same(b, b + n);\r\n    }\r\n    union_find.rollback();\r\
    \n    ans -= is_bad;\r\n  }\r\n  std::cout << ans << '\\n';\r\n  return 0;\r\n\
    }\r\n"
  dependsOn:
  - data_structure/union-find/undoable_union-find.hpp
  isVerificationFile: true
  path: test/data_structure/union-find/undoable_union-find.test.cpp
  requiredBy: []
  timestamp: '2021-09-24 01:25:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/data_structure/union-find/undoable_union-find.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/union-find/undoable_union-find.test.cpp
- /verify/test/data_structure/union-find/undoable_union-find.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/union-find/undo \u53EF\u80FD union-find"
---
