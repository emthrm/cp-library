---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/mod_pow.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5 / \u4E8C\u5206\u7D2F\u4E57\u6CD5\
      \ / \u30D0\u30A4\u30CA\u30EA\u6CD5"
  - icon: ':question:'
    path: include/emthrm/math/prime_sieve.hpp
    title: prime sieve
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/enumerate_k-th_power.test.cpp
    title: "\u6570\u5B66/$i^k \\bmod m$ ($0 \\leq i \\leq n$)"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/mod_pow.hpp:\
    \ line -1: no such header\n"
  code: "#ifndef EMTHRM_MATH_ENUMERATE_K_TH_POWER_HPP_\n#define EMTHRM_MATH_ENUMERATE_K_TH_POWER_HPP_\n\
    \n#include <vector>\n\n#include \"emthrm/math/mod_pow.hpp\"\n#include \"emthrm/math/prime_sieve.hpp\"\
    \n\nnamespace emthrm {\n\nstd::vector<int> enumerate_kth_power(const int n, const\
    \ int k, const int m) {\n  const std::vector<int> smallest_prime_factor = prime_sieve<false>(n);\n\
    \  std::vector<int> res(n + 1, 0);\n  for (int i = 1; i <= n; ++i) {\n    if (smallest_prime_factor[i]\
    \ == i) [[unlikely]] {\n      res[i] = mod_pow(i, k, m);\n    } else {\n     \
    \ res[i] = static_cast<long long>(res[smallest_prime_factor[i]])\n           \
    \    * res[i / smallest_prime_factor[i]] % m;\n    }\n  }\n  return res;\n}\n\n\
    }  // namespace emthrm\n\n#endif  // EMTHRM_MATH_ENUMERATE_K_TH_POWER_HPP_\n"
  dependsOn:
  - include/emthrm/math/mod_pow.hpp
  - include/emthrm/math/prime_sieve.hpp
  isVerificationFile: false
  path: include/emthrm/math/enumerate_k-th_power.hpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/enumerate_k-th_power.test.cpp
documentation_of: include/emthrm/math/enumerate_k-th_power.hpp
layout: document
title: $i^k \bmod m$ ($0 \leq i \leq n$)
---


## 時間計算量

$O(N)$


## 仕様

|名前|戻り値|
|:--|:--|
|`std::vector<int> enumerate_kth_power(const int n, const int k, const int m);`|$i^k \bmod m$ ($0 \leq i \leq n$)|


## 参考文献

- https://37zigen.com/linear-sieve/


## Submissons

https://yukicoder.me/submissions/623345
