---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/mobius_mu/mobius_mu_init2.hpp
    title: "\u30E1\u30D3\u30A6\u30B9\u95A2\u6570\u306E\u6570\u88682"
  - icon: ':question:'
    path: math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  - icon: ':x:'
    path: math/prime_sieve.hpp
    title: prime sieve
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc162/tasks/abc162_e
    document_title: "\u6570\u5B66/\u30E1\u30D3\u30A6\u30B9\u95A2\u6570/\u30E1\u30D3\
      \u30A6\u30B9\u95A2\u6570\u306E\u6570\u88682"
    links:
    - https://atcoder.jp/contests/abc162/tasks/abc162_e
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/mobius_mu/mobius_mu_init2.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/*\n * @brief \u6570\u5B66/\u30E1\u30D3\u30A6\u30B9\u95A2\u6570/\u30E1\u30D3\
    \u30A6\u30B9\u95A2\u6570\u306E\u6570\u88682\n */\n#define PROBLEM \"https://atcoder.jp/contests/abc162/tasks/abc162_e\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../../math/mobius_mu/mobius_mu_init2.hpp\"\
    \n#include \"../../../math/modint.hpp\"\n\nint main() {\n  using ModInt = MInt<0>;\n\
    \  ModInt::set_mod(1000000007);\n  int n, k;\n  std::cin >> n >> k;\n  const std::vector<int>\
    \ mu = mobius_mu_init2(1, k + 1);\n  ModInt ans = 0;\n  for (int g = 1; g <= k;\
    \ ++g) {\n    ModInt ways = 0;\n    for (int mul = 1; g * mul <= k; ++mul) {\n\
    \      ways += ModInt(k / (g * mul)).pow(n) * mu[mul - 1];\n    }\n    ans +=\
    \ ways * g;\n  }\n  std::cout << ans << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - math/mobius_mu/mobius_mu_init2.hpp
  - math/prime_sieve.hpp
  - math/modint.hpp
  isVerificationFile: true
  path: test/math/mobius_mu/mobius_mu_init2.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
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
