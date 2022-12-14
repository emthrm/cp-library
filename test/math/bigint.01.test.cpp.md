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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/flow/matching/weighted_bipartite_matching.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/*\n * @brief \u6570\u5B66/\u591A\u500D\u9577\u6574\u6570\n */\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2679\"\n\n#include\
    \ <algorithm>\n#include <iostream>\n#include <map>\n#include <string>\n#include\
    \ <vector>\n\n#include \"../../graph/flow/matching/weighted_bipartite_matching.hpp\"\
    \n#include \"../../math/bigint.hpp\"\n\nnamespace std {\n\ntemplate <int LogB,\
    \ int B>\nstruct numeric_limits<BigInt<LogB, B>> {\n  static constexpr BigInt<LogB,\
    \ B> max() {\n    return static_cast<std::string>(\n        \"453152254949043485887196599220742984693877551020408163265306122448979591836734693877551\"\
    );\n  }\n};\n\n};  // namespace std\n\nint main() {\n  using bigint = BigInt<>;\n\
    \  constexpr int SIGMA = 26;\n  int n;\n  std::cin >> n;\n  std::map<char, bigint>\
    \ cost;\n  bigint cur = 0;\n  for (int i = SIGMA - 1; i >= 0; --i) {\n    cost['a'\
    \ + i] = cur;\n    cur = cur * SIGMA * 2 + 1;\n  }\n  for (int i = SIGMA - 1;\
    \ i >= 0; --i) {\n    cost['A' + i] = cur;\n    cur = cur * SIGMA * 2 + 1;\n \
    \ }\n  std::vector<std::string> c(n);\n  for (int i = 0; i < n; ++i) {\n    std::cin\
    \ >> c[i];\n  }\n  WeightedBipartiteMatching<bigint> weighted_bipartite_matching(n,\
    \ n);\n  for (int i = 0; i < n; ++i) {\n    std::cin >> c[i];\n    for (int j\
    \ = 0; j < n; ++j) {\n      weighted_bipartite_matching.add_edge(i, j, cost[c[i][j]]);\n\
    \    }\n  }\n  weighted_bipartite_matching.solve();\n  std::string ans = \"\"\
    ;\n  const std::vector<int> matching = weighted_bipartite_matching.matching();\n\
    \  for (int i = 0; i < n; ++i) {\n    ans += c[i][matching[i]];\n  }\n  std::sort(ans.begin(),\
    \ ans.end());\n  std::cout << ans << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - graph/flow/matching/weighted_bipartite_matching.hpp
  - graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp
  - math/bigint.hpp
  isVerificationFile: true
  path: test/math/bigint.01.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/bigint.01.test.cpp
layout: document
redirect_from:
- /verify/test/math/bigint.01.test.cpp
- /verify/test/math/bigint.01.test.cpp.html
title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570"
---
