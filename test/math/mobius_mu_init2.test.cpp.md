---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/mobius_mu_init2.hpp
    title: "\u30E1\u30D3\u30A6\u30B9\u95A2\u6570\u306E\u6570\u88682"
  - icon: ':question:'
    path: include/emthrm/math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/prime_sieve.hpp
    title: prime sieve
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc162/tasks/abc162_e
    document_title: "\u6570\u5B66/\u30E1\u30D3\u30A6\u30B9\u95A2\u6570/\u30E1\u30D3\
      \u30A6\u30B9\u95A2\u6570\u306E\u6570\u88682"
    links:
    - https://atcoder.jp/contests/abc162/tasks/abc162_e
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/mobius_mu_init2.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6570\u5B66/\u30E1\u30D3\u30A6\u30B9\u95A2\u6570/\u30E1\u30D3\
    \u30A6\u30B9\u95A2\u6570\u306E\u6570\u88682\n */\n#define PROBLEM \"https://atcoder.jp/contests/abc162/tasks/abc162_e\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"emthrm/math/mobius_mu_init2.hpp\"\
    \n#include \"emthrm/math/modint.hpp\"\n\nint main() {\n  using ModInt = emthrm::MInt<1000000007>;\n\
    \  int n, k;\n  std::cin >> n >> k;\n  const std::vector<int> mu = emthrm::mobius_mu_init2(1,\
    \ k + 1);\n  ModInt ans = 0;\n  for (int g = 1; g <= k; ++g) {\n    ModInt ways\
    \ = 0;\n    for (int mul = 1; g * mul <= k; ++mul) {\n      ways += ModInt(k /\
    \ (g * mul)).pow(n) * mu[mul - 1];\n    }\n    ans += ways * g;\n  }\n  std::cout\
    \ << ans << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/mobius_mu_init2.hpp
  - include/emthrm/math/prime_sieve.hpp
  - include/emthrm/math/modint.hpp
  isVerificationFile: true
  path: test/math/mobius_mu_init2.test.cpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/mobius_mu_init2.test.cpp
layout: document
redirect_from:
- /verify/test/math/mobius_mu_init2.test.cpp
- /verify/test/math/mobius_mu_init2.test.cpp.html
title: "\u6570\u5B66/\u30E1\u30D3\u30A6\u30B9\u95A2\u6570/\u30E1\u30D3\u30A6\u30B9\
  \u95A2\u6570\u306E\u6570\u88682"
---
