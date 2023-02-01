---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/mobius_mu/mobius_mu_focusing_on_divisor.hpp
    title: "\u30E1\u30D3\u30A6\u30B9\u95A2\u6570 \u7D04\u6570\u7248"
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
    PROBLEM: https://atcoder.jp/contests/abc162/tasks/abc162_e
    document_title: "\u6570\u5B66/\u30E1\u30D3\u30A6\u30B9\u95A2\u6570/\u30E1\u30D3\
      \u30A6\u30B9\u95A2\u6570 \u7D04\u6570\u7248"
    links:
    - https://atcoder.jp/contests/abc162/tasks/abc162_e
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/mobius_mu/mobius_mu_focusing_on_divisor.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6570\u5B66/\u30E1\u30D3\u30A6\u30B9\u95A2\u6570/\u30E1\u30D3\
    \u30A6\u30B9\u95A2\u6570 \u7D04\u6570\u7248\n */\n#define PROBLEM \"https://atcoder.jp/contests/abc162/tasks/abc162_e\"\
    \n\n#include <iostream>\n#include <map>\n#if __cplusplus < 201703L\n# include\
    \ <utility>\n#endif  // __cplusplus < 201703L\n\n#include \"emthrm/math/mobius_mu/mobius_mu_focusing_on_divisor.hpp\"\
    \n#include \"emthrm/math/modint.hpp\"\n\nint main() {\n  using ModInt = emthrm::MInt<1000000007>;\n\
    \  int n, k;\n  std::cin >> n >> k;\n  std::map<int, int> mu;\n  ModInt ans =\
    \ 0;\n  for (int g = 1; g <= k; ++g) {\n    ModInt ways = 0;\n    for (int m =\
    \ k / g; m >= 1; --m) {\n      if (mu.count(m) == 0) {\n#if __cplusplus >= 201703L\n\
    \        for (const auto& [d, mu_d] : emthrm::mobius_mu_focusing_on_divisor(m))\
    \ {\n          mu[d] = mu_d;\n        }\n#else\n        for (const std::pair<const\
    \ int, int>& p\n             : emthrm::mobius_mu_focusing_on_divisor(m)) {\n \
    \         mu[p.first] = p.second;\n        }\n#endif  // __cplusplus >= 201703L\n\
    \      }\n      ways += ModInt(k / (g * m)).pow(n) * mu[m];\n    }\n    ans +=\
    \ ways * g;\n  }\n  std::cout << ans << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/mobius_mu/mobius_mu_focusing_on_divisor.hpp
  - include/emthrm/math/modint.hpp
  isVerificationFile: true
  path: test/math/mobius_mu/mobius_mu_focusing_on_divisor.test.cpp
  requiredBy: []
  timestamp: '2023-01-30 16:05:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/mobius_mu/mobius_mu_focusing_on_divisor.test.cpp
layout: document
redirect_from:
- /verify/test/math/mobius_mu/mobius_mu_focusing_on_divisor.test.cpp
- /verify/test/math/mobius_mu/mobius_mu_focusing_on_divisor.test.cpp.html
title: "\u6570\u5B66/\u30E1\u30D3\u30A6\u30B9\u95A2\u6570/\u30E1\u30D3\u30A6\u30B9\
  \u95A2\u6570 \u7D04\u6570\u7248"
---
