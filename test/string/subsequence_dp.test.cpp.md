---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/string/subsequence_dp.hpp
    title: "\u90E8\u5206\u5217 DP"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/arc081/tasks/arc081_e
    document_title: "\u6587\u5B57\u5217/\u90E8\u5206\u5217 DP"
    links:
    - https://atcoder.jp/contests/arc081/tasks/arc081_c
    - https://atcoder.jp/contests/arc081/tasks/arc081_e
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/string/subsequence_dp.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6587\u5B57\u5217/\u90E8\u5206\u5217 DP\n */\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/arc081/tasks/arc081_e\"\n// #define PROBLEM \"\
    https://atcoder.jp/contests/arc081/tasks/arc081_c\"\n\n#include <iostream>\n#include\
    \ <string>\n#include <vector>\n\n#include \"emthrm/string/subsequence_dp.hpp\"\
    \n\nint main() {\n  constexpr int SIGMA = 26;\n  std::string a;\n  std::cin >>\
    \ a;\n  const int n = a.length();\n  const std::vector<std::vector<int>> nxt =\n\
    \      emthrm::subsequence_dp(a, 'a', SIGMA);\n  std::vector<int> dp(n + 1, n\
    \ + 1), next_char(n, -1);\n  dp[n] = 1;\n  for (int i = n - 1; i >= 0; --i) {\n\
    \    for (int c = 0; c < SIGMA; ++c) {\n      const int len = (nxt[i][c] == n\
    \ ? 0 : dp[nxt[i][c] + 1]) + 1;\n      if (len < dp[i]) {\n        dp[i] = len;\n\
    \        next_char[i] = c;\n      }\n    }\n  }\n  std::string ans = \"\";\n \
    \ for (int i = 0; i < n;) {\n    ans += 'a' + next_char[i];\n    i = nxt[i][next_char[i]]\
    \ + 1;\n  }\n  std::cout << ans << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/string/subsequence_dp.hpp
  isVerificationFile: true
  path: test/string/subsequence_dp.test.cpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/subsequence_dp.test.cpp
layout: document
redirect_from:
- /verify/test/string/subsequence_dp.test.cpp
- /verify/test/string/subsequence_dp.test.cpp.html
title: "\u6587\u5B57\u5217/\u90E8\u5206\u5217 DP"
---
