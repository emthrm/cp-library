---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/inverse_element/mod_inv_fermat.hpp
    title: "\u9006\u5143 Fermat \u306E\u5C0F\u5B9A\u7406\u7248"
  - icon: ':x:'
    path: math/linear_congruence.hpp
    title: "\u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F (linear congruence)"
  - icon: ':question:'
    path: math/mod_pow.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5 (\u4E8C\u5206\u7D2F\u4E57\u6CD5\
      , \u30D0\u30A4\u30CA\u30EA\u6CD5)"
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
    document_title: "\u6570\u5B66/\u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F"
    links:
    - https://atcoder.jp/contests/ddcc2019-qual/tasks/ddcc2018_qual_d
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/inverse_element/mod_inv_fermat.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F\r\
    \n */\r\n#define IGNORE\r\n#define PROBLEM \"https://atcoder.jp/contests/ddcc2019-qual/tasks/ddcc2018_qual_d\"\
    \r\n\r\n#include <iostream>\r\n#include <tuple>\r\n#include <vector>\r\n#include\
    \ \"../../math/linear_congruence.hpp\"\r\n\r\nint main() {\r\n  constexpr int\
    \ N = 29;\r\n  std::vector<long long> a(N), m(N);\r\n  for (int i = 0; i < N;\
    \ ++i) {\r\n    std::cin >> a[i];\r\n    m[i] = i + 1;\r\n  }\r\n  long long ans,\
    \ mod; std::tie(ans, mod) = linear_congruence(std::vector<long long>(N, 1), a,\
    \ m);\r\n  if (mod == -1 || ans > 1000000000000) {\r\n    std::cout << \"invalid\\\
    n\";\r\n    return 0;\r\n  }\r\n  for (int i = 0; i < N; ++i) {\r\n    int cnt\
    \ = 0;\r\n    long long tmp = ans;\r\n    while (tmp > 0) {\r\n      cnt += tmp\
    \ % (i + 2);\r\n      tmp /= i + 2;\r\n    }\r\n    if (cnt != a[i]) {\r\n   \
    \   std::cout << \"invalid\\n\";\r\n      return 0;\r\n    }\r\n  }\r\n  std::cout\
    \ << ans << \"\\n\";\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/linear_congruence.hpp
  - math/inverse_element/mod_inv_fermat.hpp
  - math/mod_pow.hpp
  isVerificationFile: true
  path: test/math/linear_congruence.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/linear_congruence.test.cpp
layout: document
redirect_from:
- /verify/test/math/linear_congruence.test.cpp
- /verify/test/math/linear_congruence.test.cpp.html
title: "\u6570\u5B66/\u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F"
---
