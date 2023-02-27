---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/euler_phi.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570 (Euler's totient\
      \ function)"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/mod_pow.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5 / \u4E8C\u5206\u7D2F\u4E57\u6CD5\
      \ / \u30D0\u30A4\u30CA\u30EA\u6CD5"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/prime_factorization.hpp
    title: "\u7D20\u56E0\u6570\u5206\u89E3 (prime factorization)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/is_primitive_root.test.cpp
    title: "\u6570\u5B66/\u539F\u59CB\u6839\u5224\u5B9A"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/math/is_primitive_root.hpp\"\n\n\n\n#include\
    \ <algorithm>\n#include <map>\n#include <numeric>\n#include <ranges>\n#include\
    \ <utility>\n#include <vector>\n\n#line 1 \"include/emthrm/math/euler_phi.hpp\"\
    \n\n\n\n#include <cassert>\n\nnamespace emthrm {\n\nlong long euler_phi(long long\
    \ n) {\n  assert(n >= 1);\n  long long res = n;\n  for (long long i = 2; i * i\
    \ <= n; ++i) {\n    if (n % i == 0) [[unlikely]] {\n      res -= res / i;\n  \
    \    while (n % i == 0) n /= i;\n    }\n  }\n  return n > 1 ? res - res / n :\
    \ res;\n}\n\n}  // namespace emthrm\n\n\n#line 1 \"include/emthrm/math/mod_pow.hpp\"\
    \n\n\n\nnamespace emthrm {\n\nlong long mod_pow(long long x, long long n, const\
    \ int m) {\n  if ((x %= m) < 0) x += m;\n  long long res = 1;\n  for (; n > 0;\
    \ n >>= 1) {\n    if (n & 1) res = (res * x) % m;\n    x = (x * x) % m;\n  }\n\
    \  return res;\n}\n\n}  // namespace emthrm\n\n\n#line 1 \"include/emthrm/math/prime_factorization.hpp\"\
    \n\n\n\n#line 6 \"include/emthrm/math/prime_factorization.hpp\"\n\nnamespace emthrm\
    \ {\n\ntemplate <typename T>\nstd::vector<std::pair<T, int>> prime_factorization(T\
    \ n) {\n  std::vector<std::pair<T, int>> res;\n  for (T i = 2; i * i <= n; ++i)\
    \ {\n    if (n % i == 0) [[unlikely]] {\n      int exponent = 0;\n      for (;\
    \ n % i == 0; n /= i) {\n        ++exponent;\n      }\n      res.emplace_back(i,\
    \ exponent);\n    }\n  }\n  if (n > 1) res.emplace_back(n, 1);\n  return res;\n\
    }\n\n}  // namespace emthrm\n\n\n#line 14 \"include/emthrm/math/is_primitive_root.hpp\"\
    \n\nnamespace emthrm {\n\nbool is_primitive_root(long long root, const int m)\
    \ {\n  if ((root %= m) < 0) root += m;\n  if (std::gcd(root, m) > 1) return false;\n\
    \  static std::map<int, int> phi;\n  if (!phi.contains(m)) phi[m] = euler_phi(m);\n\
    \  const int phi_m = phi[m];\n  static std::map<int, std::vector<int>> primes;\n\
    \  if (!primes.contains(phi_m)) {\n    // GCC 12 adopted P2415.\n    const std::vector<std::pair<int,\
    \ int>> pf = prime_factorization(phi_m);\n    const auto ev = pf | std::views::keys;\n\
    \    // const auto ev = prime_factorization(phi_m) | std::views::keys;\n    primes[phi_m]\
    \ = std::vector<int>(ev.begin(), ev.end());\n  }\n  return std::none_of(primes[phi_m].begin(),\
    \ primes[phi_m].end(),\n                      [root, phi_m, m](const int p) ->\
    \ bool {\n                        return mod_pow(root, phi_m / p, m) == 1;\n \
    \                     });\n}\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_MATH_IS_PRIMITIVE_ROOT_HPP_\n#define EMTHRM_MATH_IS_PRIMITIVE_ROOT_HPP_\n\
    \n#include <algorithm>\n#include <map>\n#include <numeric>\n#include <ranges>\n\
    #include <utility>\n#include <vector>\n\n#include \"emthrm/math/euler_phi.hpp\"\
    \n#include \"emthrm/math/mod_pow.hpp\"\n#include \"emthrm/math/prime_factorization.hpp\"\
    \n\nnamespace emthrm {\n\nbool is_primitive_root(long long root, const int m)\
    \ {\n  if ((root %= m) < 0) root += m;\n  if (std::gcd(root, m) > 1) return false;\n\
    \  static std::map<int, int> phi;\n  if (!phi.contains(m)) phi[m] = euler_phi(m);\n\
    \  const int phi_m = phi[m];\n  static std::map<int, std::vector<int>> primes;\n\
    \  if (!primes.contains(phi_m)) {\n    // GCC 12 adopted P2415.\n    const std::vector<std::pair<int,\
    \ int>> pf = prime_factorization(phi_m);\n    const auto ev = pf | std::views::keys;\n\
    \    // const auto ev = prime_factorization(phi_m) | std::views::keys;\n    primes[phi_m]\
    \ = std::vector<int>(ev.begin(), ev.end());\n  }\n  return std::none_of(primes[phi_m].begin(),\
    \ primes[phi_m].end(),\n                      [root, phi_m, m](const int p) ->\
    \ bool {\n                        return mod_pow(root, phi_m / p, m) == 1;\n \
    \                     });\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_IS_PRIMITIVE_ROOT_HPP_\n"
  dependsOn:
  - include/emthrm/math/euler_phi.hpp
  - include/emthrm/math/mod_pow.hpp
  - include/emthrm/math/prime_factorization.hpp
  isVerificationFile: false
  path: include/emthrm/math/is_primitive_root.hpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/is_primitive_root.test.cpp
documentation_of: include/emthrm/math/is_primitive_root.hpp
layout: document
title: "\u539F\u59CB\u6839 (primitive root) \u5224\u5B9A"
---

# 原始根 (primitive root)

$n \in \mathbb{N}^+,\ g \in \mathbb{Z}$ に対して $\mathrm{ord}_n(g) = \varphi(n)$ が成り立つとき、$g \bmod n$ を「$n$ を法とする原始根」と呼ぶ。

$n = 2, 4, p^k, 2p^k$ ($p \in \mathbb{P} \setminus \lbrace 2 \rbrace,\ k \in \mathbb{N}^+$) のときのみ $\varphi(\varphi(n))$ 個原始根が存在する。


### 位数 (multiplicative order)

$a \perp n$ を満たす $a \in \mathbb{Z},\ n \in \mathbb{N}^+$ に対して $a^k \equiv 1 \pmod{n}$ を満たす最小の $k \in \mathbb{N}^+$ である。


### 指数 (index)

$n$ を法とする原始根を $g$ とすると、任意の $a \in \mathbb{Z}$ に対して $g^e \equiv a \pmod{n}$ を満たす $0 \leq e < \varphi(n)$ がただ一つ存在する。この $e$ を「$g$ を底とする $a$ の指数」と呼び、$\mathrm{Ind}_g(a)$ と表す。


## 時間計算量

||時間計算量|
|:--|:--|
|原始根判定|$O(\sqrt{M})$|


## 仕様

### 原始根判定

|名前|戻り値|
|:--|:--|
|`bool is_primitive_root(long long root, const int m);`|$\mathrm{root}$ は $m$ を法とする原始根であるか。|


## 参考文献

- https://ja.wikipedia.org/wiki/%E6%8C%87%E6%95%B0_(%E5%88%9D%E7%AD%89%E6%95%B4%E6%95%B0%E8%AB%96)
- https://37zigen.com/primitive-root/

原始根判定
- https://lumakernel.github.io/ecasdqina/math/general
- https://hackmd.io/@qLethon/SJV41ERNL


## TODO

- 高速化
  - https://twitter.com/noshi91/status/1317022141599002624
- 原始根を求める。
  - https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp#L142
  - https://github.com/drken1215/algorithm/blob/master/MathNumberTheory/primitive_root.cpp
  - https://judge.yosupo.jp/problem/primitive_root
- 位数
  - https://github.com/beet-aizu/library/blob/e480647072b3a5cb2016e9137c024ccc043a897f/mod/order.cpp


## Submissons

- [原始根判定](https://yukicoder.me/submissions/624631)
