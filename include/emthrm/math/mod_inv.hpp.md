---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/chinese_remainder_theorem.hpp
    title: "\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406 (Chinese remainder theorem)"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/simultaneous_linear_congruence.hpp
    title: "\u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F (simultaneous linear congruence)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/chinese_remainder_theorem.test.cpp
    title: "\u6570\u5B66/\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406"
  - icon: ':heavy_check_mark:'
    path: test/math/simultaneous_linear_congruence.test.cpp
    title: "\u6570\u5B66/\u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/math/mod_inv.hpp\"\n\n\n\n#if __cplusplus\
    \ >= 201703L\n#include <numeric>\n#else\n#include <algorithm>\n#endif\n#include\
    \ <utility>\n\nnamespace emthrm {\n\nlong long mod_inv(long long a, const int\
    \ m) {\n  if ((a %= m) < 0) a += m;\n#if __cplusplus >= 201703L\n  if (std::gcd(a,\
    \ m) != 1) return -1;\n#else\n  if (std::__gcd(a, static_cast<long long>(m)) !=\
    \ 1) return -1;\n#endif\n  long long x = 1;\n  for (long long b = m, u = 0; b\
    \ > 0;) {\n    const long long q = a / b;\n    std::swap(a -= q * b, b);\n   \
    \ std::swap(x -= q * u, u);\n  }\n  x %= m;\n  return x < 0 ? x + m : x;\n}\n\n\
    }  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_MATH_MOD_INV_HPP_\n#define EMTHRM_MATH_MOD_INV_HPP_\n\n#if\
    \ __cplusplus >= 201703L\n#include <numeric>\n#else\n#include <algorithm>\n#endif\n\
    #include <utility>\n\nnamespace emthrm {\n\nlong long mod_inv(long long a, const\
    \ int m) {\n  if ((a %= m) < 0) a += m;\n#if __cplusplus >= 201703L\n  if (std::gcd(a,\
    \ m) != 1) return -1;\n#else\n  if (std::__gcd(a, static_cast<long long>(m)) !=\
    \ 1) return -1;\n#endif\n  long long x = 1;\n  for (long long b = m, u = 0; b\
    \ > 0;) {\n    const long long q = a / b;\n    std::swap(a -= q * b, b);\n   \
    \ std::swap(x -= q * u, u);\n  }\n  x %= m;\n  return x < 0 ? x + m : x;\n}\n\n\
    }  // namespace emthrm\n\n#endif  // EMTHRM_MATH_MOD_INV_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/math/mod_inv.hpp
  requiredBy:
  - include/emthrm/math/simultaneous_linear_congruence.hpp
  - include/emthrm/math/chinese_remainder_theorem.hpp
  timestamp: '2023-01-20 03:45:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/chinese_remainder_theorem.test.cpp
  - test/math/simultaneous_linear_congruence.test.cpp
documentation_of: include/emthrm/math/mod_inv.hpp
layout: document
title: "\u9006\u5143 (inverse element)"
---

$ax \equiv 1 \pmod{m}$ を満たす $x = a^{-1}$ である。
- $a^{-1}$ が存在するとき $a \cdot a^{-1} + my = 1$ を満たす $y \in \mathbb{Z}$ が存在する。[拡張 Euclid の互除法](ext_gcd.md)を用い、時間計算量 $O(\log{M})$ で $(a^{-1}, y)$ を求められる。
- Fermat の小定理より、$m \in \mathbb{P}$ かつ $a \perp m$ を満たすとき $a^{-1} \equiv a^{m - 2} \pmod{m}$ が成り立つ。時間計算量 $O(\log{M})$ で求められる。
- [オイラーの定理](euler_phi/euler_phi.md###オイラーの定理)より、$a \perp m$ を満たすとき $a^{-1} \equiv a^{\varphi(m) - 1} \pmod{m}$ が成り立つ。時間計算量 $O(\sqrt{M})$ で求められる。


## 時間計算量

$O(\log{M})$


## 仕様

|名前|戻り値|
|:--|:--|
|`long long mod_inv(long long a, const int m);`|$a$ の逆元。ただし存在しないときは $-1$ を返す。|


## 参考文献

- https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a
- https://github.com/kirika-comp/articles/blob/c16612f266202ec6ce0f462601dd4db110add534/pre-seisuuron.pdf
