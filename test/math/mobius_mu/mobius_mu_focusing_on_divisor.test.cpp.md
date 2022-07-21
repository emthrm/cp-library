---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/mobius_mu/mobius_mu_focusing_on_divisor.hpp
    title: "\u30E1\u30D3\u30A6\u30B9\u95A2\u6570 \u7D04\u6570\u7248"
  - icon: ':question:'
    path: math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc162/tasks/abc162_e
    document_title: "\u6570\u5B66/\u30E1\u30D3\u30A6\u30B9\u95A2\u6570/\u30E1\u30D3\
      \u30A6\u30B9\u95A2\u6570 \u7D04\u6570\u7248"
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
    \ math/mobius_mu/mobius_mu_focusing_on_divisor.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/*\n * @brief \u6570\u5B66/\u30E1\u30D3\u30A6\u30B9\u95A2\u6570/\u30E1\u30D3\
    \u30A6\u30B9\u95A2\u6570 \u7D04\u6570\u7248\n */\n#define PROBLEM \"https://atcoder.jp/contests/abc162/tasks/abc162_e\"\
    \n\n#include <iostream>\n#include <map>\n#include <utility>\n\n#include \"../../../math/mobius_mu/mobius_mu_focusing_on_divisor.hpp\"\
    \n#include \"../../../math/modint.hpp\"\n\nint main() {\n  using ModInt = MInt<0>;\n\
    \  ModInt::set_mod(1000000007);\n  int n, k;\n  std::cin >> n >> k;\n  std::map<int,\
    \ int> mu;\n  ModInt ans = 0;\n  for (int g = 1; g <= k; ++g) {\n    ModInt ways\
    \ = 0;\n    for (int m = k / g; m >= 1; --m) {\n      if (mu.count(m) == 0) {\n\
    \        for (const std::pair<int, int>& p : mobius_mu_focusing_on_divisor(m))\
    \ {\n          mu[p.first] = p.second;\n        }\n      }\n      ways += ModInt(k\
    \ / (g * m)).pow(n) * mu[m];\n    }\n    ans += ways * g;\n  }\n  std::cout <<\
    \ ans << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - math/mobius_mu/mobius_mu_focusing_on_divisor.hpp
  - math/modint.hpp
  isVerificationFile: true
  path: test/math/mobius_mu/mobius_mu_focusing_on_divisor.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/mobius_mu/mobius_mu_focusing_on_divisor.test.cpp
layout: document
redirect_from:
- /verify/test/math/mobius_mu/mobius_mu_focusing_on_divisor.test.cpp
- /verify/test/math/mobius_mu/mobius_mu_focusing_on_divisor.test.cpp.html
title: "\u6570\u5B66/\u30E1\u30D3\u30A6\u30B9\u95A2\u6570/\u30E1\u30D3\u30A6\u30B9\
  \u95A2\u6570 \u7D04\u6570\u7248"
---
