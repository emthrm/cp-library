---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/flow/matching/weighted_bipartite_matching.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/*\n * @brief \u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\
    \u30B0/\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u91CD\u307F\u4ED8\u304D\u6700\u5927\
    \u30DE\u30C3\u30C1\u30F3\u30B0\n */\n#define IGNORE\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2429\"\
    \n\n#include <iostream>\n#include <string>\n#include <vector>\n\n#include \"../../../../graph/flow/matching/weighted_bipartite_matching.hpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  std::vector<std::vector<int>>\
    \ w(n, std::vector<int>(n));\n  for (int i = 0; i < n; ++i) {\n    for (int j\
    \ = 0; j < n; ++j) {\n      std:: cin >> w[i][j];\n    }\n  }\n  std::vector<std::vector<int>>\
    \ e(n, std::vector<int>(n));\n  for (int i = 0; i < n; ++i) {\n    for (int j\
    \ = 0; j < n; ++j) {\n      std:: cin >> e[i][j];\n    }\n  }\n  std::vector<std::string>\
    \ f(n);\n  long long ans = 0;\n  for (int i = 0; i < n; ++i) {\n    std::cin >>\
    \ f[i];\n    for (int j = 0; j < n; ++j) {\n      if (f[i][j] == 'o') ans += e[i][j];\n\
    \    }\n  }\n  WeightedBipartiteMatching<long long> weighted_bipartite_matching(n,\
    \ n);\n  for (int i = 0; i < n; ++i) {\n    for (int j = 0; j < n; ++j) {\n  \
    \    weighted_bipartite_matching.add_edge(i, j,\n                            \
    \               f[i][j] == 'o' ? e[i][j] : -w[i][j]);\n    }\n  }\n  std::cout\
    \ << ans - weighted_bipartite_matching.solve() << '\\n';\n  std::vector<std::string>\
    \ taro(n, std::string(n, '.'));\n  const std::vector<int> matching = weighted_bipartite_matching.matching();\n\
    \  for (int i = 0; i < n; ++i) {\n    taro[i][matching[i]] = 'o';\n  }\n  std::vector<int>\
    \ r, c;\n  std::vector<std::string> operate;\n  for (int i = 0; i < n; ++i) {\n\
    \    for (int j = 0; j < n; ++j) {\n      if (f[i][j] != taro[i][j]) {\n     \
    \   r.emplace_back(i);\n        c.emplace_back(j);\n        operate.emplace_back(f[i][j]\
    \ == 'o' ? \"erase\" : \"write\");\n      }\n    }\n  }\n  const int cnt = r.size();\n\
    \  std::cout << cnt << '\\n';\n  for (int i = 0; i < cnt; ++i) {\n    std::cout\
    \ << r[i] + 1 << ' ' << c[i] + 1 << ' ' << operate[i] << '\\n';\n  }\n  return\
    \ 0;\n}\n"
  dependsOn:
  - graph/flow/matching/weighted_bipartite_matching.hpp
  - graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp
  isVerificationFile: true
  path: test/graph/flow/matching/weighted_bipartite_matching.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
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
