---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/prime_sieve.hpp
    title: prime sieve
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/math/carmichael_function_init.hpp\"\n\n\n\
    \n#include <numeric>\n#include <vector>\n\n#line 1 \"include/emthrm/math/prime_sieve.hpp\"\
    \n\n\n\n#line 6 \"include/emthrm/math/prime_sieve.hpp\"\n\nnamespace emthrm {\n\
    \ntemplate <bool GETS_ONLY_PRIME>\nstd::vector<int> prime_sieve(const int n) {\n\
    \  std::vector<int> smallest_prime_factor(n + 1), prime;\n  std::iota(smallest_prime_factor.begin(),\
    \ smallest_prime_factor.end(), 0);\n  for (int i = 2; i <= n; ++i) {\n    if (smallest_prime_factor[i]\
    \ == i) [[unlikely]] prime.emplace_back(i);\n    for (const int p : prime) {\n\
    \      if (i * p > n || p > smallest_prime_factor[i]) break;\n      smallest_prime_factor[i\
    \ * p] = p;\n    }\n  }\n  return GETS_ONLY_PRIME ? prime : smallest_prime_factor;\n\
    }\n\n}  // namespace emthrm\n\n\n#line 8 \"include/emthrm/math/carmichael_function_init.hpp\"\
    \n\nnamespace emthrm {\n\nstd::vector<long long> carmichael_function_init(const\
    \ long long low,\n                                                const long long\
    \ high) {\n  std::vector<long long> lambda(high - low, 1), tmp(high - low);\n\
    \  std::iota(tmp.begin(), tmp.end(), low);\n  if (low == 0 && high > 0) lambda[0]\
    \ = 0;\n  for (long long i = (low + 7) / 8 * 8; i < high; i += 8) {\n    tmp[i\
    \ - low] >>= 1;\n  }\n  long long root = 1;\n  while ((root + 1) * (root + 1)\
    \ < high) ++root;\n  for (const int p : prime_sieve<true>(root)) {\n    for (long\
    \ long i = (low + p - 1) / p * p; i < high; i += p) {\n      if (i == 0) continue;\n\
    \      tmp[i - low] /= p;\n      long long phi = p - 1;\n      for (; tmp[i -\
    \ low] % p == 0; tmp[i - low] /= p) {\n        phi *= p;\n      }\n      lambda[i\
    \ - low] = std::lcm(lambda[i - low], phi);\n    }\n  }\n  for (int i = 0; i <\
    \ high - low; ++i) {\n    if (tmp[i] > 1) lambda[i] = std::lcm(lambda[i], tmp[i]\
    \ - 1);\n  }\n  return lambda;\n}\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_MATH_CARMICHAEL_FUNCTION_INIT_HPP_\n#define EMTHRM_MATH_CARMICHAEL_FUNCTION_INIT_HPP_\n\
    \n#include <numeric>\n#include <vector>\n\n#include \"emthrm/math/prime_sieve.hpp\"\
    \n\nnamespace emthrm {\n\nstd::vector<long long> carmichael_function_init(const\
    \ long long low,\n                                                const long long\
    \ high) {\n  std::vector<long long> lambda(high - low, 1), tmp(high - low);\n\
    \  std::iota(tmp.begin(), tmp.end(), low);\n  if (low == 0 && high > 0) lambda[0]\
    \ = 0;\n  for (long long i = (low + 7) / 8 * 8; i < high; i += 8) {\n    tmp[i\
    \ - low] >>= 1;\n  }\n  long long root = 1;\n  while ((root + 1) * (root + 1)\
    \ < high) ++root;\n  for (const int p : prime_sieve<true>(root)) {\n    for (long\
    \ long i = (low + p - 1) / p * p; i < high; i += p) {\n      if (i == 0) continue;\n\
    \      tmp[i - low] /= p;\n      long long phi = p - 1;\n      for (; tmp[i -\
    \ low] % p == 0; tmp[i - low] /= p) {\n        phi *= p;\n      }\n      lambda[i\
    \ - low] = std::lcm(lambda[i - low], phi);\n    }\n  }\n  for (int i = 0; i <\
    \ high - low; ++i) {\n    if (tmp[i] > 1) lambda[i] = std::lcm(lambda[i], tmp[i]\
    \ - 1);\n  }\n  return lambda;\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_CARMICHAEL_FUNCTION_INIT_HPP_\n"
  dependsOn:
  - include/emthrm/math/prime_sieve.hpp
  isVerificationFile: false
  path: include/emthrm/math/carmichael_function_init.hpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: include/emthrm/math/carmichael_function_init.hpp
layout: document
title: "\u30AB\u30FC\u30DE\u30A4\u30B1\u30EB\u95A2\u6570 (Carmichael function) \u306E\
  \u6570\u8868"
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
