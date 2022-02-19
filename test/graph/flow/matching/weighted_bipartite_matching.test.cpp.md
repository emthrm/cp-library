---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/flow/matching/weighted_bipartite_matching.hpp
    title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u91CD\u307F\u4ED8\u304D\u6700\u5927\
      \u30DE\u30C3\u30C1\u30F3\u30B0"
  - icon: ':question:'
    path: graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp
    title: "\u6700\u5C0F\u8CBB\u7528 $s$-$t$-\u30D5\u30ED\u30FC \u6700\u77ED\u8DEF\
      \u53CD\u5FA9\u6CD5\u7248"
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
    document_title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\
      \u30B0/\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u91CD\u307F\u4ED8\u304D\u6700\u5927\
      \u30DE\u30C3\u30C1\u30F3\u30B0"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2429
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/flow/matching/weighted_bipartite_matching.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\
    \u30B0/\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u91CD\u307F\u4ED8\u304D\u6700\u5927\
    \u30DE\u30C3\u30C1\u30F3\u30B0\r\n */\r\n#define IGNORE\r\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2429\"\r\n\r\n#include\
    \ <iostream>\r\n#include <string>\r\n#include <vector>\r\n\r\n#include \"../../../../graph/flow/matching/weighted_bipartite_matching.hpp\"\
    \r\n\r\nint main() {\r\n  int n;\r\n  std::cin >> n;\r\n  std::vector<std::vector<int>>\
    \ w(n, std::vector<int>(n));\r\n  for (int i = 0; i < n; ++i) {\r\n    for (int\
    \ j = 0; j < n; ++j) {\r\n      std:: cin >> w[i][j];\r\n    }\r\n  }\r\n  std::vector<std::vector<int>>\
    \ e(n, std::vector<int>(n));\r\n  for (int i = 0; i < n; ++i) {\r\n    for (int\
    \ j = 0; j < n; ++j) {\r\n      std:: cin >> e[i][j];\r\n    }\r\n  }\r\n  std::vector<std::string>\
    \ f(n);\r\n  long long ans = 0;\r\n  for (int i = 0; i < n; ++i) {\r\n    std::cin\
    \ >> f[i];\r\n    for (int j = 0; j < n; ++j) {\r\n      if (f[i][j] == 'o') ans\
    \ += e[i][j];\r\n    }\r\n  }\r\n  WeightedBipartiteMatching<long long> weighted_bipartite_matching(n,\
    \ n);\r\n  for (int i = 0; i < n; ++i) {\r\n    for (int j = 0; j < n; ++j) {\r\
    \n      weighted_bipartite_matching.add_edge(i, j,\r\n                       \
    \                    f[i][j] == 'o' ? e[i][j] : -w[i][j]);\r\n    }\r\n  }\r\n\
    \  std::cout << ans - weighted_bipartite_matching.solve() << '\\n';\r\n  std::vector<std::string>\
    \ taro(n, std::string(n, '.'));\r\n  const std::vector<int> matching = weighted_bipartite_matching.matching();\r\
    \n  for (int i = 0; i < n; ++i) {\r\n    taro[i][matching[i]] = 'o';\r\n  }\r\n\
    \  std::vector<int> r, c;\r\n  std::vector<std::string> operate;\r\n  for (int\
    \ i = 0; i < n; ++i) {\r\n    for (int j = 0; j < n; ++j) {\r\n      if (f[i][j]\
    \ != taro[i][j]) {\r\n        r.emplace_back(i);\r\n        c.emplace_back(j);\r\
    \n        operate.emplace_back(f[i][j] == 'o' ? \"erase\" : \"write\");\r\n  \
    \    }\r\n    }\r\n  }\r\n  const int cnt = r.size();\r\n  std::cout << cnt <<\
    \ '\\n';\r\n  for (int i = 0; i < cnt; ++i) {\r\n    std::cout << r[i] + 1 <<\
    \ ' ' << c[i] + 1 << ' ' << operate[i] << '\\n';\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - graph/flow/matching/weighted_bipartite_matching.hpp
  - graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp
  isVerificationFile: true
  path: test/graph/flow/matching/weighted_bipartite_matching.test.cpp
  requiredBy: []
  timestamp: '2022-02-16 15:47:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/flow/matching/weighted_bipartite_matching.test.cpp
layout: document
redirect_from:
- /verify/test/graph/flow/matching/weighted_bipartite_matching.test.cpp
- /verify/test/graph/flow/matching/weighted_bipartite_matching.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\u30B0/\u4E8C\
  \u90E8\u30B0\u30E9\u30D5\u306E\u91CD\u307F\u4ED8\u304D\u6700\u5927\u30DE\u30C3\u30C1\
  \u30F3\u30B0"
---
