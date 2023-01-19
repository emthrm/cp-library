---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/least_common_multiple.hpp
    title: "\u6700\u5C0F\u516C\u500D\u6570 (least common multiple)"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/prime_sieve.hpp
    title: prime sieve
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/math/carmichael_function.md
    document_title: "\u30AB\u30FC\u30DE\u30A4\u30B1\u30EB\u95A2\u6570\u306E\u6570\u8868"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ include/emthrm/math/carmichael_function_init.hpp: line 13: unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\n"
  code: "/**\n * @brief \u30AB\u30FC\u30DE\u30A4\u30B1\u30EB\u95A2\u6570\u306E\u6570\
    \u8868\n * @docs docs/math/carmichael_function.md\n */\n\n#ifndef EMTHRM_MATH_CARMICHAEL_FUNCTION_INIT_HPP_\n\
    #define EMTHRM_MATH_CARMICHAEL_FUNCTION_INIT_HPP_\n\n#include <numeric>\n#include\
    \ <vector>\n\n#if __cplusplus < 201703L\n#include \"emthrm/math/least_common_multiple.hpp\"\
    \n#endif\n#include \"emthrm/math/prime_sieve.hpp\"\n\nnamespace emthrm {\n\nstd::vector<long\
    \ long> carmichael_function_init(const long long low,\n                      \
    \                          const long long high) {\n  std::vector<long long> lambda(high\
    \ - low, 1), tmp(high - low);\n  std::iota(tmp.begin(), tmp.end(), low);\n  if\
    \ (low == 0 && high > 0) lambda[0] = 0;\n  for (long long i = (low + 7) / 8 *\
    \ 8; i < high; i += 8) {\n    tmp[i - low] >>= 1;\n  }\n  long long root = 1;\n\
    \  while ((root + 1) * (root + 1) < high) ++root;\n  for (const int p : prime_sieve(root,\
    \ true)) {\n    for (long long i = (low + p - 1) / p * p; i < high; i += p) {\n\
    \      if (i == 0) continue;\n      tmp[i - low] /= p;\n      long long phi =\
    \ p - 1;\n      for (; tmp[i - low] % p == 0; tmp[i - low] /= p) {\n        phi\
    \ *= p;\n      }\n#if __cplusplus >= 201703L\n      lambda[i - low] = std::lcm(lambda[i\
    \ - low], phi);\n#else\n      lambda[i - low] = __lcm(lambda[i - low], phi);\n\
    #endif\n    }\n  }\n  for (int i = 0; i < high - low; ++i) {\n#if __cplusplus\
    \ >= 201703L\n    if (tmp[i] > 1) lambda[i] = std::lcm(lambda[i], tmp[i] - 1);\n\
    #else\n    if (tmp[i] > 1) lambda[i] = __lcm(lambda[i], tmp[i] - 1);\n#endif\n\
    \  }\n  return lambda;\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_CARMICHAEL_FUNCTION_INIT_HPP_\n"
  dependsOn:
  - include/emthrm/math/least_common_multiple.hpp
  - include/emthrm/math/prime_sieve.hpp
  isVerificationFile: false
  path: include/emthrm/math/carmichael_function_init.hpp
  requiredBy: []
  timestamp: '2023-01-20 03:45:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: include/emthrm/math/carmichael_function_init.hpp
layout: document
redirect_from:
- /library/include/emthrm/math/carmichael_function_init.hpp
- /library/include/emthrm/math/carmichael_function_init.hpp.html
title: "\u30AB\u30FC\u30DE\u30A4\u30B1\u30EB\u95A2\u6570\u306E\u6570\u8868"
---
# カーマイケル関数 (Carmichael function)

$n \in \mathbb{N}^+$ に対して

$$
  \forall a \in \mathbb{N}^+,\ a \perp n \implies a^x \equiv 1 \pmod{n}
$$

を満たす最小の $x \in \mathbb{N}^+$ を $\lambda(n)$ と定義する。

素因数分解 $n = \prod_{i = 1}^k p_i^{e_i}$ に対して

$$
  \lambda(n) =
  \begin{cases}
    1 & (n = 1, 2), \\
    2 & (n = 4), \\
    2^{e - 2} & (\exists e \geq 3,\ n = 2^e), \\
    (p - 1)p^{e - 1} & (\exists p \text{ : 奇素数},\ \exists e \in \mathbb{N}^+,\ n = p^e), \\
    \mathrm{lcm} (\lambda(p_1^{e_1}),\ldots, \lambda(p_k^{e_k})) & (\text{otherwise})
  \end{cases}
$$

が成り立つ。


## 仕様

|名前|戻り値|
|:--|:--|
|`long long carmichael_function(long long n);`|カーマイケル関数 $\lambda(n)$|


### 数表

|名前|戻り値|
|:--|:--|
|`std::vector<long long> carmichael_function_init(const long long low, const long long high);`|カーマイケル関数 $\lambda(n)$ ($\mathrm{low} \leq n \leq \mathrm{high}$) の数表|


## 参考文献

- http://integers.hatenablog.com/entry/2017/06/08/191649
- https://en.wikipedia.org/wiki/Carmichael_function
- https://github.com/spaghetti-source/algorithm/blob/8af3698b8a7583035857280ab324c8ae75c70374/number_theory/carmichael_lambda.cc


## TODO

- https://onlinejudge.u-aizu.ac.jp/problems/2720
