---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/flow/matching/maximum_matching.hpp
    title: "\u4E00\u822C\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\
      \u30B0"
  - icon: ':heavy_check_mark:'
    path: math/matrix/gauss_jordan.hpp
    title: "\u30AC\u30A6\u30B9\u30FB\u30B8\u30E7\u30EB\u30C0\u30F3\u306E\u6D88\u53BB\
      \u6CD5 (Gauss-Jordan elimination)"
  - icon: ':question:'
    path: math/matrix/matrix.hpp
    title: "\u884C\u5217 (matrix)"
  - icon: ':question:'
    path: math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  - icon: ':heavy_check_mark:'
    path: util/xorshift.hpp
    title: xorshift
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3032
    document_title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\
      \u30B0/\u4E00\u822C\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\
      \u30B0"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3032
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/flow/matching/maximum_matching.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\
    \u30B0/\u4E00\u822C\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\
    \u30B0\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3032\"\
    \r\n\r\n#include <cmath>\r\n#include <iostream>\r\n#include <vector>\r\n\r\n#include\
    \ \"../../../../graph/flow/matching/maximum_matching.hpp\"\r\n\r\nint main() {\r\
    \n  int n, a, b;\r\n  std::cin >> n >> a >> b;\r\n  int ans = 0;\r\n  std::vector<int>\
    \ as, bs;\r\n  while (n--) {\r\n    int a_i, b_i;\r\n    std::cin >> a_i >> b_i;\r\
    \n    const int x = std::abs(a_i - b_i);\r\n    if (x <= a || (b <= x && x <=\
    \ 2 * a)) {\r\n      ++ans;\r\n    } else {\r\n      as.emplace_back(a_i);\r\n\
    \      bs.emplace_back(b_i);\r\n    }\r\n  }\r\n  n = as.size();\r\n  if (n >\
    \ 0) {\r\n    std::vector<std::vector<int>> graph(n);\r\n    for (int i = 0; i\
    \ < n; ++i) {\r\n      for (int j = i + 1; j < n; ++j) {\r\n        const int\
    \ x = std::abs((as[i] + as[j]) - (bs[i] + bs[j]));\r\n        if (x <= a || (b\
    \ <= x && x <= 2 * a)) {\r\n          graph[i].emplace_back(j);\r\n          graph[j].emplace_back(i);\r\
    \n        }\r\n      }\r\n    }\r\n    ans += maximum_matching(graph);\r\n  }\r\
    \n  std::cout << ans << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - graph/flow/matching/maximum_matching.hpp
  - math/modint.hpp
  - math/matrix/gauss_jordan.hpp
  - math/matrix/matrix.hpp
  - util/xorshift.hpp
  isVerificationFile: true
  path: test/graph/flow/matching/maximum_matching.test.cpp
  requiredBy: []
  timestamp: '2022-02-19 03:53:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/flow/matching/maximum_matching.test.cpp
layout: document
redirect_from:
- /verify/test/graph/flow/matching/maximum_matching.test.cpp
- /verify/test/graph/flow/matching/maximum_matching.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\u30B0/\u4E00\
  \u822C\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0"
---
