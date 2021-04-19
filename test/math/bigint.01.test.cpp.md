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
  - icon: ':question:'
    path: math/bigint.hpp
    title: "\u591A\u500D\u9577\u6574\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2679
    document_title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2679
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/flow/matching/weighted_bipartite_matching.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u591A\u500D\u9577\u6574\u6570\r\n */\r\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2679\"\r\n\
    \r\n#include <algorithm>\r\n#include <iostream>\r\n#include <map>\r\n#include\
    \ <string>\r\n#include <vector>\r\n#include \"../../math/bigint.hpp\"\r\n#include\
    \ \"../../graph/flow/matching/weighted_bipartite_matching.hpp\"\r\n\r\nnamespace\
    \ std {\r\n  template <int Log10Base, int Base>\r\n  struct numeric_limits<BigInt<Log10Base,\
    \ Base>> {\r\n    static constexpr BigInt<Log10Base, Base> max() {\r\n      return\
    \ string(\"453152254949043485887196599220742984693877551020408163265306122448979591836734693877551\"\
    );\r\n    }\r\n  };\r\n};  // std\r\n\r\nint main() {\r\n  using bigint = BigInt<>;\r\
    \n  int n;\r\n  std::cin >> n;\r\n  std::map<char, bigint> cost;\r\n  bigint now\
    \ = 0;\r\n  for (int i = 25; i >= 0; --i) {\r\n    cost['a' + i] = now;\r\n  \
    \  now = now * 50 + 1;\r\n  }\r\n  for (int i = 25; i >= 0; --i) {\r\n    cost['A'\
    \ + i] = now;\r\n    now = now * 50 + 1;\r\n  }\r\n  std::vector<std::string>\
    \ c(n);\r\n  for (int i = 0; i < n; ++i) std::cin >> c[i];\r\n  WeightedBipartiteMatching<bigint>\
    \ wbm(n, n);\r\n  for (int i = 0; i < n; ++i) {\r\n    std::cin >> c[i];\r\n \
    \   for (int j = 0; j < n; ++j) wbm.add_edge(i, j, cost[c[i][j]]);\r\n  }\r\n\
    \  wbm.solve();\r\n  std::string ans = \"\";\r\n  std::vector<int> matching =\
    \ wbm.matching();\r\n  for (int i = 0; i < n; ++i) ans += c[i][matching[i]];\r\
    \n  std::sort(ans.begin(), ans.end());\r\n  std::cout << ans << '\\n';\r\n  return\
    \ 0;\r\n}\r\n"
  dependsOn:
  - math/bigint.hpp
  - graph/flow/matching/weighted_bipartite_matching.hpp
  - graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp
  isVerificationFile: true
  path: test/math/bigint.01.test.cpp
  requiredBy: []
  timestamp: '2021-04-20 01:59:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/bigint.01.test.cpp
layout: document
redirect_from:
- /verify/test/math/bigint.01.test.cpp
- /verify/test/math/bigint.01.test.cpp.html
title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570"
---
