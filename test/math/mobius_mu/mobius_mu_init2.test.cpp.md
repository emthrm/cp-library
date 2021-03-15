---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/mobius_mu/mobius_mu_init2.hpp
    title: "\u30E1\u30D3\u30A6\u30B9\u95A2\u6570\u306E\u6570\u88682"
  - icon: ':question:'
    path: math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
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
    document_title: "\u6570\u5B66/\u30E1\u30D3\u30A6\u30B9\u95A2\u6570/\u30E1\u30D3\
      \u30A6\u30B9\u95A2\u6570\u306E\u6570\u88682"
    links:
    - https://codeforces.com/problemset/problem/1139/D
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/mobius_mu/mobius_mu_init2.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u30E1\u30D3\u30A6\u30B9\u95A2\u6570/\u30E1\u30D3\
    \u30A6\u30B9\u95A2\u6570\u306E\u6570\u88682\r\n */\r\n#define IGNORE\r\n#define\
    \ PROBLEM \"https://codeforces.com/problemset/problem/1139/D\"\r\n\r\n#include\
    \ <iostream>\r\n#include <vector>\r\n#include \"../../../math/modint.hpp\"\r\n\
    #include \"../../../math/mobius_mu/mobius_mu_init2.hpp\"\r\n\r\nint main() {\r\
    \n  using ModInt = MInt<0>;\r\n  ModInt::set_mod(1000000007);\r\n  int m;\r\n\
    \  std::cin >> m;\r\n  ModInt ans = 1;\r\n  std::vector<int> mu = mobius_mu_init2(2,\
    \ m + 1);\r\n  for (int i = 2; i <= m; ++i) ans -= (ModInt(m) / (m - m / i) -\
    \ 1) * mu[i - 2];\r\n  std::cout << ans << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/modint.hpp
  - math/mobius_mu/mobius_mu_init2.hpp
  - math/prime_sieve.hpp
  isVerificationFile: true
  path: test/math/mobius_mu/mobius_mu_init2.test.cpp
  requiredBy: []
  timestamp: '2021-03-07 02:53:11+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/mobius_mu/mobius_mu_init2.test.cpp
layout: document
redirect_from:
- /verify/test/math/mobius_mu/mobius_mu_init2.test.cpp
- /verify/test/math/mobius_mu/mobius_mu_init2.test.cpp.html
title: "\u6570\u5B66/\u30E1\u30D3\u30A6\u30B9\u95A2\u6570/\u30E1\u30D3\u30A6\u30B9\
  \u95A2\u6570\u306E\u6570\u88682"
---
