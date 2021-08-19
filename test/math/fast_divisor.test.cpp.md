---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/prime_sieve.hpp
    title: prime sieve
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
    document_title: "\u6570\u5B66/\u7D04\u6570\u5217\u6319"
    links:
    - https://codeforces.com/contest/1512/problem/G
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/fast_divisor.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u7D04\u6570\u5217\u6319\r\n */\r\n#define IGNORE\r\
    \n#define PROBLEM \"https://codeforces.com/contest/1512/problem/G\"\r\n\r\n#include\
    \ <iostream>\r\n#include <vector>\r\n#include \"../../math/fast_divisor.hpp\"\r\
    \n\r\nint main() {\r\n  constexpr int N = 10000000;\r\n  Divisor divisor(N);\r\
    \n  std::vector<int> ans(N + 1, -1);\r\n  for (int i = N; i >= 1; --i) {\r\n \
    \   int d = 0;\r\n    for (int di : divisor.query(i)) d += di;\r\n    if (d <=\
    \ N) ans[d] = i;\r\n  }\r\n  int t;\r\n  std::cin >> t;\r\n  while (t--) {\r\n\
    \    int c;\r\n    std::cin >> c;\r\n    std::cout << ans[c] << '\\n';\r\n  }\r\
    \n  return 0;\r\n}\r\n"
  dependsOn:
  - math/prime_sieve.hpp
  isVerificationFile: true
  path: test/math/fast_divisor.test.cpp
  requiredBy: []
  timestamp: '2021-04-12 18:12:34+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/fast_divisor.test.cpp
layout: document
redirect_from:
- /verify/test/math/fast_divisor.test.cpp
- /verify/test/math/fast_divisor.test.cpp.html
title: "\u6570\u5B66/\u7D04\u6570\u5217\u6319"
---
