---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  - icon: ':x:'
    path: math/twelvefold_way/binomial_coefficients/binom_large_n_init.hpp
    title: "\u4E8C\u9805\u4FC2\u6570 $n$ \u306F\u5DE8\u5927\u306A\u56FA\u5B9A\u5024"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3071
    document_title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u4E8C\u9805\u4FC2\u6570/\u4E8C\
      \u9805\u4FC2\u6570 $n$ \u306F\u5DE8\u5927\u306A\u56FA\u5B9A\u5024"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3071
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/twelvefold_way/binomial_coefficients/binom_large_n_init.hpp: line 6: #pragma\
    \ once found in a non-first line\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u5199\u50CF12\u76F8/\u4E8C\u9805\u4FC2\u6570\
    /\u4E8C\u9805\u4FC2\u6570 $n$ \u306F\u5DE8\u5927\u306A\u56FA\u5B9A\u5024\r\n */\r\
    \n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3071\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include \"../../../../math/modint.hpp\"\
    \r\n#include \"../../../../math/twelvefold_way/binomial_coefficients/binom_large_n_init.hpp\"\
    \r\n\r\nint main() {\r\n  ModInt::set_mod(998244353);\r\n  long long m, n;\r\n\
    \  int k;\r\n  std::cin >> m >> n >> k;\r\n  Combinatorics com(k);\r\n  ModInt\
    \ ans = ModInt(m).pow(n);\r\n  if (k > 1) {\r\n    std::vector<ModInt> c = binom_large_n_init(m,\
    \ k - 1, com);\r\n    for (int i = 1; i < k; ++i) {\r\n      ModInt tmp = 0;\r\
    \n      for (int j = i; j >= 1; --j) tmp += com.nCk(i, j) * ModInt(j).pow(n) *\
    \ ((i - j) & 1 ? -1 : 1);\r\n      ans -= tmp * c[i];\r\n    }\r\n  }\r\n  std::cout\
    \ << ans << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/modint.hpp
  - math/twelvefold_way/binomial_coefficients/binom_large_n_init.hpp
  isVerificationFile: true
  path: test/math/twelvefold_way/binomial_coefficients/binom_large_n_init.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/twelvefold_way/binomial_coefficients/binom_large_n_init.test.cpp
layout: document
redirect_from:
- /verify/test/math/twelvefold_way/binomial_coefficients/binom_large_n_init.test.cpp
- /verify/test/math/twelvefold_way/binomial_coefficients/binom_large_n_init.test.cpp.html
title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u4E8C\u9805\u4FC2\u6570/\u4E8C\u9805\u4FC2\
  \u6570 $n$ \u306F\u5DE8\u5927\u306A\u56FA\u5B9A\u5024"
---
