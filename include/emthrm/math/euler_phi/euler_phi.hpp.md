---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/is_primitive_root.hpp
    title: "\u539F\u59CB\u6839\u5224\u5B9A"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/euler_phi/euler_phi.test.cpp
    title: "\u6570\u5B66/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570/\u30AA\
      \u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570"
  - icon: ':heavy_check_mark:'
    path: test/math/euler_phi/euler_phi_init.test.cpp
    title: "\u6570\u5B66/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570/\u30AA\
      \u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\u306E\u6570\u8868"
  - icon: ':heavy_check_mark:'
    path: test/math/euler_phi/euler_phi_init2.test.cpp
    title: "\u6570\u5B66/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570/\u30AA\
      \u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\u306E\u6570\u88682"
  - icon: ':heavy_check_mark:'
    path: test/math/is_primitive_root.test.cpp
    title: "\u6570\u5B66/\u539F\u59CB\u6839\u5224\u5B9A"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/euler_phi/euler_phi.md
    document_title: "\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570"
    links: []
  bundledCode: "#line 1 \"include/emthrm/math/euler_phi/euler_phi.hpp\"\n/**\n * @brief\
    \ \u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\n * @docs docs/math/euler_phi/euler_phi.md\n\
    \ */\n\n#ifndef EMTHRM_MATH_EULER_PHI_EULER_PHI_HPP_\n#define EMTHRM_MATH_EULER_PHI_EULER_PHI_HPP_\n\
    \n#include <cassert>\n\nnamespace emthrm {\n\nlong long euler_phi(long long n)\
    \ {\n  assert(n >= 1);\n  long long res = n;\n  for (long long i = 2; i * i <=\
    \ n; ++i) {\n    if (n % i == 0) {\n      res -= res / i;\n      while (n % i\
    \ == 0) n /= i;\n    }\n  }\n  return n > 1 ? res - res / n : res;\n}\n\n}  //\
    \ namespace emthrm\n\n#endif  // EMTHRM_MATH_EULER_PHI_EULER_PHI_HPP_\n"
  code: "/**\n * @brief \u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\n *\
    \ @docs docs/math/euler_phi/euler_phi.md\n */\n\n#ifndef EMTHRM_MATH_EULER_PHI_EULER_PHI_HPP_\n\
    #define EMTHRM_MATH_EULER_PHI_EULER_PHI_HPP_\n\n#include <cassert>\n\nnamespace\
    \ emthrm {\n\nlong long euler_phi(long long n) {\n  assert(n >= 1);\n  long long\
    \ res = n;\n  for (long long i = 2; i * i <= n; ++i) {\n    if (n % i == 0) {\n\
    \      res -= res / i;\n      while (n % i == 0) n /= i;\n    }\n  }\n  return\
    \ n > 1 ? res - res / n : res;\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_EULER_PHI_EULER_PHI_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/math/euler_phi/euler_phi.hpp
  requiredBy:
  - include/emthrm/math/is_primitive_root.hpp
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/is_primitive_root.test.cpp
  - test/math/euler_phi/euler_phi_init2.test.cpp
  - test/math/euler_phi/euler_phi_init.test.cpp
  - test/math/euler_phi/euler_phi.test.cpp
documentation_of: include/emthrm/math/euler_phi/euler_phi.hpp
layout: document
redirect_from:
- /library/include/emthrm/math/euler_phi/euler_phi.hpp
- /library/include/emthrm/math/euler_phi/euler_phi.hpp.html
title: "\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570"
---
# オイラーの $\varphi$ 関数 (Euler's totient function)

$n \in \mathbb{N}^+$ に対して

$$
  \varphi(n) \mathrel{:=} \# \lbrace k \in \lbrace 1, 2, \ldots, n \rbrace \mid k \perp n \rbrace
$$

と定義される $\varphi(n)$ である。素因数分解 $n = \prod_{i = 1}^k p_i^{e_i}$ に対して

$$
  \varphi(n) = n \prod_{i = 1}^k \left(1 - \frac{1}{p_i}\right)
$$

が成り立つ。


### オイラーの定理

$n \perp a$ を満たす $n, a \in \mathbb{N}^+$ に対して $a^{\varphi(n)} \equiv 1 \pmod{n}$ が成り立つ。


## 時間計算量

||時間計算量|
|:--|:--|
||$O(\sqrt{N})$|
|数表|$O(N\log{\log{N}})$|
|数表2|$O\left(\sqrt{H}\log{\log{H}} + \frac{(H - L)\sqrt{H}}{\log{H}}\right)$ ?|


## 仕様

|名前|戻り値|
|:--|:--|
|`long long euler_phi(long long n);`|$\varphi(n)$|

### 数表

|名前|戻り値|
|:--|:--|
|`std::vector<int> euler_phi_init(const int n);`|$\varphi(i)$ ($1 \leq i \leq n$) の数表|

### 数表2

|名前|戻り値|
|:--|:--|
|`std::vector<long long> euler_phi_init2(const long long low, const long long high);`|$\varphi(i)$ ($\mathrm{low} \leq i < \mathrm{high}$) の数表|


## 参考文献

- https://ei1333.github.io/algorithm/euler-phi.html

数表2
- https://github.com/spaghetti-source/algorithm/blob/87f5b3e4a3c10d8b85048f4fc4e4842ad11e9670/number_theory/euler_phi.cc


## TODO

- $\sum_{i = 1}^n \varphi(i)$ を $O(N^{\frac{2}{3}})$ で求める。
  - https://yukicoder.me/wiki/sum_totient
  - https://min-25.hatenablog.com/entry/2018/11/11/172216
  - https://judge.yosupo.jp/problem/sum_of_totient_function


## Submissons

- https://onlinejudge.u-aizu.ac.jp/solutions/problem/NTL_1_D/review/4088206/emthrm/C++14
- [数表](https://onlinejudge.u-aizu.ac.jp/solutions/problem/NTL_1_D/review/4088232/emthrm/C++14)
- [数表2](https://onlinejudge.u-aizu.ac.jp/solutions/problem/NTL_1_D/review/4088268/emthrm/C++14)
