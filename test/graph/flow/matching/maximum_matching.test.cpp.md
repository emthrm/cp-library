---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/flow/matching/maximum_matching.hpp
    title: "\u4E00\u822C\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\
      \u30B0"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/matrix/gauss_jordan.hpp
    title: "\u30AC\u30A6\u30B9\u30FB\u30B8\u30E7\u30EB\u30C0\u30F3\u306E\u6D88\u53BB\
      \u6CD5 (Gauss\u2013Jordan elimination)"
  - icon: ':question:'
    path: include/emthrm/math/matrix/matrix.hpp
    title: "\u884C\u5217 (matrix)"
  - icon: ':question:'
    path: include/emthrm/math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/graph/flow/matching/maximum_matching.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\
    \u30B0/\u4E00\u822C\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\
    \u30B0\n */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3032\"\
    \n\n#include <cmath>\n#include <iostream>\n#include <vector>\n\n#include \"emthrm/graph/flow/matching/maximum_matching.hpp\"\
    \n\nint main() {\n  int n, a, b;\n  std::cin >> n >> a >> b;\n  int ans = 0;\n\
    \  std::vector<int> as, bs;\n  while (n--) {\n    int a_i, b_i;\n    std::cin\
    \ >> a_i >> b_i;\n    const int x = std::abs(a_i - b_i);\n    if (x <= a || (b\
    \ <= x && x <= 2 * a)) {\n      ++ans;\n    } else {\n      as.emplace_back(a_i);\n\
    \      bs.emplace_back(b_i);\n    }\n  }\n  n = as.size();\n  if (n > 0) {\n \
    \   std::vector<std::vector<int>> graph(n);\n    for (int i = 0; i < n; ++i) {\n\
    \      for (int j = i + 1; j < n; ++j) {\n        const int x = std::abs((as[i]\
    \ + as[j]) - (bs[i] + bs[j]));\n        if (x <= a || (b <= x && x <= 2 * a))\
    \ {\n          graph[i].emplace_back(j);\n          graph[j].emplace_back(i);\n\
    \        }\n      }\n    }\n    ans += emthrm::maximum_matching(graph);\n  }\n\
    \  std::cout << ans << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/flow/matching/maximum_matching.hpp
  - include/emthrm/math/matrix/gauss_jordan.hpp
  - include/emthrm/math/matrix/matrix.hpp
  - include/emthrm/math/modint.hpp
  isVerificationFile: true
  path: test/graph/flow/matching/maximum_matching.test.cpp
  requiredBy: []
  timestamp: '2023-01-30 16:05:09+09:00'
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
