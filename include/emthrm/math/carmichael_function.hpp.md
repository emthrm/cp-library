---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/math/carmichael_function.hpp\"\n\n\n\n#include\
    \ <numeric>\n\nnamespace emthrm {\n\nlong long carmichael_function(long long n)\
    \ {\n  long long lambda = 1;\n  if (n % 8 == 0) n >>= 1;\n  for (long long i =\
    \ 2; i * i <= n; ++i) {\n    if (n % i == 0) [[unlikely]] {\n      n /= i;\n \
    \     long long phi = i - 1;\n      for (; n % i == 0; n /= i) {\n        phi\
    \ *= i;\n      }\n      lambda = std::lcm(lambda, phi);\n    }\n  }\n  return\
    \ n > 1 ? std::lcm(lambda, n - 1) : lambda;\n}\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_MATH_CARMICHAEL_FUNCTION_HPP_\n#define EMTHRM_MATH_CARMICHAEL_FUNCTION_HPP_\n\
    \n#include <numeric>\n\nnamespace emthrm {\n\nlong long carmichael_function(long\
    \ long n) {\n  long long lambda = 1;\n  if (n % 8 == 0) n >>= 1;\n  for (long\
    \ long i = 2; i * i <= n; ++i) {\n    if (n % i == 0) [[unlikely]] {\n      n\
    \ /= i;\n      long long phi = i - 1;\n      for (; n % i == 0; n /= i) {\n  \
    \      phi *= i;\n      }\n      lambda = std::lcm(lambda, phi);\n    }\n  }\n\
    \  return n > 1 ? std::lcm(lambda, n - 1) : lambda;\n}\n\n}  // namespace emthrm\n\
    \n#endif  // EMTHRM_MATH_CARMICHAEL_FUNCTION_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/math/carmichael_function.hpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: include/emthrm/math/carmichael_function.hpp
layout: document
title: "\u30AB\u30FC\u30DE\u30A4\u30B1\u30EB\u95A2\u6570 (Carmichael function)"
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

- Robert D. Carmichael: Note on a new number theory function, *Bulletin of the American Mathematical Society*, Vol. 16, pp. 232–238 (1910). https://doi.org/10.1090/S0002-9904-1910-01892-9
- http://integers.hatenablog.com/entry/2017/06/08/191649
- https://en.wikipedia.org/wiki/Carmichael_function
- https://github.com/spaghetti-source/algorithm/blob/8af3698b8a7583035857280ab324c8ae75c70374/number_theory/carmichael_lambda.cc


## TODO

- https://onlinejudge.u-aizu.ac.jp/problems/2720